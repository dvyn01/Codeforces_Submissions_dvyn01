#include <bits/stdc++.h>
/*    #include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;       */
using namespace std;

#define ll long long
#define ull unsigned long long
#define f(a, b) for (ll i = a; i < b; i++)
#define mod 1000000007
#define pb push_back
#define vll vector<ll>
#define pll vector<pair<ll, ll>>
#define ld long double
#define fr(a, b) for (ll j = a; j >= b; j--)
#define fi(a, b) for (ll j = a; j < b; j++)
#define fii(a, b) for (ll k = a; k < b; k++)
//      typedef tree<ll
//      ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//      ordered_set;

template <class T> ostream &operator<<(ostream &os, vector<T> V) {
  os << "[ ";
  for (auto v : V)
    os << v << " ";
  os << "]";
  return os;
}
template <class T> ostream &operator<<(ostream &os, set<T> S) {
  os << "{ ";
  for (auto s : S)
    os << s << " ";
  return os << "}";
}
template <class L, class R> ostream &operator<<(ostream &os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}
template <class L, class R> ostream &operator<<(ostream &os, map<L, R> M) {
  os << "{ ";
  for (auto m : M)
    os << "(" << m.first << ":" << m.second << ") ";
  return os << "}";
}

const ll N = 500005;
ll a[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, m, p;
  cin >> n >> m >> p;
  string s, t;
  cin >> s;
  stack<ll> st;
  f(0, s.length()) {
    if (s[i] == '(')
      st.push(i + 1);
    else {
      ll k = st.top();
      st.pop();
      a[k] = i + 1;
      a[i + 1] = k;
    }
  }
  set<pair<ll, ll>> v;
  v.insert({1, n});
  cin >> t;
  f(0, t.length()) {
    if (t[i] == 'R') {
      auto it = v.upper_bound({p, 1e18});
      it--;
      if (p == it->second) {
        ++it;
        if (it == v.end())
          continue;
        p = it->first;
      } else {
        p++;
      }
    } else if (t[i] == 'L') {
      auto it = v.upper_bound({p, 1e18});
      it--;
      if (it->first == p) {
        if (it == v.begin())
          continue;
        it--;
        p = it->second;
      } else {
        p--;
      }
    } else {
      ll k1 = min(p, a[p]), k2 = max(p, a[p]);
      auto it = v.upper_bound({k1, 1e18});
      it--;
      if (it->second >= k2) {
        ll c = p;
        ll p1 = it->first, p2 = it->second;
        v.erase(it);
        if (p1 != k1)
          v.insert({p1, k1 - 1});
        if (p2 != k2)
          v.insert({k2 + 1, p2});
        auto it1 = v.lower_bound({c, -1});
        if (it1 != v.end())
          p = it1->first;
        else
          p = (--it1)->second;
      } else {
        ll c = p;
        auto it1 = it;
        ++it1;
        while (1) {
          if (it1->second >= k2)
            break;
          v.erase(it1);
          it = v.upper_bound({k1, 1e18});
          it--;
          it1 = it;
          ++it1;
        }
        ll p1 = it->first, p2 = it1->second;
        v.erase(it);
        v.erase(it1);
        if (p1 != k1)
          v.insert({p1, k1 - 1});
        if (p2 != k2)
          v.insert({k2 + 1, p2});
        it1 = v.lower_bound({c, -1});
        if (it1 != v.end())
          p = it1->first;
        else
          p = (--it1)->second;
      }
    }
  }
  for (auto it : v) {
    f(it.first, it.second + 1) cout << s[i - 1];
  }

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}
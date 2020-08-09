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
template <class L, class R> ostream &operator<<(ostream &os, map<L, R> M) {
  os << "{ ";
  for (auto m : M)
    os << "(" << m.first << ":" << m.second << ") ";
  return os << "}";
}
template <class L, class R> ostream &operator<<(ostream &os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}

const ll N = 1000005;

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, k = 0;
  cin >> n;
  string s, t;
  cin >> s >> t;
  f(0, n) if (s[i] == '0') k++;
  f(0, n) if (t[i] == '0') k--;
  if (k != 0) {
    cout << -1;
    return 0;
  }
  set<ll> s1, s2;
  f(0, n) {
    if (s[i] == '0' && t[i] == '1')
      s1.insert(i);
    else if (s[i] == '1' && t[i] == '0')
      s2.insert(i);
  }
  ll ans = 0;
  while (!(s1.empty() && s2.empty())) {
    ll last = 1, lt = *s1.begin(), sz = 1;
    if (*s1.begin() < *s2.begin())
      last = 1, lt = *s1.begin(), s1.erase(s1.begin());
    else
      last = 2, lt = *s2.begin(), s2.erase(s2.begin());
    while (1) {
      if (last == 1) {
        auto it = s2.upper_bound(lt);
        if (it == s2.end())
          break;
        last = 2;
        lt = *it;
        sz++;
        s2.erase(it);
      } else {
        auto it = s1.upper_bound(lt);
        if (it == s1.end())
          break;
        last = 1;
        lt = *it;
        sz++;
        s1.erase(it);
      }
    }
    if (sz & 1) {
      if (last == 1)
        s1.insert(lt);
      else
        s2.insert(lt);
    }
    ans++;
  }
  cout << ans;

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}
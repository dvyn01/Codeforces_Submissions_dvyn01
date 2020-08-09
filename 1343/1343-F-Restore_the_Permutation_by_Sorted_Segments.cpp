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

const ll N = 100005;
set<ll> s[201];
ll n;

vector<ll> pos(ll st) {
  set<ll> temp[n - 1];
  vll r;
  f(0, n - 1) for (auto it : s[i]) temp[i].insert(it);
  f(0, n - 1) {
    if (temp[i].find(st) != temp[i].end())
      temp[i].erase(temp[i].find(st));
  }
  r.pb(st);
  while (1) {
    ll one = 0, more = 0;
    f(0, n - 1) {
      if (temp[i].size() == 1)
        one++;
      else if (temp[i].size() > 1)
        more++;
    }
    if (one == 0 && more == 0)
      break;
    if (one != 1)
      return r;
    ll val;
    f(0, n - 1) if (temp[i].size() == 1) val = *temp[i].begin();
    f(0, n - 1) {
      if (temp[i].find(val) != temp[i].end())
        temp[i].erase(temp[i].find(val));
    }
    r.pb(val);
  }
  return r;
}

bool check(vll v) {
  map<set<ll>, ll> m;
  f(1, n) {
    set<ll> temp;
    temp.insert(v[i]);
    fr(i - 1, 0) {
      temp.insert(v[j]);
      m[temp] = 1;
    }
  }
  f(0, n - 1) {
    if (m.find(s[i]) == m.end())
      return false;
  }
  return true;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin >> t;
  while (t--) {
    cin >> n;
    f(0, n) s[i].clear();
    f(0, n - 1) {
      ll x, y;
      cin >> x;
      fi(0, x) cin >> y, s[i].insert(y);
    }
    vll v;
    f(1, n + 1) {
      v = pos(i);
      if (v.size() == n) {
        if (check(v))
          break;
      }
    }
    f(0, n) cout << v[i] << ' ';
    cout << '\n';
  }

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}
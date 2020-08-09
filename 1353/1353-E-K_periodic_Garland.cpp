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
vll v[N];

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
    ll n, k, tot = 0;
    cin >> n >> k;
    string s;
    cin >> s;
    f(0, k) v[i].clear();
    f(0, n) if (s[i] == '1') v[i % k].pb(i), tot++;
    ll ans = tot - 1;
    f(0, k) {
      if (v[i].size() <= 1)
        continue;
      ll temp[v[i].size() + 4];
      memset(temp, 0, sizeof(temp));
      fi(1, v[i].size()) {
        ll hona = (v[i][j] - v[i][0]) / k + 1;
        ll hai = j + 1;
        temp[j] = hona - hai;
        if (tot - v[i].size() + (v[i].size() - j - 1) + temp[j] < ans)
          ans = tot - v[i].size() + (v[i].size() - j - 1) + temp[j];
      }
      ll mn = 0;
      fi(1, v[i].size()) {
        ll hona = (v[i][j] - v[i][0]) / k + 1;
        ll hai = j + 1;
        ll profit = hona - hai - j;
        if (profit > mn)
          mn = profit;
        if (tot - v[i].size() + (v[i].size() - j - 1) + temp[j] - mn < ans)
          ans = tot - v[i].size() + (v[i].size() - j - 1) + temp[j] - mn;
      }
    }
    if (ans < 0)
      ans = 0;
    cout << ans << '\n';
  }

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}
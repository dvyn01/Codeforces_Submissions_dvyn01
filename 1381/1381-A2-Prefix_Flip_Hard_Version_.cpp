#include <bits/stdc++.h>
/** #include <ext/pb_ds/assoc_container.hpp>
 * #include <ext/pb_ds/tree_policy.hpp>
 * using namespace __gnu_pbds; */
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
/** typedef tree<ll
 * ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
 * ordered_set; */

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

const ll N = 100005;
string a, b;
ll n;

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
    cin >> n >> a >> b;
    vll ans, ans1;
    f(0, n - 1) {
      if (a[i] != a[i + 1])
        ans.pb(i + 1);
    }
    if (a[n - 1] == '1')
      ans.pb(n);
    f(0, n - 1) {
      if (b[i] != b[i + 1])
        ans1.pb(i + 1);
    }
    if (b[n - 1] == '1')
      ans1.pb(n);
    reverse(ans1.begin(), ans1.end());
    cout << ans.size() + ans1.size() << ' ';
    f(0, ans.size()) cout << ans[i] << ' ';
    f(0, ans1.size()) cout << ans1[i] << ' ';
    cout << '\n';
  }

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}
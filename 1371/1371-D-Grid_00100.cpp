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
/**      typedef tree<ll
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
    ll n, k;
    cin >> n >> k;
    ll a[2 * n][n];
    memset(a, 0, sizeof(a));
    ll cur = 1, r = 0, c = 0;
    while (k > 0) {
      k--;
      a[r][c] = 1;
      if (c == n - 1)
        r = cur, c = 0, cur++;
      else
        r++, c++;
    }
    f(0, 2 * n) fi(0, n) if (i >= n) a[i - n][j] |= a[i][j];
    ll mxR = 0, mnR = 1e18, mxC = 0, mnC = 1e18;
    f(0, n) {
      ll c = 0;
      fi(0, n) if (a[i][j] == 1) c++;
      mxR = max(mxR, c);
      mnR = min(mnR, c);
      c = 0;
      fi(0, n) if (a[j][i] == 1) c++;
      mxC = max(mxC, c);
      mnC = min(mnC, c);
    }
    ll ans = (mxR - mnR) * (mxR - mnR) + (mxC - mnC) * (mxC - mnC);
    cout << ans << '\n';
    f(0, n) {
      fi(0, n) cout << a[i][j];
      cout << '\n';
    }
  }

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}
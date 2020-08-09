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

const ll N = 505;

ll n, m, k, dp[N][N], mn[N][N];
string s[N];

ll rec(ll in, ll rem) {
  if (in > n)
    return 0;
  if (dp[in][rem] != -1)
    return dp[in][rem];
  ll k = 1e18;
  f(0, rem + 1) {
    if (mn[in][i] == 1e18)
      break;
    k = min(k, mn[in][i] + rec(in + 1, rem - i));
  }
  return dp[in][rem] = k;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(dp, -1, sizeof(dp));
  cin >> n >> m >> k;
  f(0, N) fi(0, N) mn[i][j] = 1e18;
  f(1, n + 1) {
    cin >> s[i];
    vll v;
    fi(0, m) if (s[i][j] == '1') v.pb(j);
    if (v.size() == 0)
      mn[i][0] = 0;
    else
      mn[i][0] = v.back() - v[0] + 1;
    mn[i][v.size()] = 0;
    if (v.size() <= 1)
      continue;
    fi(1, m + 1) {
      if (j == v.size() - 1) {
        mn[i][j] = 1;
        break;
      }
      ll c = 1e18;
      ll lp = 0, rp = v.size() - j - 1;
      while (rp < v.size()) {
        mn[i][j] = min(mn[i][j], v[rp] - v[lp] + 1);
        lp++;
        rp++;
      }
    }
  }
  cout << rec(1, k);

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}
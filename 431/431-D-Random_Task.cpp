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

const ll N = 100005;
ll m, k, C[65][65];

void pre() {
  f(0, 64) {
    fi(0, i + 1) {
      if (j == 0)
        C[i][j] = 1;
      else if (j == 1)
        C[i][j] = i;
      else
        C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
  }
}

ll ncr(ll n, ll r) {
  if (r > n)
    return 0;
  if (r == 0)
    return 1;
  return C[n][r];
}

ll find(ll n) {
  ll ans = 0;
  vll ones;
  ll x = n, c = 0;
  while (x) {
    if (x & 1)
      ones.pb(c);
    c++;
    x >>= 1;
  }
  reverse(ones.begin(), ones.end());
  f(0, ones.size()) {
    ans += ncr(ones[i], k - i);
    if (i == k - 1) {
      ans++;
      break;
    }
  }
  return ans;
}

ll check(ll mid) { return find(mid << 1) - find(mid); }

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  pre();
  cin >> m >> k;
  ll l = 1, r = 1e18;
  while (l <= r) {
    ll mid = l + r >> 1;
    ll c = check(mid);
    if (c == m) {
      cout << mid;
      return 0;
    }
    if (c < m)
      l = mid + 1;
    else
      r = mid - 1;
  }

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}
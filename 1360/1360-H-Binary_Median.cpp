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
ll n, m;

ll convert(string s) {
  ll n = 0;
  f(0, s.length()) if (s[i] == '1') n += (1LL << s.length() - i - 1);
  return n;
}

string back(ll n) {
  string s;
  while (n) {
    if (n & 1)
      s.pb('1');
    else
      s.pb('0');
    n >>= 1;
  }
  while (s.length() < m)
    s.pb('0');
  reverse(s.begin(), s.end());
  return s;
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
    cin >> n >> m;
    vll v;
    f(0, n) {
      string s;
      cin >> s;
      v.pb(convert(s));
    }
    ll ans = 0;
    sort(v.begin(), v.end());
    ll k = pow(2, m) - n;
    if (k & 1)
      k /= 2;
    else
      k = k / 2 - 1;
    ll l = 0, h = 2e18;
    while (l <= h) {
      ll mid = l + h >> 1;
      ll cl = mid;
      f(0, v.size()) {
        if (v[i] <= mid)
          cl--;
        else
          break;
      }
      if (cl >= k)
        ans = mid, h = mid - 1;
      else
        l = mid + 1;
    }
    cout << back(ans) << '\n';
  }

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}
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

bool check(string s1, string s2) {
  ll c = 0;
  f(0, s1.length()) if (s1[i] != s2[i]) c++;
  return c < 2;
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
    ll n, m;
    cin >> n >> m;
    string s[n];
    f(0, n) cin >> s[i];
    string ans;
    bool ok = false;
    f(0, n) {
      ok = true;
      fi(0, m) {
        fii(0, 26) {
          ok = true;
          ans = s[i];
          ans[j] = char('a' + k);
          for (ll l = 0; l < n; l++) {
            if (i == l)
              continue;
            if (!check(ans, s[l])) {
              ok = false;
              break;
            }
          }
          if (ok)
            break;
        }
        if (ok)
          break;
      }
      if (ok)
        break;
    }
    if(ok)
      cout << ans << '\n';
    else cout << -1 << '\n';
  }

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}
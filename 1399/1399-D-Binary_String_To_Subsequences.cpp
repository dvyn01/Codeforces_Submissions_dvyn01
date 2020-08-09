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
    ll n;
    string s;
    cin >> n >> s;
    set<ll> z, o;
    f(0, n) {
      if (s[i] == '0')
        z.insert(i);
      else
        o.insert(i);
    }
    bool done[n];
    ll ans[n];
    memset(ans, 0, sizeof(ans));
    memset(done, false, sizeof(done));
    ll p = 1;
    f(0, n) {
      if (done[i])
        continue;
      ll c = i, cc = s[i] - '0';
      while (1) {
        ans[c] = p;
        done[c] = true;
        if (cc == 0) {
          auto it = o.lower_bound(c);
          if (it == o.end())
            break;
          c = *it;
          o.erase(it);
          cc = 1;
        } else {
          auto it = z.lower_bound(c);
          if (it == z.end())
            break;
          c = *it;
          z.erase(it);
          cc = 0;
        }
      }
      p++;
    }
    cout << p - 1 << '\n';
    f(0, n) cout << ans[i] << ' ';
    cout << '\n';
  }

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}
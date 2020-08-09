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

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin >> t;
  string r = "abacaba";
  while (t--) {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    if (s.length() < 7) {
      cout << "No\n";
      continue;
    }
    ll c = 0;
    f(0, s.length() - 6) {
      if (s.substr(i, 7) == r)
        c++;
    }
    if (c > 1) {
      cout << "No\n";
      continue;
    }
    if (c == 1) {
      cout << "Yes\n";
      f(0, s.length()) if (s[i] == '?') s[i] = 'z';
      cout << s << '\n';
      continue;
    }
    bool mila = false;
    f(0, s.length() - 6) {
      string t = s;
      bool done = true;
      fi(i, i + 7) {
        if (t[j] == '?')
          t[j] = r[j - i];
        else if (t[j] != r[j - i]) {
          done = false;
          break;
        }
      }
      if (done) {
        mila = true;
        string t = s;
        fi(i, i + 7) s[j] = r[j - i];
        fi(0, s.length()) if (s[j] == '?') s[j] = 'z';
        ll c = 0;
        fi(0, s.length() - 6) {
          if (s.substr(j, 7) == r)
            c++;
        }
        if (c > 1) {
          s = t;
          mila = false;
          continue;
        } else if (c == 1) {
          break;
        }
      }
    }
    if (mila)
      cout << "Yes\n" << s << '\n';
    else
      cout << "No\n";
  }

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}
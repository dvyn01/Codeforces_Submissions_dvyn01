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

const ll N = 200005;
ll odd[10];

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
    memset(odd, 0, sizeof(odd));
    string s;
    cin >> s;
    bool done = false;
    string res = s;
    ll n = s.length();
    f(0, n - 1) odd[s[i] - '0'] ^= 1;
    fr(s.length() - 2, -1) {
      ll c = 0;
      f(0, 10) c += odd[i];
      if (c == 0) {
        f(j + 1, n) {
          if (s[i] != '0') {
            if (i == n - 1) {
              s[i] = '0';
              done = true;
              break;
            }
            s[i]--;
            done = true;
            s[n - 1] = s[i];
            fii(i + 1, n - 1) s[k] = '9';
            break;
          }
        }
        if (!done) {
          if (j != -1)
            odd[s[j] - '0'] ^= 1;
          continue;
        }
        string t;
        ll lp = 0, rp = n - 1;
        while (s[lp] == '0')
          lp++, rp--;
        f(lp, rp + 1) t.pb(s[i]);
        cout << t << '\n';
        break;
      }
      ll rem = n - j - 1;
      if ((rem < c) || ((rem & 1) != (c & 1))) {
        if (j != -1)
          odd[s[j] - '0'] ^= 1;
        continue;
      }
      vector<char> v;
      f(0, 10) {
        if (odd[i]) {
          v.pb('0' + i);
        }
      }
      sort(v.begin(), v.end());
      if (s[j + 1] > v[0]) {
        ll k = lower_bound(v.begin(), v.end(), s[j + 1]) - v.begin() - 1;
        vll v1;
        if (v[k] != s[j + 1] - 1 && v.size() < rem) {
          v.pb(s[j + 1] - 1);
          s[j + 1]--;
          f(0, v.size()) v1.pb(v[i]);
        } else {
          s[j + 1] = v[k];
          f(0, v.size()) if (i != k) v1.pb(v[i]);
        }
        while (v1.size() < rem - 1)
          v1.pb('9');
        sort(v1.begin(), v1.end());
        f(j + 2, n) s[i] = v1.back(), v1.pop_back();
        cout << s << '\n';
        done = true;
        break;
      } else {
        if (v.size() == rem || s[j + 1] == '0') {
          if (j != -1)
            odd[s[j] - '0'] ^= 1;
          continue;
        }
        v.pb(s[j + 1] - 1);
        s[j + 1]--;
        while (v.size() < rem - 1)
          v.pb('9');
        sort(v.begin(), v.end());
        f(j + 2, n) s[i] = v.back(), v.pop_back();
        cout << s << '\n';
        done = true;
        break;
      }
      if (j != -1)
        odd[s[j] - '0'] ^= 1;
    }
    if (!done) {
      f(0, s.length() - 2) cout << '9';
      cout << '\n';
    }
  }

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}
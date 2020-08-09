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

const ll N = 100005;
ll c[10];
string s, t;

bool pos(ll len) {
  ll b[10], k = len;
  f(0, 10) b[i] = c[i];
  while (k) {
    b[k % 10]--;
    k /= 10;
  }
  f(0, 10) if (b[i] < 0) return 0;
  bool more = false;
  ll sum = b[0];
  f(1, 10) {
    if (b[i] > 0)
      more = true;
    sum += b[i];
  }
  if ((!more && t[0] == '0') || sum + t.length() != len)
    return false;
  return true;
}

string get(ll len) {
  ll b[10], k = len;
  f(0, 10) b[i] = c[i];
  while (k > 0) {
    b[k % 10]--;
    k /= 10;
  }
  string ans;
  ll first = -1;
  f(1, 10) {
    if (b[i] > 0) {
      first = i;
      break;
    }
  }
  bool done = false;
  if (first == -1) {
    ans = t;
    done = true;
    while (b[0] > 0)
      ans.pb('0'), b[0]--;
  } else {
    if (t[0] != '0' && t[0] < ('0' + first)) {
      ans = t;
      done = true;
      f(0, 10) while (b[i] > 0) ans.pb('0' + i), b[i]--;
    } else {
      if (t[0] == '0' + first) {
        string s1, s2, s3; // T, 0, F; F, 0, T, F; F, 0, F, T
        s1 = t;
        s2.pb('0' + first);
        s3.pb('0' + first);
        while (b[0] > 0)
          s1.pb('0'), s2.pb('0'), s3.pb('0'), b[0]--;
        s2 += t;
        s1.pb('0' + first);
        b[first]--;
        while (b[first] > 0)
          s1.pb('0' + first), s2.pb('0' + first), s3.pb('0' + first),
              b[first]--;
        s3 += t;
        ans = min(s1, min(s2, s3));
        done = true;
      } else {
        ans.pb('0' + first);
        b[first]--;
        while (b[0] > 0)
          ans.pb('0'), b[0]--;
      }
      f(1, 10) {
        if (b[i] > 0) {
          if (i < (t[0] - '0')) {
            while (b[i] != 0)
              ans.pb('0' + i), b[i]--;
          } else if (i == (t[0] - '0') && !done) {
            string s1;
            while (b[i] != 0)
              s1.pb('0' + i), b[i]--;
            string s2 = t + s1;
            s1 += t;
            if (s1 < s2)
              fi(0, s1.length()) ans.pb(s1[j]);
            else
              fi(0, s2.length()) ans.pb(s2[j]);
            done = true;
          } else {
            if (!done) {
              fi(0, t.length()) ans.pb(t[j]);
              done = true;
            }
            while (b[i] > 0)
              ans.pb('0' + i), b[i]--;
          }
        }
      }
    }
  }
  if (!done)
    fi(0, t.length()) ans.pb(t[j]);
  return ans;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> s >> t;
  if ((s == "01" || s == "10") && t == "0") {
    cout << 0;
    return 0;
  }
  f(0, s.length()) c[s[i] - '0']++;
  f(0, t.length()) c[t[i] - '0']--;
  string ans;
  f(0, s.length()) {
    ll len = i + t.length();
    if (pos(len)) {
      string p = get(len);
      if (ans.length() == 0 || (p.size() < ans.size()) ||
          (p.size() == ans.size() && p < ans))
        ans = p;
    }
  }
  cout << ans;

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}
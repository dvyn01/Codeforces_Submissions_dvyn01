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

// https://github.com/Ashishgup1/Competitive-Coding/blob/master/Hashing%20(Strings).cpp

struct Hashs {
  vector<int> hashs;
  vector<int> pows;
  int P;
  int MOD;

  Hashs() {}

  Hashs(string &s, int P, int MOD) : P(P), MOD(MOD) {
    int n = s.size();
    pows.resize(n + 1, 0);
    hashs.resize(n + 1, 0);
    pows[0] = 1;
    for (int i = n - 1; i >= 0; i--) {
      hashs[i] = (1LL * hashs[i + 1] * P + s[i] - 'a' + 1) % MOD;
      pows[n - i] = (1LL * pows[n - i - 1] * P) % MOD;
    }
    pows[n] = (1LL * pows[n - 1] * P) % MOD;
  }
  int get_hash(int l, int r) {
    int ans = hashs[l] + MOD - (1LL * hashs[r + 1] * pows[r - l + 1]) % MOD;
    ans %= MOD;
    return ans;
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;
  Hashs S(s, 31, mod);
  ll l = 0, r = s.length() - 1, ans = 0;
  while (l < r) {
    ll len = r - l + 1;
    if (len & 1) {
      ll mid = (l + r) / 2;
      if (S.get_hash(l, mid - 1) != S.get_hash(mid + 1, r)) {
        ans = 2;
        break;
      }
      r = mid - 1;
    } else {
      ll mid = (l + r) / 2;
      if (S.get_hash(l, mid) != S.get_hash(mid + 1, r)) {
        ans = 1;
        break;
      }
      r = mid;
    }
  }
  if (ans == 0) {
    map<char, ll> m;
    f(0, s.length()) m[s[i]]++;
    if (m.size() == 2) {
      if (!(m.begin()->second == 1 || ((++m.begin())->second == 1)))
        ans = 2;
    } else if (m.size() > 2) {
      ans = 2;
    }
  }
  if (ans == 0)
    cout << "Impossible";
  else
    cout << ans;

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}
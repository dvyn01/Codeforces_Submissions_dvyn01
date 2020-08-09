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

  ll n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<vector<ll>> ans;
  string r = s;
  ll mx = 0;
  while (1) {
    bool done = false;
    vll v;
    f(0, n - 1) {
      if (r[i] == 'R' && r[i + 1] == 'L')
        swap(r[i], r[i + 1]), v.pb(i + 1), i++, done = true;
    }
    if (!done)
      break;
    ans.pb(v);
    mx++;
  }
  if (mx > k) {
    cout << -1;
    return 0;
  }
  vector<vector<ll>> ans1;
  while (ans.size() + ans1.size() < k) {
    if (ans.empty()) {
      cout << -1;
      return 0;
    }
    vll v;
    v.pb(ans[ans.size() - 1].back());
    ans[ans.size() - 1].pop_back();
    if (ans[ans.size() - 1].size() == 0)
      ans.pop_back();
    ans1.pb(v);
  }
  f(0, ans.size()) {
    cout << ans[i].size() << ' ';
    fi(0, ans[i].size()) cout << ans[i][j] << ' ';
    cout << '\n';
  }
  fr((int)ans1.size() - 1, 0) {
    cout << ans1[j].size() << ' ';
    f(0, ans1[j].size()) cout << ans1[j][i] << ' ';
    cout << '\n';
  }

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}
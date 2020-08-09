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

const ll N = 1005;
string s[N];
ll n, m;
bool vis[N][N];
map<ll, ll> mr, mc;

bool safe(ll i, ll j) {
  return i >= 0 && i < n && j >= 0 && j < m && s[i][j] == '#';
}

void dfs(ll i, ll j) {
  if (vis[i][j])
    return;
  mr[i]++;
  mc[j]++;
  vis[i][j] = true;
  if (safe(i + 1, j) && !vis[i + 1][j])
    dfs(i + 1, j);
  if (safe(i - 1, j) && !vis[i - 1][j])
    dfs(i - 1, j);
  if (safe(i, j + 1) && !vis[i][j + 1])
    dfs(i, j + 1);
  if (safe(i, j - 1) && !vis[i][j - 1])
    dfs(i, j - 1);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  f(0, n) cin >> s[i];
  bool z = true;
  f(0, n) {
    ll c = 0;
    fi(0, m) {
      if (s[i][j] == '#') {
        c++;
        ll k = j;
        while (k < m && s[i][k] == '#')
          k++;
        j = k - 1;
      }
    }
    if (c > 0)
      z = false;
    if (c > 1) {
      cout << -1;
      return 0;
    }
  }
  fi(0, m) {
    ll c = 0;
    f(0, n) {
      if (s[i][j] == '#') {
        c++;
        ll k = i;
        while (k < n && s[k][j] == '#')
          k++;
        i = k - 1;
      }
    }
    if (c > 0)
      z = false;
    if (c > 1) {
      cout << -1;
      return 0;
    }
  }
  if (z) {
    cout << 0;
    return 0;
  }
  ll ans = 0;
  f(0, n) {
    fi(0, m) {
      if (!vis[i][j] && s[i][j] == '#')
        dfs(i, j), ans++;
    }
  }
  if ((mr.size() == n && mc.size() != m) ||
      (mr.size() != n && mc.size() == m)) {
    cout << -1;
    return 0;
  }
  cout << ans << '\n';

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}
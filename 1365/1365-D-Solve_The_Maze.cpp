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

const ll N = 55;
string s[N];
ll n, m;
bool vis[N][N];

bool safe(ll i, ll j) { return i >= 0 && i < n && j >= 0 && j < m; }

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
    memset(vis, false, sizeof(vis));
    f(0, n) cin >> s[i];
    bool ok = true;
    ll g = 0, b = 0;
    f(0, n) {
      fi(0, m) {
        if (s[i][j] == 'B') {
          b++;
          if (safe(i - 1, j) && s[i - 1][j] == 'G')
            ok = false;
          if (safe(i + 1, j) && s[i + 1][j] == 'G')
            ok = false;
          if (safe(i, j - 1) && s[i][j - 1] == 'G')
            ok = false;
          if (safe(i, j + 1) && s[i][j + 1] == 'G')
            ok = false;
          if (!ok)
            break;
        } else if (s[i][j] == 'G') {
          g++;
        }
      }
    }
    if (!ok || s[n - 1][m - 1] == 'B') {
      cout << "No\n";
      continue;
    }
    if (g == 0) {
      cout << "Yes\n";
      continue;
    }
    f(0, n) {
      fi(0, m) {
        if (s[i][j] == 'B') {
          if (safe(i - 1, j) && s[i - 1][j] == '.')
            s[i - 1][j] = '#';
          if (safe(i + 1, j) && s[i + 1][j] == '.')
            s[i + 1][j] = '#';
          if (safe(i, j - 1) && s[i][j - 1] == '.')
            s[i][j - 1] = '#';
          if (safe(i, j + 1) && s[i][j + 1] == '.')
            s[i][j + 1] = '#';
        }
      }
    }
    if (s[n - 1][m - 1] == '#' && g > 0) {
      cout << "No\n";
      continue;
    }
    queue<pair<ll, ll>> q;
    ll c = 0;
    vis[n - 1][m - 1] = true;
    q.push({n - 1, m - 1});
    while (!q.empty()) {
      ll i = q.front().first, j = q.front().second;
      if (s[i][j] == 'G')
        c++;
      q.pop();
      if (safe(i - 1, j) && !vis[i - 1][j] && s[i - 1][j] != 'B' &&
          s[i - 1][j] != '#')
        vis[i - 1][j] = true, q.push({i - 1, j});
      if (safe(i + 1, j) && !vis[i + 1][j] && s[i + 1][j] != 'B' &&
          s[i + 1][j] != '#')
        vis[i + 1][j] = true, q.push({i + 1, j});
      if (safe(i, j - 1) && !vis[i][j - 1] && s[i][j - 1] != 'B' &&
          s[i][j - 1] != '#')
        vis[i][j - 1] = true, q.push({i, j - 1});
      if (safe(i, j + 1) && !vis[i][j + 1] && s[i][j + 1] != 'B' &&
          s[i][j + 1] != '#')
        vis[i][j + 1] = true, q.push({i, j + 1});
    }
    if (c == g)
      cout << "Yes\n";
    else
      cout << "No\n";
  }

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}
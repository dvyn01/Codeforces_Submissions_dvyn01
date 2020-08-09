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

const ll N = 200005;
ll a[N], ans1[N], ans2[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin >> n;
  f(0, n + 1) cin >> a[i];
  queue<ll> q;
  q.push(1);
  ll c = 2;
  bool done = false;
  f(1, n + 1) {
    queue<ll> cur;
    if (done) {
      while (a[i] > 0) {
        ans1[c] = q.front();
        ans2[c] = q.front();
        cur.push(c);
        c++;
        a[i]--;
      }
      while (!q.empty())
        q.pop();
      while (!cur.empty())
        q.push(cur.front()), cur.pop();
      continue;
    }
    if (q.size() > 1 && a[i] > 1)
      done = true;
    if (done) {
      ll x1 = q.front();
      q.pop();
      ll x2 = q.front();
      q.pop();
      while (!q.empty())
        q.pop();
      a[i]--;
      ans1[c] = x1;
      ans2[c] = x1;
      cur.push(c);
      c++;
      while (a[i] > 0)
        ans1[c] = x1, ans2[c] = x2, cur.push(c), c++, a[i]--;
      while (!cur.empty())
        q.push(cur.front()), cur.pop();
      continue;
    }
    ll x = q.front();
    while (!q.empty())
      q.pop();
    while (a[i] > 0)
      a[i]--, ans1[c] = x, ans2[c] = x, q.push(c), c++;
  }
  if (!done)
    cout << "perfect";
  else {
    cout << "ambiguous\n";
    f(1, c) cout << ans1[i] << ' ';
    cout << '\n';
    f(1, c) cout << ans2[i] << ' ';
  }

#ifndef ONLINE_JUDGE
  cout << "\nTime Elapsed : " << 1000 * (ld)clock() / (ld)CLOCKS_PER_SEC
       << " ms\n";
#endif
  return 0;
}
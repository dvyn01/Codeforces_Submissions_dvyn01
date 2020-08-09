#include<bits/stdc++.h>
/*    #include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;       */
using namespace std;

#define ll long long
#define ull unsigned long long
#define f(a,b) for(ll i=a; i<b; i++)
#define mod 1000000007
#define pb push_back
#define vll vector<ll>
#define pll vector<pair<ll,ll>>
#define ld long double
#define fr(a,b) for(ll j=a; j>=b; j--)
#define fi(a,b) for(ll j=a; j<b; j++)
#define fii(a,b) for(ll k=a; k<b; k++)
//      typedef tree<ll ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
	os << "[ ";
	for (auto v : V) os << v << " ";
	os << "]";
	return os;
}
template<class T> ostream& operator<<(ostream &os, set<T> S) {
	os << "{ ";
	for (auto s : S) os << s << " ";
	return os << "}";
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) {
	return os << "(" << P.first << "," << P.second << ")";
}
template<class L, class R> ostream& operator<<(ostream &os, map<L, R> M) {
	os << "{ ";
	for (auto m : M) os << "(" << m.first << ":" << m.second << ") ";
	return os << "}";
}

inline ll mul(ll x, ll y, ll m)	{	ll z = 1LL * x * y;		if (z >= m)	z %= m;		return z;	}
inline ll add(ll x, ll y, ll m)	{	ll z = x + y;			if (z >= m)	z %= m;		return z;	}
inline ll sub(ll x, ll y, ll m)	{	ll z = x - y;			if (z < 0)	z += m;		z %= m;		return z;	}

vll adj[10005];
set<pair<ll, ll>> s;

void dfs(ll x, ll pr) {
	s.insert({adj[x].size(), x});
	f(0, adj[x].size()) if (adj[x][i] != pr) dfs(adj[x][i], x);
}

bool check(ll x, ll pr, ll k) {
	bool ret = false;
	if (x == k)
		ret = true;
	f(0, adj[x].size()) if (adj[x][i] != pr) ret |= check(adj[x][i], x, k);
	return ret;
}

void remove(ll x, ll pr) {
	f(0, adj[x].size()) if (adj[x][i] != pr) remove(adj[x][i], x);
	s.erase(s.find({adj[x].size(), x}));
}


void detach(ll r, ll k) {
	f(0, adj[r].size()) {
		if (check(adj[r][i], r, k)) {
			remove(adj[r][i], r);
			s.erase(s.find({adj[r].size(), r}));
			adj[r].erase(adj[r].begin() + i);
			s.insert({adj[r].size(), r});
			break;
		}
	}
}

bool ask() {
	if (s.begin()->first <= 0) {
		cout << "! " << s.begin() -> second << endl;
		return true;
	}
	auto it = s.begin();
	ll k1 = it -> second;
	it++;
	ll k2 = it -> second;
	cout << "? " << k1 << " " << k2 << endl;
	ll r;
	cin >> r;
	if (r != k1)
		detach(r, k1);
	if (r != k2)
		detach(r, k2);
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, r, x, y;
	cin >> n;
	f(0, n - 1) cin >> x >> y, adj[x].pb(y), adj[y].pb(x);
	dfs(1, -1);
	bool done = false;
	while (!done) {
		done = ask();
	}

	return 0;
}

/*
          * AUTHOR : Divyanshu *
*/

// p_q again !!!

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define ull unsigned long long
#define f(a,b) for(ll i=a; i<b; i++)
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define pl pair<ll,ll>
#define vll vector<ll>
#define pll vector<pair<ll,ll>>
#define ld long double
#define fr(a,b) for(ll j=a; j>=b; j--)
#define fi(a,b) for(ll j=a; j<b; j++)
#define fii(a,b) for(ll k=a; k<b; k++)
typedef tree<ll ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
ll n, m;

bool safe(ll x, ll y)
{
    if(x >=0 && x <n && y >= 0 && y < m)
        return true;
    return false;
}

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	// freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll r, c, x, y;
    cin>>n>>m>>r>>c>>x>>y;
    r--;    c--;
    string s[n];
    f(0, n) cin>>s[i];
    ll dx[] = {0, 0, 1, -1},      dy[] = {1, -1, 0, 0};
    priority_queue<pair< pair<ll, ll>, pair<ll, ll>> > pq;
    pq.push(mp(mp(x, y), mp(r, c)));
    ll ans = 0;
    bool b[n][m];       memset(b, false, sizeof(b));
    b[r][c] = true;
    while(!pq.empty())
    {
        ans++;
        ll X = pq.top().first.first,    Y = pq.top().first.second;
        ll R = pq.top().second.first,   C = pq.top().second.second;
    //    cout<<X<<" "<<Y<<" "<<R<<" "<<C<<"\n";
        pq.pop();
        f(0, 4)
        {
            ll nr, nc;
            nr = R + dx[i], nc = C + dy[i];
            ll k1 = X,  k2 = Y;
            if(dy[i] == 1)
                k2--;
            if(dy[i] == -1)
                k1--;
            if(!safe(nr, nc) || k1 < 0 || k2 < 0)
                continue;
            if(s[nr][nc] == '*')
                continue;
            if(b[nr][nc])
                continue;
            b[nr][nc] = true;
            pq.push(mp(mp(k1, k2), mp(nr, nc)));
        }
    }
    cout<<ans;

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}
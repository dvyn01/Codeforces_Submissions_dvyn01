//          * AUTHOR : Divyanshu *

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define f(a,b) for(ll i=a; i<b; i++)
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define vll vector<ll>
#define pll vector<pair<ll,ll>>
#define ld long double
#define fr(a,b) for(ll j=a; j>=b; j--)
#define fi(a,b) for(ll j=a; j<b; j++)
#define fii(a,b) for(ll k=a; k<b; k++)

struct point{
    ll x, y;
};

ll orientation(point p, point q, point r)
{
    ll val = (q.y-p.y) * (r.x-q.x) - (q.x-p.x) * (r.y-q.y);
    if(val == 0)    return 0;
    else if(val > 0)    return 1;
    else return -1;
}

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	// freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    point p[3];
    f(0, 3){ll x,y;     cin>>x>>y;  p[i].x=x; p[i].y=y;}
    ll v = orientation(p[0], p[1], p[2]);
    if(v == 0)  cout<<"TOWARDS";
    else if(v==1)   cout<<"RIGHT";
    else cout<<"LEFT";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}


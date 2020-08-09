/*
          * AUTHOR : Divyanshu *
*/

#include<bits/stdc++.h>
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

ld area(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
    return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

bool check(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4, ll x, ll y)
{
    ld ar = area(x1, y1, x2, y2, x3, y3) + area(x1, y1, x4, y4, x3, y3);
    ld a = area(x, y, x1, y1, x2, y2);
    ld b = area(x, y, x2, y2, x3, y3);
    ld c = area(x, y, x3, y3, x4, y4);
    ld d = area(x, y, x1, y1, x4, y4);
    return (ar == a+b+c+d);
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

    ll n, d;
    cin>>n>>d;
    ll m;
    cin>>m;
    while(m--)
    {
        ll x, y;
        cin>>x>>y;
        if(check(0, d, d, 0, n, n-d, n-d, n, x, y))
            cout<<"YES\n";
        else cout<<"NO\n";
    }

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}


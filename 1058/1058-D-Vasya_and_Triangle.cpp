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
ld x, y;
ld n, m, k;

bool fun(ll a)
{
    ll r = a / x;
    for(ll i=r; i<=y; i++)
    {
        if(i == 0)
            continue;
        if(a % i == 0)
        {
            ll p = a/i;
            if(max(i, p) <= x && min(i, p) <= y)
            {
                cout<<"YES\n";
                if(n < m)
                {
                    cout<<"0 0\n";
                    cout<<"0 "<<max(i, p)<<"\n";
                    cout<<min(i, p)<<" 0\n";
                }
                else
                {
                    cout<<"0 0\n";
                    cout<<"0 "<<min(i, p)<<"\n";
                    cout<<max(i, p)<<" 0\n";
                }
                return true;
            }
        }
    }
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
    cout.tie(0);

    cin>>n>>m>>k;
    ld a = 2.0*n*m / k;
    ll ar = a;
    if(a != ar)
    {
        cout<<"NO";
        return 0;
    }
    x = max(n, m), y = min(n, m);
    if(!fun(ar))
        cout<<"NO";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}


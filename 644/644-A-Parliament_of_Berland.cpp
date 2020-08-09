//          * AUTHOR : Divyanshu *

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define f(a,b) for(ll i=a; i<b; i++)
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define vll vector<ll>
#define pll vector<pair<ll,ll>>
#define ld long double

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	// freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll n, x, y;
    cin>>n>>x>>y;
    ll a[x+1][y+1] = {0};
    ll ec, oc;
    if(n%2==0){
        ec = n; oc = n-1;
    }
    else {ec = n-1; oc = n; }
    f(1,x+1)
    {
        for(ll j=1; j<=y; j++)
        {
            if(i%2 == j%2)
            {
                if(oc>0)
                {
                    a[i][j] = oc;
                    oc -= 2;
                }
            }
            else
            {
                if(ec>0)
                {
                    a[i][j] = ec;
                    ec -= 2;
                }
            }
        }
    }
    if(oc>0 || ec>0)
        cout<<"-1";
    else{
        f(1, x+1)
        {
            for(ll j=1; j<=y; j++)
                cout<<a[i][j]<<" ";
            cout<<"\n";
        }
    }

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}


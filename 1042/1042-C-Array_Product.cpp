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

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	// freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll n;
    cin>>n;
    vll z;
    vll p;
    ll a[n], nc=0, ni=0, ne = -1e18;
    bool b[n];
    memset(b, false, sizeof(b));
    f(0, n)
    {
        cin>>a[i];
        if(a[i] == 0)  {z.pb(i); b[i] = true; }
        else if(a[i] < 0)
        {
            nc++;
            if(a[i] > ne)
            {
                ne = a[i];
                ni = i;
            }
        }
    }
    if((nc&1) && z.size())
    {
        f(1, z.size())
            cout<<1<<" "<<z[i-1]+1<<" "<<z[i]+1<<"\n";
        cout<<1<<" "<<ni+1<<" "<<z[z.size()-1]+1<<"\n";
        b[ni] = true;
        if(z.size() + 1 == n)
            return 0;
        cout<<2<<" "<<z[z.size()-1] + 1<<"\n";
        f(0, n)
            if(!b[i])   p.pb(i+1);
        f(1, p.size())
            cout<<1<<" "<<p[i-1]<<" "<<p[i]<<"\n";
    }
    else if(!(nc&1))
    {
        if(z.size() != 0)
        {
            f(1, z.size())
                cout<<1<<" "<<z[i-1]+1<<" "<<z[i]+1<<"\n";
            if(z.size() == n)
                return 0;
            cout<<2<<" "<<z[z.size()-1] + 1<<"\n";
        }
        f(0, n)
            if(!b[i])   p.pb(i+1);
        f(1, p.size())
            cout<<1<<" "<<p[i-1]<<" "<<p[i]<<"\n";
    }
    else
    {
        cout<<2<<" "<<ni+1<<"\n";
        b[ni] = true;
        f(0, n)
            if(!b[i])   p.pb(i+1);
        f(1, p.size())
            cout<<1<<" "<<p[i-1]<<" "<<p[i]<<"\n";
    }

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}


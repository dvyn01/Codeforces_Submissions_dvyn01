//          * AUTHOR : Divyanshu *

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define f(a,b) for(ll i=a; i<b; i++)
#define mod 1000000007

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	//freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll n,m,ans=0;
    cin>>n>>m;
    bool b[m] = {false};
    ll a[n][m];
    f(0, n)
    {
        string z;
        cin>>z;
        for(ll j=0; j<m; j++)
        {
            if(z[j] == '1')
                a[i][j] = 1;
            else a[i][j] = 0;
        }
    }
    vector<ll> c;
    f(0,m)
    {
        ll p=0;
        for(ll j=0; j<n;j++)
        {
            if(a[j][i] == 1)
                p++;
        }
        if(p>1)
            c.push_back(i);
    }
    ll d[m];
    f(0,m)
    {
        if(binary_search(c.begin(), c.end(), i))
            d[i] = 1;
        else d[i] = 0;
    }
    //f(0,m) cout<<d[i]<<" ";
    f(0,n)
    {
        ll p=0;
        for(ll j=0; j<m; j++)
        {
            if(d[j]==0 && a[i][j]==0)
                continue;
            if(d[j]==0 && a[i][j]==1)
                p++;
        }
      //  cout<<i<<"*"<<p<<" ";
        if(p==0)
        {
            ans=1;
            break;
        }
    }
    if(ans==1)
        cout<<"YES";
    else cout<<"NO";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}


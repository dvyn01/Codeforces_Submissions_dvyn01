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


int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	//freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll n, c=0, p=0, m=0;
    cin>>n;
    vll v[n+1];
    f(0, n-1){
        ll a, b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    f(1, n+1)
    {
        if(v[i].size() > 2)
            {
                c++;
                p = i;
            }
        if(v[i].size()==1)
            m++;
    }
    if(c > 1)
    {
        cout<<"No\n";
            return 0;
    }
    if(p==0)
    {
        cout<<"Yes\n1\n";
        f(1, n+1)
        {
            if(v[i].size()==1)
                cout<<i<<" ";
        }
    }
    else{
        cout<<"Yes\n"<<m<<"\n";
        f(1, n+1)
        {
            if(v[i].size()==1)
            {
                cout<<p<<" "<<i<<"\n";
            }
        }
    }

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}


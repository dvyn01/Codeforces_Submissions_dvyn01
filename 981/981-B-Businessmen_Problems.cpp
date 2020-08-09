//          * AUTHOR : Divyanshu *

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define f(a,b) for(ll i=a; i<b; i++)
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define vll vector<ll>;
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

    ll m,n,p,q,s=0;
    map<ll,ll> a,b;
    map<ll,ll> :: iterator it;
    cin>>n;
    f(0,n)
    {
        cin>>p>>q;
        a[p] = q;
    }
    cin>>m;
    f(0,m)
    {
        cin>>p>>q;
        b[p] = q;
    }
    for(it = a.begin(); it!=a.end(); it++)
    {
        if(b.find(it->first) == b.end())
            s += it->second;
        else
            s += max(b[it->first], it->second);
    }
 //   cout<<s<<" ";
    for(it = b.begin(); it!=b.end(); it++)
    {
         if(a.find(it->first) == a.end())
            s += it->second;
         else continue;
    }
    cout<<s<<"\n";


     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

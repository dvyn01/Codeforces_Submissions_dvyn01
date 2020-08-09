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

    map<ld, ld> m;
    ll n, s;
    cin>>n>>s;
    f(0,n)
    {
        ld x, y, p;
        cin>>x>>y>>p;
        ld d = sqrt(x*x+y*y);
        m[d] += p;
    }
    map<ld, ld> :: iterator it;
    for(it=m.begin(); it!=m.end(); it++)
    {
        s += it->second;
        if(s >= 1000000)
        {
            cout<<std::fixed<<setprecision(7)<<it->first;
            return 0;
        }
    }
    if(s<1000000)
        cout<<"-1";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}


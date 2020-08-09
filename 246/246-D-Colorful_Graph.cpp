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

    ll n, m;
    cin>>n>>m;
    ll c[n+1];
    bool b[100005] = {false};
    f(1, n+1) { cin>>c[i]; b[c[i]] = true; }
    set<int> s[100005];
    f(0,m)
    {
        ll a, b;
        cin>>a>>b;
        if(c[a]!=c[b]){
        s[c[a]].insert(c[b]);
        s[c[b]].insert(c[a]);
      //  cout<<a<<" "<<b<<"\n";
        }
    }
    ll mx=-1e18, x=0;
   // set<ll>:: iterator it;
   // it = s[1].begin();
    f(1, 100005)
    {
        if(s[i].size() > mx && b[i])
        {
            x = i;
            mx = s[i].size();
        }
    }
    cout<<x;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}


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
    ll a[n+1], b[n+1]={0};
    f(1, n+1) cin>>a[i];
    stack<ll> s;
    bool vis[n+1];
    f(1, n+1)
    {
        if(!b[i])
        {
            while(!s.empty())
                s.pop();
            memset(vis, false, sizeof(vis));
            s.push(i);
            while(!vis[s.top()])
            {
                vis[s.top()] = true;
              //  cout<<s.top()<<"--->>>"<<a[s.top()]<<"\n";
                s.push(a[s.top()]);
               // cout<<a[s.top()]<<"==  ";
            }
            ll k = s.top();
            s.pop();
            b[i] = k;
            while(!s.empty() && s.top()!=k){b[s.top()]=s.top(); s.pop(); }
        }
    }
    f(1, n+1)   cout<<b[i]<<" ";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}


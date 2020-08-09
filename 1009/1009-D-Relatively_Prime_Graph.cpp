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
#define fr(a,b) for(ll j=a; j>=b; j--)
#define fi(a,b) for(ll j=a; j<b; j++)

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
    pll p;
    f(2, n+1)
        { p.pb(mp(1,i)); m--; }
    if(m>0)
    {
        f(2, n)
        {
            fi(i+1, n+1)
            {
                if(__gcd(i, j) == 1)
                {
                    p.pb(mp(i, j));
                    m--;
                }
                if(m==0) break;
            }
            if(m==0) break;
        }
    }
    if(m==0){
        cout<<"Possible\n";
        f(0, p.size()) cout<<p[i].first<<" "<<p[i].second<<"\n";
    }
    else cout<<"Impossible";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}


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

    ll k, c=1;
    cin>>k;
    map<ll, pair<ll,ll>> m;
    while(k--)
    {
        ll n, s=0;
        cin>>n;
        ll a[n];
        f(0,n) {
            cin>>a[i];
            s += a[i];
        }
        f(0,n)
        {
            ll p = s - a[i];
            if(m.count(p))
            {
                cout<<"YES\n";
                cout<<m[p].first<<" "<<m[p].second<<"\n";
                cout<<c<<" "<<i+1<<"\n";
                return 0;
            }
        }
        f(0,n)
        {
            ll p = s - a[i];
            m[p] = mp(c,i+1);
        }
        c++;
    }
    cout<<"NO\n";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}


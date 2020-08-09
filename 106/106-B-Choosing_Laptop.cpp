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
    vector<tuple<ll, ll, ll, ll, ll>> t;
    f(0, n)
    {
        ll a, b, c, d;
        cin>>a>>b>>c>>d;
        t.pb(make_tuple(a, b, c, d, i+1));
    }
    sort(t.begin(), t.end());
    bool bb[n+1] = {false};
    f(0, n)
    {
        ll a=get<0>(t[i]), b=get<1>(t[i]), c=get<2>(t[i]);
        fi(i+1, n)
        {
            if(get<0>(t[j])>a && get<1>(t[j])>b && get<2>(t[j])>c)
            {
                bb[i] = true;
                break;
            }
        }
    }
    ll c=1e18, ans=0;
    f(0, n)
    {
        if(!bb[i])
        {
            if(get<3>(t[i]) < c)
            {
                c = get<3>(t[i]);
                ans = get<4>(t[i]);
            }
        }
    }
    cout<<ans;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}


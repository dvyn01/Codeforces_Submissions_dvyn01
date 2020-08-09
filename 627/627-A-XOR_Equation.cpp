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

    int64_t s, x;
    cin>>s>>x;
    if((!(s&1) && x&1) || (!(x&1) && s&1))
    {
        cout<<0;
        return 0;
    }
    ll k = s - x;
    if(k & 1)
    {
        cout<<0;
        return 0;
    }
    k /= 2;
    ll ans = 0;
    ll c = 0;
    fr(62, 0)
    {
        ll k1 = (1LL << j) & x;
        ll k2 = (1LL << j) & k;
        if(k1 > 0 && k2 > 0)
        {
            cout<<0;
            return 0;
        }
        if(k1 > 0)
            c++;
    }
    if(x == s)
        cout<<(1LL << c) - 2;
    else cout<<(1LL << c);

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

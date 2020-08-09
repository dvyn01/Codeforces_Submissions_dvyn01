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

bool check(ll n)
{
    while(n)
    {
        ll x = n%10;
        if(x!=4 && x!=7)
            return false;
        n /= 10;
    }
    return true;
}


ll find_next(ll n)
{
    ll r=0;
    ll c=1;
    while(n)
    {
        ll x = n%10;
        if(x <= 4)
            r = 4*c+r;
        else if(x>4 && x<=7 && check(n/10))
            r = 7*c+r;
        else{
            r = 4*c+r;
            n/=10;  c *= 10;
            n++;
            continue;
        }
        n /= 10;
        c *= 10;
    }
    return r;
}

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	// freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll l, r;
    cin>>l>>r;
    ll s=0;
    f(l, r+1)
    {
        ll x = find_next(i);
        s += min(r-i+1, x-i+1) * x;
        i = x;
    }
    cout<<s;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}


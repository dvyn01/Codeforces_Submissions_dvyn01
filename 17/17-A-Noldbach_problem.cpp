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
bool p[1055];
vll prime;

void sieve()
{
    f(2, 1050)
    {
        if(!p[i])
        {
            prime.pb(i);
            for(ll j=i; j<1050; j+=i)
                p[j] = true;
        }
    }
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

    sieve();
    ll n, k, c=0;
    cin>>n>>k;
    ll in = 0;
    while(prime[in] <= n)
    {
        ll pp = prime[in];
        pp--;
        fi(0, prime.size())
        {
            if(prime[j+1] >= pp)
                break;
            if(prime[j]+prime[j+1] == pp)
            {   c++;    break; }
        }
        in++;
    }
    if(c >= k)  cout<<"YES";
    else cout<<"NO";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}


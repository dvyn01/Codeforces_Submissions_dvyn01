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
ll k, a[110];

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
    string ss;
    cin>>ss;
    ll s=0;
    f(0, n) {   a[i] = ss[i] - '0';     s += a[i]; }
    ll c = 2;
    while(c <= n)
    {
        k = s / c;
        if(s % c)
        {  c++; continue;   }
        if(k < a[n-1])
            break;
        bool ok = true;
        ll cs = 0;
        f(0, n)
        {
            if(cs + a[i] <= k)
                cs += a[i];
            else {
                ok = false;
                break;
            }
            if(cs == k)
                cs = 0;
        }
        if(cs == 0 && ok)
        {
            cout<<"YES";
            return 0;
        }
        c++;
    }
    cout<<"NO";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}


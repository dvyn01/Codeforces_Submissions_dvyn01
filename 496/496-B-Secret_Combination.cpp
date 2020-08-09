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

    ll n;
    cin>>n;
    string z;
    cin>>z;
    vector<string> v;
    f(0,10)
    {
       // v.pb(z);
        f(0,n)
        {
            string p;
            p += z[n-1];
            for(ll j=0; j<n-1; j++)
                p += z[j];
            v.pb(p);
           // cout<<p<<" ";
            z=p;
        }
        f(0,n){
            if(z[i] == '9') z[i]='0';
            else z[i]++;
        }
       // cout<<z<<"    ";
    }
    sort(v.begin(), v.end());
    cout<<v[0];

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}


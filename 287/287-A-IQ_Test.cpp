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

    string s[4];
    bool ok = false;
    ll d;
    f(0, 4) cin>>s[i];
    f(0, 3)
    {
        d = 0;
        fi(1, 4)
        {
            d = 0;
            char c = s[i][j];
            if(s[i+1][j] != c) d++;
            if(s[i][j-1] != c) d++;
            if(s[i+1][j-1] != c) d++;
            if(d <= 1 || d==3) ok = true;
        }
    }
    if(ok) cout<<"YES";
    else cout<<"NO";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

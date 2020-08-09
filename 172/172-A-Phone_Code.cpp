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
    string s[n];
    f(0, n) cin>>s[i];
    string z;
    f(0, s[0].length()){
        if(s[0][i] == s[1][i])
            z += s[0][i];
        else break;
    }
    f(1, n-1)
    {
        string zz;
        fi(0, s[0].length())
        {
            if(s[i][j] == s[i+1][j])
                zz += s[i][j];
            else break;
        }
        if(zz.length() < z.length())
            z = zz;
    }
    cout<<z.length();

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}


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

    ll n, m;
    cin>>n>>m;
    string s[n];
    unordered_map<char, unordered_map<ll, ll>> r, c;
    f(0, n)
    {
        cin>>s[i];
        fi(0, m)
        {
            r[s[i][j]][i]++;
            c[s[i][j]][j]++;
        }
    }
    string ans;
    f(0, n)
    {
        fi(0, m)    if(r[s[i][j]][i]<2 && c[s[i][j]][j]<2)  ans += s[i][j];
    }
    cout<<ans;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}


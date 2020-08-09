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

bool compare(string a, string b)
{
    return a.length() < b.length();
}

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	//freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll n;
    cin>>n;
    string s[n];
    f(0,n) cin>>s[i];
    sort(s, s+n, compare);
    f(1,n)
    {
        if(s[i].find(s[i-1]) == -1)
        {
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
    f(0,n) cout<<s[i]<<"\n";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}


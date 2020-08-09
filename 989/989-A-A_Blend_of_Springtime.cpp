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

    ll k=0;
    string s;
    cin>>s;
    f(1, s.length()-1)
    {
        if(s[i-1]!=s[i+1] && s[i+1]!=s[i] && s[i-1]!=s[i] && s[i]!='.' && s[i+1]!='.' && s[i-1]!='.')
            k++;
    }
    if(k==0)
        cout<<"No";
    else cout<<"Yes";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}


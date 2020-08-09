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

    string s;
    cin>>s;
    if(s.length() <= 3){cout<<"No"; return 0; }
    ll c=0; bool b[26] = {false};
    f(0, s.length()){
        if(!b[s[i]-97])
        {
            c++;
            b[s[i]-97] = true;
        }
    }
    if(c>4 || c==1){cout<<"No"; return 0; }
    if(c==2){
        ll a=0, b=0;
        char ch = s[0];
        f(0,s.length()){
            if(s[i] == ch) a++;
            else b++;
        }
        if(a==1 || b==1){cout<<"No"; return 0; }
    }
    cout<<"Yes";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}


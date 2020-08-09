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

    ll n, k=0;
    cin>>n;
    string s;
    cin>>s;
    if(s[0]=='?' || s[n-1]=='?')
         k++;
    f(1, n-2)
    {
        if(s[i]=='?')
        {
            ll j=i+1;
            while(s[j]=='?')
                j++;
            if(j-i >= 2)
            {
                k++;
                break;
            }
            if(j-i==1 && s[i-1]==s[i+1]){
                k++;
                break;
            }
        }
    }
        f(0, s.length())
        {
            if(s[i]==s[i+1] && s[i]!='?')
            {
                cout<<"No";
                return 0;
            }
        }
        if(k==0)
            cout<<"No";
        else cout<<"Yes";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}


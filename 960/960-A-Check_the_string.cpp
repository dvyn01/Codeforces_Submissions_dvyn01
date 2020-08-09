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


int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	//freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    string s;
    cin>>s;
    ll f[3] = {0},p=0;
    string z=s;
    sort(z.begin(), z.end());
    f(0,s.length())
    {
        if(s[i] != z[i])
        {
            p++;
            break;
        }
    }
    f(0,s.length())
        f[s[i]-97]++;
    f(0,3)
    {
        if(f[i]==0)
            p++;
    }
    if(!(f[2]==f[0] || f[2]==f[1]))
        p++;
    if(p==0)
        cout<<"YES";
    else cout<<"NO";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}


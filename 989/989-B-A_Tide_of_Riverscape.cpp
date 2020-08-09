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

    ll n, p, k=0;
    cin>>n>>p;
    vector<int> v[p];
    string s;
    cin>>s;
    if(k>=n){cout<<"No"; return 0;}
    f(0,p)
    {
        ll q=i;
        while(s[q]=='.' && q<n)
            q += p;
        for(ll j=q; j<n; j+=p)
        {
            if(s[j]!=s[q])
            {
                if(s[j]=='.')
                {
                    if(s[q]=='1') s[j]='0';
                    else if(s[q]=='0') s[j]='1';
                }
            }
        }
    }
    for(ll i=n-1; i>=n-p; i--)
    {
        ll q=i;
        while(s[q]=='.' && q>=0)
            q -= p;
        for(ll j=q; j>=0; j-=p)
        {
            if(s[j]!=s[q])
            {
                if(s[j]=='.')
                {
                    if(s[q]=='1') s[j]='0';
                    else if(s[q]=='0') s[j]='1';
                }
            }
        }
    }
    f(0,p)
    {
        if(s[i]=='.')
        {
            s[i] = '0';
            for(ll j=i+p; j<n; j+=p)
                s[j] = '1';
        }
    }
    f(0,p)
    {
        for(ll j=i; j<n; j+=p)
        {
            if(s[i] != s[j])
            {
                k++;
                break;
            }
        }
    }

    if(k>0)
        cout<<s;
    else cout<<"No";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

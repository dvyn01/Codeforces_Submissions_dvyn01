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

ll cn(string s)
{
    ll p = s.length()-1, q=p;
    ll r=0;
    fr(s.length()-2, 0)
    {
        if(s[j] == s[p])
        {
            ll k = j, l=0;
           while(k>=0 && s[k]==s[p])
           {
               k--;
               p--;
               l++;
           }
           if(k == -1)
                r = max(l, r);
           p = q;
        }
    }
    return r;
}

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	// freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    if(s.length()==1)
    {
        f(0, k) cout<<s;
        return 0;
    }
    ll r = cn(s);
    cout<<s;
    k--;
    while(k--)
    {
        f(r, s.length())    cout<<s[i];
    }

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}


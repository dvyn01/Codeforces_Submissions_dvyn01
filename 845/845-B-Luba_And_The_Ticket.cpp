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

    string s;
    cin>>s;
    vll a, b;
    ll x=0,y=0;
    f(0, 3) {   a.pb(s[i]-48);  x+=s[i]-48; }
    f(3,6)  {   b.pb(s[i]-48);  y+=s[i]-48; }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if(x==y){cout<<"0"; return 0;}
    ll c=0, fp=0, sp=2;
    ll d = abs(x-y);
    if(x < y)
    {
        f(0, 3)
        {
            ll xx = 9-a[fp], yy = b[sp];
            if(xx < yy)
            {
                d -= yy;
                sp--;
            }
            else
            {
                d -= xx;
                fp++;
            }
            c++;
            if(d<=0)    break;
        }
    }
    else
    {
        f(0, 3)
        {
            ll xx = 9-b[fp], yy = a[sp];
            if(xx < yy)
            {
                d -= yy;
                sp--;
            }
            else
            {
                d -= xx;
                fp++;
            }
            c++;
            if(d<=0)    break;
        }
    }
    cout<<c;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}


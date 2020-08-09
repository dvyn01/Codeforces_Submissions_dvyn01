//          * AUTHOR : Divyanshu *

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
ll z[105000];

ll zalg(string s, ll n)
{
    memset(z, 0, sizeof(z));
    ll l=0, r=0;
    f(0, s.length())
    {
        if(i > r)
        {
            l = r = i;
            while(r<s.length() && s[r]==s[r-l])
                r++;
            z[i] = r-l;
            r--;
        }
        else{
            ll k = i-l;
            if(z[k] < r-i+1)
                z[i] = z[k];
            else{
                l = i;
                while(r<s.length() && s[r]==s[r-l])
                    r++;
                z[i] = r-l;
                r--;
            }
        }
    }
 //   cout<<s<<"\n";
 //   f(0, s.length())    cout<<z[i]<<" ";
 //   cout<<"\n\n\n";
    f(0, s.length())
    {
        if(z[i] == n)
            return i-1;
    }
    return -1;
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

    string s, a, b;
    cin>>s>>a>>b;
    if(a.length()+b.length() > s.length()){cout<<"fantasy"; return 0; }
    bool f=false, bc=false;
    string c = a + '$' + s;
    ll r = zalg(c, a.length());
    if(r != -1)
    {
        c = b + '$';
        f(r, s.length())
            c += s[i];
        r = zalg(c, b.length());
        if(r != -1)
            f = true;
    }
    reverse(s.begin(), s.end());
    c = a + '$' + s;
    r = zalg(c, a.length());
    if(r != -1)
    {
        c = b + '$';
        f(r, s.length())
            c += s[i];
        r = zalg(c, b.length());
        if(r != -1)
            bc = true;
    }
    if(f && bc)
        cout<<"both";
    else if(f)
        cout<<"forward";
    else if(bc)
        cout<<"backward";
    else cout<<"fantasy";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}


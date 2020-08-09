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

    ll n, t;
    cin>>n>>t;
    string a, b;
    cin>>a>>b;
    string s = a;
    ll x=0, y=0;
    if(a==b)
    {
        f(0, n)
        {
            if(x==t) break;
            fi(0, 26)
            {
                if(97+j != s[i])
                {
                    s[i] = 97+j;
                    x++;
                    break;
                }
            }
            if(x==t) break;
        }
        cout<<s; return 0;
    }
    f(0, n)
        if(s[i] != b[i]) x++;
    if(x > t)
    {
        f(0, n)
        {
            if(s[i] != b[i])
            {
                s[i] = b[i];
                x--;
                y++;
            }
            if(x==t) break;
        }
        if(y < t)
        {
            f(0, n)
            {
                if(s[i]==a[i] && s[i]!=b[i])
                {
                    fi(0, 26)
                    {
                        if(s[i]!=97+j && 97+j!=b[i])
                        {
                            s[i] = 97+j;
                            y++;
                            break;
                        }
                    }
                    if(y==t) break;
                }
            }
        }
    }
    else{
        f(0, n)
        {
            if(x==t) break;
            if(s[i]==b[i])
            {
                fi(0, 26)
                {
                    if(s[i]!=97+j)
                    {
                        x++;
                        y++;
                        s[i] = 97+j;
                        break;
                    }
                }
            }
            if(x==t) break;
        }
        if(y < t)
        {
            f(0, n)
            {
                if(s[i]==a[i] && s[i]!=b[i])
                {
                    fi(0, 26)
                    {
                        if(s[i]!=97+j && 97+j!=b[i])
                        {
                            s[i] = 97+j;
                            y++;
                            break;
                        }
                    }
                }
                if(y==t) break;
            }
        }
    }
    if(x==t && y==t) cout<<s;
    else cout<<"-1";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}


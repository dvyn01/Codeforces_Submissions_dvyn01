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

    ll n;
    cin>>n;
    ll a[n+1][n+1];
    memset(a, 0, sizeof(a));
    if(n%2)
    {
        ll x=0, p=2, y=n/2+1;
        f(1, n+1)
        {
            fi(1, n+1)
            {
                if(abs(j-y)<=x)
                    continue;
                a[i][j] = p;
                p += 2;
            }
            if(i <= n/2)
                x++;
            else x--;
        }
        p=1;
        f(1, n+1)
        {
            fi(1, n+1)
            {
                if(a[i][j] == 0)
                {
                    a[i][j] = p;
                    p += 2;
                }
            }
        }
    }
    else
    {
        ll p = 2;
        f(1, n+1)
        {
            a[i][i] = p;
            p += 2;
        }
        ll x = 1;
        f(1, n/2)
        {
            fr(n-x, 1)
            {
                if(a[i][j] != 0)    break;
                a[i][j] = p;
                p += 2;
            }
            x++;
        }
        x = 2;
        fr(n, n/2+1)
        {
            f(x, n)
            {
                if(a[j][i] != 0)    break;
                a[j][i] = p;
                p += 2;
            }
            x++;
        }
        p = 1;
        f(1, n+1)
        {
            fi(1, n+1)
            {
                if(a[i][j] != 0)    continue;
                a[i][j] = p;
                p += 2;
            }
        }
    }
    f(1, n+1)
    {
        fi(1, n+1)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

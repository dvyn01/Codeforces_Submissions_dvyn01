//          * AUTHOR : Divyanshu *      .......

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define f(a,b) for(ll i=a; i<b; i++)
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define vll vector<ll>
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

    char a[505][505];
    char ch;
    ll n, m, s=0;
    cin>>n>>m;
    f(0,n)
    {
        for(ll j=0; j<m; j++)
        {
          cin>>ch;
          a[i][j] = ch;
        }
    }
    f(0,n)
    {
        for(ll j=0; j<m; j++)
        {
            if(a[i][j] == 'S')
            {
                if(a[i+1][j]=='W' || a[i-1][j]=='W' || a[i][j+1]=='W' || a[i][j-1]=='W')
                {
                    s++;
                    break;
                }
            }
        }
        if(s>0) break;
    }
    if(s>0)
    {
        cout<<"No\n";
        return 0;
    }
    cout<<"Yes\n";
    f(0,n)
    {
       for(ll j=0; j<m; j++)
        {
            if(a[i][j] == '.')
                cout<<"D";
            else cout<<a[i][j];
        }
        cout<<"\n";
    }

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}
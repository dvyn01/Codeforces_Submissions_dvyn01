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


int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	//freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll n, k;
    cin>>n>>k;
    ll a[n][n] = {0};
    char c[n][n+1];
    f(0,n*n)
        cin>>c[i/n][i%n];
     f(0,n*n)
        a[i/n][i%n]=0;
    f(0,n)
    {
        for(ll j=0; j<n; j++)
        {
            if(c[j][i] == '.')
            {
                ll cc=0, p=j;
                while(p<n && c[p][i]=='.')
                    {cc++;  p++; }
                if(cc >= k)
                {   ll m=1;
                    for(ll kk=0; kk<=(cc-1)/2; kk++)
                    {
                        if(kk+j == j+cc-1-kk){
                            a[j+cc-1-kk][i] += m;
                            continue;
                        }
                        a[kk+j][i] += m;
                        a[j+cc-1-kk][i] += m;
                        if(m < min(k,cc-k+1))
                            m++;
                    }
                }
                j = p-1;
            }
        }
    }
     f(0,n)
    {
        for(ll j=0; j<n; j++)
        {
            if(c[i][j] == '.')
            {
                ll cc=0, p=j;
                while(p<n && c[i][p]=='.')
                    {cc++;  p++; }
                if(cc >= k)
                {   ll m=1;
                    for(ll kk=0; kk<=(cc-1)/2; kk++)
                    {
                        if(kk+j == j+cc-1-kk){
                            a[i][kk+j] += m;
                            continue;
                        }
                        a[i][kk+j] += m;
                        a[i][j+cc-1-kk] += m;
                        if(m<min(k,cc-k+1))
                            m++;
                    }
                }
                j = p-1;
            }
        }
    }
    ll m=0, x=1, y=1;
  /*  f(0,n)
    {
        for(ll j=0; j<n; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    } */
   f(0,n)
   {
       for(ll j=0; j<n; j++)
       {
           if(a[i][j] > m)
           {
               m=a[i][j];
               x=i+1;
               y=j+1;
           }
       }
   }
    cout<<x<<" "<<y;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}


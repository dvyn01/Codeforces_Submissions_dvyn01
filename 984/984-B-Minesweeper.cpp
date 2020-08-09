//          * AUTHOR : Divyanshu ****

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define f(a,b) for(ll i=a; i<b; i++)
#define mod 1000000007

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	//freopen("output.txt", "wt", stdout); *No Need*
	#endif
  //  ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
   // cout.tie(0);

    ll n,m;
    cin>>n>>m;
    string s[n+2];
    s[0].assign(m+2, '0');
    s[n+1].assign(m+2, '0');
    f(1, n+1)
    {
        s[i] = '0';
    }
    f(1,n+1)
    {
            string a;
            cin>>a;
            s[i] = s[i]+a;
    }
    f(1, n+1)
    {
        s[i] += '0';
    }
    ll p=0, q=0;
   // f(0, n+2)
     //   cout<<s[i]<<"\n";

    f(1,n+1)
    {
        for(ll j=1; j<m+1; j++)
        {
            if(s[i][j] == '.')
            {
               if(s[i-1][j]=='*' || s[i+1][j]=='*' || s[i][j-1]=='*' || s[i][j+1]=='*' || s[i-1][j-1]=='*' || s[i-1][j+1]=='*' || s[i+1][j-1]=='*' || s[i+1][j+1]=='*')
                    q++;
            }
            else if(s[i][j]>='1' && s[i][j]<='8')
            {
                ll ss=0;
                if(s[i-1][j]=='*')  ss++;
                if(s[i+1][j]=='*')  ss++;
                if(s[i][j-1]=='*')  ss++;
                if(s[i][j+1]=='*')    ss++;
                if(s[i-1][j-1]=='*')  ss++;
                if(s[i-1][j+1]=='*')  ss++;
                if(s[i+1][j-1]=='*')    ss++;
                if(s[i+1][j+1]=='*')    ss++;
                //cout<<ss<<"*\n";
                if(ss != s[i][j]-48)
                    p++;
            }
        }
      //  cout<<i<<" "<<p<<" "<<q<<"\n";
        if(p!=0 || q!=0)
            break;
    }
    if(p==0 && q==0)
        cout<<"YES";
    else cout<<"NO";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}               
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

    ll n, c=0;
    cin>>n;
    string s;
    cin>>s;
    ll v=0, h=0;
    f(0,s.length())
    {
        if(h==0){
            if(s[i] == 'R')
                h = 1;
            else if(s[i] == 'L')
                h = -1;
        }
        if(v==0)
        {
            if(s[i] == 'U')
                v = 1;
            else if(s[i] == 'D')
                v = -1;
        }
        if(h==1)
        {
            if(s[i] == 'L')
            {
                c++;
                h = -1;
                v=0;
            }
        }
        else if(h == -1)
        {
            if(s[i] == 'R')
            {
                c++;
                h = 1;
                v=0;
            }
        }
         if(v==-1)
        {
            if(s[i] == 'U')
            {
                c++;
                v = 1;
                h=0;
            }
        }
        else if(v==1)
        {
            if(s[i] == 'D')
            {
                c++;
                v = -1;
                h=0;
            }
        }
    }
    cout<<c+1;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}


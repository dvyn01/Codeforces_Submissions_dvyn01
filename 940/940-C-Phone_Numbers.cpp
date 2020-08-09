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

    ll n, k;
    string s;
    cin>>n>>k>>s;
    if(k > n)
    {
        char x = s[0];
        f(1,n)
        {
           if(s[i] < x)
                x = s[i];
        }
        string z=s;
        f(0, k-n)
        {
            z += x;
        }
        cout<<z;
    }
    else{
        char x=s[0], y=s[0], p;    string z;
        ll j=k-1, f[26]={0};
        f[s[0]-97]++;
        f(1,n)
        {
           if(s[i] > x)
                x=s[i];
            if(s[i]<y)
                y=s[i];
            f[s[i]-97]++;
        }
      /*  if(k==1){
            f(s[0]-97+1,26){
            if(f[i]){z += 'a'+i; break;} }
            cout<<z; return 0;
        } */
        while(s[j]==x)
            j--;
        f(0,j)
            z += s[i];
        //cout<<j<<" ";
        p = s[j];
        f(p-97+1,26){
            if(f[i]){z+='a'+i; break;}
        }
        f(z.length(), k)
        {
            z += y;
        }
        cout<<z;
    }

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}


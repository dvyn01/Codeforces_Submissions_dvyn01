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
ll r,s;

bool check(ll p, ll q, int b[][550])
{
    if(p==r && q==s && b[p][q]>0)
        return true;
    if(b[p][q]) return false;
   // cout<<p<<" "<<q<<"\n";
    b[p][q]++;
    return check(p+1,q,b) || check(p-1,q,b) || check(p,q+1,b) || check(p,q-1,b);
    return false;
}



int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	//freopen("output.txt", "wt", stdout); *No Need*
	#endif
  //  ios_base::sync_with_stdio(false);
  //  cin.tie(NULL);
  //  cout.tie(0);

    ll m,n;
    cin>>n>>m;
    int b[550][550];
    memset(b, 1, sizeof(b));
    f(1,n+1)
    {
        string s;
        cin>>s;
        for(ll j=1; j<s.length()+1; j++)
        {
            if(s[j-1]  == '.')
                b[i][j] = 0;
        }
    }
    ll p, q;
    cin>>p>>q>>r>>s;
    b[p][q] = 0;
    if(check(p, q, b))
        cout<<"YES";
    else cout<<"NO";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}


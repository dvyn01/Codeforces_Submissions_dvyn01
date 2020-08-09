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

    string s;   ll k;
    cin>>s>>k;
    ll pos=-1, n=s.length();
    ll j=0;
    bool ok = false;
    while(k){
    pos = -1;
     if(j==n) break;
    char c=s[j++];
    string p;
    f(j, min(n, j+k))
    {
        if(s[i] > c)
        {
            pos=i;  c=s[i]; p=c;
        }
    }
    if(pos == -1) continue;
    s.erase(s.begin() + pos);
    s.insert(j-1, p);
    k -= pos-j+1;
    if(j==n) break;
  //  cout<<s<<" "<<j-1<<" "<<k<<"\n";
    }
    cout<<s;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}


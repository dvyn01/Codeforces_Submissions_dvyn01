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

    ll n, m;
    cin>>n>>m;
    if(n==0 && m>0)
    {
        cout<<"Impossible";
        return 0;
    }
    ll m1, m2;
    if(m>n)
    {
        m1 = n + (m-n);
        m2 = m+n-1;
    }
    else{
        m1 = n;
        if(m!=0)
        m2 = m+n-1;
        else m2=n;
    }
    cout<<m1<<" "<<m2;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}


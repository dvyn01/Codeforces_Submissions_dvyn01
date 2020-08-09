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
   	// freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll n, k, sum=0;
    set<ll> s;
    map<ll,ll> f;
    cin>>n>>k;
    ll a[n];
    f(0, n){ cin>>a[i]; f[a[i]]++; s.insert(a[i]);}
    set<ll> :: iterator it, itt;
    for(it=s.begin(); it!=s.end(); )
    {
        itt=it; ++it;
        if(it==s.end()) break;
        if(*it>*itt && *itt+k>=*it)
            sum += f[*itt];
    }
    cout<<n-sum;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}


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

ll n, d[1000000], s[10000000];

void fun(ll p){
	if (d[p]!=1) return;
	ll q = s[p];
	cout<<p<<" "<<q<<"\n";
	s[q] ^= p;
	d[p]--;
	d[q]--;
	fun(q);
	return;
}

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	// freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    cin>>n;
    ll ss=0;
    f(0,n)
    {
        cin>>d[i]>>s[i];
        ss += d[i];
    }
    cout<<ss/2<<"\n";
    f(0,n)
        fun(i);

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}


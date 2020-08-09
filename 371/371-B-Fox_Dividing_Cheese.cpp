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

    ll a, b;
    scanf("%lld%lld", &a, &b);
    ll p=0, q=0, r=0, x=0, y=0, z=0;
    while(a%2==0)
    {   p++;    a /= 2; }
    while(a%3==0)
    {   q++;    a /= 3; }
    while(a%5==0)
    {   r++;    a /= 5; }
    while(b%2==0)
    {   x++;    b /= 2; }
    while(b%3==0)
    {   y++;    b /= 3; }
    while(b%5==0)
    {   z++;    b /= 5; }
    ll ans = 0;
    if(a!=b)
        cout<<"-1";
    else{
        ans = min(p,x)+min(q,y)+min(r,z);
        ans = (p+q+r+x+y+z) - 2*ans;
        printf("%lld", ans);
    }

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}


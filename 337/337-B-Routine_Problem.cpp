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
#define fr(a,b) for(ll j=a; j>=b; j--)
#define fi(a,b) for(ll j=a; j<b; j++)

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	// freopen("output.txt", "wt", stdout); *No Need*
	#endif
 //   ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(0);

    ld a, b, c, d;
    cin>>a>>b>>c>>d;
    ld x=c/d, y=d/c;
    ld ar = a*b;
    ld d1 = a*y, c1 = b*x;
    ld arr = 0;
    if(d1<=b && a*d1>arr) arr = a*d1;
    if(c1<=a && b*c1>arr) arr = b*c1;
    arr = ar-arr;
    ll k=2;
    ll p=0, q=0;
    while(abs(arr-p)>0.00001 || abs(ar-q)>0.00001)
    {
        arr /= (k-1); ar /= (k-1);
        arr *= k; ar*=k;
        k++;
        if(ceil(arr)-arr < arr-floor(arr)) p = ceil(arr);
        else p = floor(arr);
        if(ceil(ar)-ar < ar-floor(ar)) q = ceil(ar);
        else q = floor(ar);
        if(abs(arr-p)==0 && abs(ar-q)==0) break;
    }
    ll g = __gcd(p,q); p/=g; q/=g;
    cout<<p<<"/"<<q;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}


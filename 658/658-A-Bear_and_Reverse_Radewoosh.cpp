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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    int n, c, k=0;
    cin>>n>>c;
    int a[n], t[n];
    f(0, n) cin>>a[i];
    f(0, n) cin>>t[i];
    int x=0, y=0;
    f(0, n) {
        k += t[i];
        x += max(a[i]-c*k, 0);
    }
    k=0;
    fr(n-1, 0){
        k += t[j];
        y += max(a[j]-c*k, 0);
    }
    if(x > y) cout<<"Limak";
    else if(y > x) cout<<"Radewoosh";
    else cout<<"Tie";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}


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
ll m, s, l, xs, xxs ,xxxs, xl, xxl, xxxl;

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	// freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll n;
    cin>>n;
    string ss;
    ll c=0;
    f(0,n){
        cin>>ss;
        if(ss == "M") m++;
        else if(ss=="S") s++;
        if(ss == "L") l++;
         else if(ss == "XS") xs++;
        else if(ss == "XXS") xxs++;
        else if(ss == "XXXS") xxxs++;
        else if(ss == "XL") xl++;
        else if(ss == "XXL") xxl++;
        else if(ss == "XXXL") xxxl++;
    }
    f(0,n){
        cin>>ss;
        if(ss=="M") m--;
        else if(ss=="S") s--;
        if(ss == "L") l--;
         else if(ss == "XS") xs--;
        else if(ss == "XXS") xxs--;
        else if(ss == "XXXS") xxxs--;
        else if(ss == "XL") xl--;
        else if(ss == "XXL") xxl--;
        else if(ss == "XXXL") xxxl--;
    }
    c = abs(m) + abs(s) + abs(l) + abs(xs) + abs(xxs)+ abs(xxxs)+ abs(xl)+ abs(xxl)+ abs(xxxl);
    cout<<c/2;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

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

    ll b, q, l, m;
    cin>>b>>q>>l>>m;
    map<ll,ll> mm;
    f(0,m){ll x; cin>>x; mm[x]++; }
    if(b==0)
    {
        if(mm[0]==0)
            cout<<"inf";
        else cout<<"0";
        return 0;
    }
    if(q==1 || q==-1)
    {
        if((q==1 && mm[b]!=0) || (q==-1 && mm[b]!=0 && mm[-1*b]!=0) || (abs(b)>l))
            cout<<"0";
        else if(abs(b)<=l)cout<<"inf";
        return 0;
    }
    if(q==0)
    {
        if((b==0 && mm[0]!=0) || (b!=0 && mm[0]!=0 && mm[b]!=0) || (abs(b)>l))
            cout<<"0";
        else if(b!=0 && mm[0]!=0 && mm[b]==0)
            cout<<"1";
        else if(mm[0]==0) cout<<"inf";
        return 0;
    }
    ll c=0;
    for(ll j=b; abs(j)<=l; j*=q)
    {
        if(mm[j]==0)
            c++;
    }
    cout<<c;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}


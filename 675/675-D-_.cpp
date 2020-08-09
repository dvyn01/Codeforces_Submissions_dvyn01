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
#define fii(a,b) for(ll k=a; k<b; k++)
unordered_map<ll,ll> a, b;


int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	// freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll n, rr;
    cin>>n;
    set<ll> s;
    f(0, n)
    {
        ll x;
        cin>>x;
        if(i==0){s.insert(x);   rr=x;    continue;}
        auto it = s.upper_bound(x);
        ll c;
        if(it!=s.end() && !a[*it])
        {
            a[*it]++;
            c = *it;
        }
        else
        {
            it--;
            b[*it]++;
            c = *it;
        }
        s.insert(x);
        cout<<c<<" ";
    }

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}


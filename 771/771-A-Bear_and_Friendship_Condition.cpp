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
ll a[1500005];
ll s[1500005];

void initialize(ll n)
{
    f(1,n+1)
    {
        a[i] = i;
        s[i] = 1;
    }
}

ll root(ll i)
{
    while(a[i] != i)
        i = a[a[i]];
    return i;
}

void unionn(ll x, ll y)
{
    ll as = root(x), bs = root(y);
    if(as==bs) return;
    if(s[as] > s[bs])
    {
        a[bs] = a[as];
        s[as] += s[bs];
    }
    else{
        a[as] = a[bs];
        s[bs] += s[as];
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	//freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll n, m, x, y, sum=0;
    cin>>n>>m;
    initialize(n);
    f(0,m)
    {
        cin>>x>>y;
        unionn(x, y);
    }
    f(1,n+1)
    {
        if(a[i] == i)
            sum += s[i]*(s[i]-1)/2;
    }
    if(sum == m)
        cout<<"YES";
    else cout<<"NO";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}


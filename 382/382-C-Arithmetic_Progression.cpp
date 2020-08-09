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
   	//freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    map<ll,ll> m;
    ll n, p=0, q=0, r=0;
    cin>>n;
    ll a[n];
    f(0,n) cin>>a[i];
    if(n==1)
    {   cout<<"-1"; return 0;}
    sort(a, a+n);
    if(n==2)
    {
        ll p = a[1]-a[0];
        if(p==0){cout<<"1\n"<<a[0]; return 0;}
        else if(p%2==1){cout<<"2\n"<<a[0]-p<<" "<<a[1]+p<<" "; return 0;}
        else { cout<<"3\n"<<a[0]-p<<" "<<(a[1]+a[0])/2<<" "<<a[1]+p; return 0;}
    }
    if(a[0] == a[n-1])
    {
        cout<<"1\n"<<a[0];
        return 0;
    }
    f(1,n)
    {
      ll p = a[i] - a[i-1];
      m[p]++;
      if(m.size() > 2)
      {
          cout<<"0";
          return 0;
      }
    }
    map<ll,ll> :: iterator it  = m.begin(), itt;
    while(it != m.end())
    {
        itt = it;
        it++;
    }
    if(m.size() == 1)
    {
        ll d = m.begin()->first;
        cout<<"2\n"<<a[0]-d<<" "<<a[n-1]+d;
        return 0;
    }
    if(m.size() == 2)
    {
        if(2*m.begin()->first != itt->first || itt->second > 1)
        {
          cout<<"0";
          return 0;
        }
        f(1,n)
        {
            if(a[i] - a[i-1] == itt->first)
            {
                cout<<"1\n"<<a[i-1]+m.begin()->first;
                return 0;
            }
        }
    }

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}


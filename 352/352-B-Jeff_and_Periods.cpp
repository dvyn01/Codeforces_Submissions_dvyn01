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
    set<ll> s;
    ll n;
    vll v[100005];
    pll p;
    cin>>n;
    ll a[n+1];
    f(1,n+1)
    {
        cin>>a[i];
        v[a[i]].pb(i);
        m[a[i]]++;
        if(m[a[i]] == 1)
            s.insert(a[i]);
    }
    set<ll> :: iterator it;
    for(it = s.begin(); it!=s.end(); it++)
    {
        if(v[*it].size()==1)
            p.pb(mp(*it, 0));
        else{
            ll d = v[*it][1] - v[*it][0], k=0;
            f(2, v[*it].size())
            {
                if(v[*it][i]-v[*it][i-1] != d)
                {
                    k++;
                    break;
                }
            }
            if(k==0)
                    p.pb(mp(*it, d));
        }
    }
    sort(p.begin(), p.end());
    cout<<p.size()<<"\n";
    f(0,p.size())
        cout<<p[i].first<<" "<<p[i].second<<"\n";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}


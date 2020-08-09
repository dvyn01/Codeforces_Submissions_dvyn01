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
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(0);

    ll n, k;
    cin>>n>>k;
    pll a;
    map<ll,ll> m;
    multiset<ll> s;
    ll b[n+1], c[n+1], ans[n+1];
    f(0,n) { cin>>b[i]; a.pb(mp(b[i], i)); }
    f(0,n) {
        cin>>c[i];
        m[i] = c[i];
    }
    sort(a.begin(), a.end());
    ll ss=0;
    f(0,k+1)
    {
        if(i==0) { ss += m[a[i].second]; ans[a[i].second] = ss; s.insert(ss); continue; }
        if(i!=0 && a[i].first > a[i-1].first)
        {
            ans[a[i].second] = ss + m[a[i].second];
            s.insert(m[a[i].second]); ss += m[a[i].second];
        }
        else{
            ll j=i, x = ss;
        while(a[j].first == a[j-1].first)
        {
            x -= m[a[j-1].second];
            j--;
        }
       // cout<<x<<"*   ";
        x += m[a[i].second]; ans[a[i].second] = x;
        s.insert(m[a[i].second]);
        ss += m[a[i].second];
        }
    }
    while(s.size()>k) { ss-=*s.begin(); s.erase(s.begin()); }
    f(k+1, n)
    {
        if(a[i] > a[i-1]){
        ll p = m[a[i].second];
       // cout<<*s.begin()<<" ";
        if(*s.begin() >= p && s.size()<=k)
            { ans[a[i].second] = ss+p; if(s.size()<k) s.insert(p); }
        else{
            //if(s.size()>k) ss -= *s.begin();
            ss += p;
            s.insert(p);
            ans[a[i].second] = ss;
            while(s.size()>k)
            {ss -= *s.begin(); s.erase(s.begin()); }
        }
        }
        else{
        ll j=i, x = ss;
        while(a[j].first == a[j-1].first)
        {
          //  cout<<"*";
            x -= m[a[j-1].second];
            j--;
        }
        x += m[a[i].second]; ans[a[i].second] = x;
        if(*s.begin() < m[a[i].second] && s.size()==k)
        {
            while(s.size()>=k) s.erase(s.begin()); s.insert(m[a[i].second]);
        }
        }
    }
    f(0, n) cout<<ans[i]<<" ";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

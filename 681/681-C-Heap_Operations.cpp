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

    multiset<ll> s;
    ll n;
    vector< pair<string, ll> > v, ans;
    cin>>n;
    f(0,n)
    {
        string z;
        ll k;
        cin>>z;
        if(z != "removeMin")
        {
            cin>>k;
            v.pb(mp(z, k));
        }
        else v.pb(mp(z, 0));
    }
    f(0,n)
    {
        string z = v[i].first;
        ll k = v[i].second;
        if(z == "insert")
        {
            ans.pb(mp(z, k));
            s.insert(k);
            continue;
        }
        if(z == "getMin")
        { ll x=0;
            while(!s.empty() && *s.begin()<=k)
            {
                if(*s.begin()==k)
                    {
                        ans.pb(mp("getMin", k));
                        x++;
                        break;
                    }
                ans.pb(mp("removeMin", 0));
                s.erase(s.begin());
            }
            if(x==0)
            {
                ans.pb(mp("insert", k));
                s.insert(k);
                ans.pb(mp("getMin", k));
            }
        }
        else{
            if(s.empty())
                {   ans.pb(mp("insert", 1));    s.insert(1);}
            ans.pb(mp("removeMin", 0));
            s.erase(s.begin());
        }
    }
    cout<<ans.size()<<"\n";
    f(0, ans.size())
    {
        if(ans[i].first == "removeMin")
            cout<<ans[i].first<<"\n";
        else cout<<ans[i].first<<" "<<ans[i].second<<"\n";
    }

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}


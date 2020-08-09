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

    ll a, b, c, m, s=0, e=0;
    cin>>a>>b>>c>>m;
    multiset<ll> p, q;
    f(0, m)
    {
        ll x;
        string z;
        cin>>x>>z;
        if(z == "USB")
            p.insert(x);
        else q.insert(x);
    }
    while(a--)
    {
        if(p.empty())
            break;
        e++;
        s += *p.begin();
        p.erase(p.begin());
    }
    while(b--)
    {
        if(q.empty())
            break;
        e++;
        s += *q.begin();
        q.erase(q.begin());
    }
    while(c--)
    {
        if(p.empty() && q.empty())
            break;
        if(p.empty())
        {
            e++;
            s += *q.begin();
            q.erase(q.begin());
            continue;
        }
        else if(q.empty())
        {
            e++;
            s += *p.begin();
            p.erase(p.begin());
            continue;
        }
        ll mm = min(*p.begin(), *q.begin());
        e++;
        s += mm;
        if(mm == *p.begin())
            p.erase(p.begin());
        else if(mm==*q.begin())
            q.erase(q.begin());
    }
    cout<<e<<" "<<s;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}


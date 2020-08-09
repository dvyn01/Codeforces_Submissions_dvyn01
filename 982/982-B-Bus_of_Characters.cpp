//          * AUTHOR : Divyanshu *

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define f(a,b) for(ll i=a; i<b; i++)
#define mod 1000000007

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	//freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll n;
    stack<ll> ss;
    cin>>n;
    vector< pair<ll,ll> > a;
    f(0,n)
    {
        ll c;
        cin>>c;
        a.push_back(make_pair(c,i));
    }
    sort(a.begin(), a.end());
    ll c=0;
    string s;
    cin>>s;
    f(0, s.length())
    {
        if(s[i] == '0')
        {
            cout<<a[c].second+1<<" ";
            ss.push(a[c].second+1);
            c++;
        }
        else
        {
            cout<<ss.top()<<" ";
            ss.pop();
        }
    }

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}


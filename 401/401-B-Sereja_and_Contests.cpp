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

    ll x, k, min=0, max=0;
    cin>>x>>k;
    bool b[x];
    memset(b, false, sizeof(b));
    while(k--)
    {
        ll c;
        cin>>c;
        if(c==1)
        {
            ll p, q;
            cin>>p>>q;
            b[p]=true; b[q]=true;
        }
        else{
            ll p;
            cin>>p;
            b[p] = true;
        }
    }
    f(1, x)
    {
        if(!b[i])
        {
            ll j=i, c=0;
            while(j<x && !b[j])
            {
                c++;
                max++;
                j++;
            }
            if(c%2==0)
                min += c/2;
            else min += c/2+1;
            i = j-1;
        }
    }
    cout<<min<<" "<<max;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}


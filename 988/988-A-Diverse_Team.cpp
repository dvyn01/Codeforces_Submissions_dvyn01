//          * AUTHOR : Divyanshu *

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define f(a,b) for(ll i=a; i<b; i++)
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define vll vector<ll>;
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

    ll n, p, k, b[101] = {0}, c=0;
    vector<ll> v;
    cin>>n>>k;
    f(0,n){
        cin>>p;
        if(!b[p])
            {
                c++;
                v.push_back(i+1);
            }
        b[p]++;
        if(c==k)
            break;
        }
    if(c<k)
        cout<<"NO\n";
    else
    {
        cout<<"YES\n";
        f(0, v.size())
            cout<<v[i]<<" ";
    }

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}


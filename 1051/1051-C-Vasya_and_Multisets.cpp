/*
          * AUTHOR : Divyanshu *
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define f(a,b) for(ll i=a; i<b; i++)
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define pl pair<ll,ll>
#define vll vector<ll>
#define pll vector<pair<ll,ll>>
#define ld long double
#define fr(a,b) for(ll j=a; j>=b; j--)
#define fi(a,b) for(ll j=a; j<b; j++)
#define fii(a,b) for(ll k=a; k<b; k++)

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	// freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll n;
    cin>>n;
    string s;
    f(0, n) s += '*';
    map<ll, ll> m, mm;
    f(0, n)
    {
        ll x;
        cin>>x;
        m[x]++;
        mm[x] = i;
    }
    ll p = -1;
    char cc = 'A';
    for(auto it = m.begin(); it!= m.end(); it++)
    {
        if(it -> second == 1)
        {
            s[mm[it -> first]] = cc;
            if(cc == 'A')
                cc = 'B';
            else cc = 'A';
        }
        else if(it -> second > 2)
            p = mm[it->first];
    }
    if(cc == 'B')
    {
        if(p == -1)
        {
            cout<<"NO";
            return 0;
        }
        s[p] = 'B';
    }
    f(0, n) if(s[i] == '*') s[i] = 'A';
    cout<<"YES\n";
    cout<<s;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}


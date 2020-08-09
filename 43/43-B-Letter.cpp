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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    string a, b;
    getline(cin, a);
    getline(cin, b);
    map<char, ll> m, n;
    f(0, a.length())   { if(a[i]!=' ') m[a[i]]++; }
    f(0, b.length()){
        if(b[i] == ' ') continue;
        n[b[i]]++;
        if(n[b[i]] > m[b[i]])
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}


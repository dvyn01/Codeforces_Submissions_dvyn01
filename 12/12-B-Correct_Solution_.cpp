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
    cin>>a>>b;
    string c = a;
    while(a[0]!='0')
    {
        if(a[0] == '0') break;
        c = a;
        if(!prev_permutation(a.begin(), a.end()))
            break;
        if(a[0] == '0') break;
     //   cout<<a<<" ";
     //   prev_permutation(a.begin(), a.end());
    }
    if(c==b) cout<<"OK";
    else cout<<"WRONG_ANSWER";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}


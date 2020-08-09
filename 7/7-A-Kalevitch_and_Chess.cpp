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

    char a[10][10];
    bool b[10][10] = {false};
    ll c=0;
    f(0, 8){
        for(ll j=0; j<8; j++)
            cin>>a[i][j];
    }
    f(0, 8)
    {
        ll p=0;
        for(ll j=0; j<8; j++)
            if(a[i][j]=='B')
                p++;
        if(p==8)
        {
            c++;
            for(ll j=0; j<8; j++)
                b[i][j] = true;
        }
    }
    f(0,8)
    {
        for(ll j=0; j<8; j++)
        {
            if(a[j][i] == 'B' && !b[j][i])
            {
                c++;
                for(ll k=0; k<8; k++)
                    b[k][i] = true;
            }
        }
    }
    cout<<c;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}


#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define f(a,b) for(ll i=a; i<b; i++)
#define mod 1000000007

vector<ll> prime;
bool b[10001] = {false};
int dp[10001] = {0};


int main()
{
    #ifndef ONLINE_JUDGE
	  freopen("input.txt", "rt", stdin);
   	//freopen("output.txt", "wt", stdout);
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll q;
    cin>>q;
    while(q--)
    {
        int n, c=0, d=0;
        cin>>n;
        if(n<4 || n==5 || n==7 || n==11)
        {
            cout<<"-1\n"; continue;
        }
        if(n==4 || n==6 || n==9){cout<<"1\n"; continue;}
            c = n/4;
            if(n%4==1 || n%4==3) c--;
            cout<<c<<"\n";
    }

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

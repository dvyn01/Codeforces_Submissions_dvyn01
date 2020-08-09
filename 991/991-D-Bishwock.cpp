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
    a+='X'; b+='X';
    a ='X'+a; b='X'+b;
    ll c=0;
    f(0, a.length()-1)
    {
        if(a[i] == '0'){
            if(a[i-1]=='0' && b[i]=='0'){
                c++;
                a[i] = 'X'; a[i-1]='X'; b[i]='X';
                continue;
            }
            else if(b[i]=='0' && b[i-1]=='0'){
                c++;
                a[i] = 'X'; b[i-1]='X'; b[i]='X';
                continue;
            }
            else if(a[i+1]=='0' && b[i]=='0'){
                c++;
                a[i] = 'X'; a[i+1]='X'; b[i]='X';
                continue;
            }
            else if(b[i]=='0' && b[i+1]=='0'){
                c++;
                a[i] = 'X'; b[i+1]='X'; b[i]='X';
                continue;
            }
        }
    }
    cout<<c;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}


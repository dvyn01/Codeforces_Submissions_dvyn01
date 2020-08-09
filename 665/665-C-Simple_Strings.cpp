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

    string a;
    cin>>a;
    ll n = a.length();
    f(0, n)
    {
        if(a[i] == a[i+1])
        {
            ll k=0, j=i;
            while(j<n-1 && a[j] == a[j+1])
            {
                j++;
                k++;
            }
            k++;
            if(k%2)
            {
                j--;
                char c='a';
                while(c == a[i]) c++;
                for(ll p=j; p>i; p-=2)
                    a[p] = c;
                i += k-1;
            }
            else{
                char c = 'a';
                while(c==a[i] || (j!=n-1 && c==a[j+1])) c++;
                for(ll p=j; p>i; p-=2)
                    a[p] = c;
                i += k-1;
            }
        }
    }
    cout<<a;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}


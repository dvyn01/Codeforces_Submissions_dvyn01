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

typedef struct t{
    ll val = 0;
    t* a[2];
}trie;

trie* root;

void insert(ll x)
{
    trie* temp = root;
    fr(30, 0)
    {
        ll p = (x >> j) & 1;
        if(temp -> a[p] == NULL)
            temp -> a[p] = new trie();
        temp = temp -> a[p];
        temp -> val++;
    }
}

ll xorr(ll x)
{
    ll ans = 0;
    trie* temp = root;
    fr(30, 0)
    {
        ll p = (x >> j) & 1;
        ll q = p ^ 1;
        if(temp -> a[p] != NULL && temp -> a[p] -> val > 0){
            temp = temp -> a[p];
            temp -> val--;
        }
        else{
            temp = temp -> a[q];
            temp -> val--;
            ans += (1LL << j);
        }
    }
    return ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	// freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll n, x;
    root = new trie();
    cin>>n;
    ll a[n];
    f(0, n) cin>>a[i];
    f(0, n)
    {
        cin>>x;
        insert(x);
    }
    f(0, n)
        cout<<xorr(a[i])<<" ";

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}


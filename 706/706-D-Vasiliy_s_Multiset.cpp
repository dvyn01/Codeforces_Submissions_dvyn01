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
#define lld long double
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

void deletee(ll x)
{
    trie* temp = root;
    fr(30, 0)
    {
        ll p = (x >> j) & 1;
        temp = temp -> a[p];
        temp -> val--;
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
        if(temp -> a[q] != NULL && temp -> a[q] -> val > 0)
        {
            ans += (1LL) << j;
            temp = temp -> a[q];
        }
        else temp = temp -> a[p];
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

    ll q;
    cin>>q;
    root = new trie();
    insert(0);
    while(q--)
    {
        char c;
        ll k;
        cin>>c>>k;
        if(c == '+')
            insert(k);
        else if(c == '-')
            deletee(k);
        else
            cout<<xorr(k)<<"\n";
    }

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}


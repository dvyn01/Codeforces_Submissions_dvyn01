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
#define vll vector<ll>
#define pll vector<pair<ll,ll>>
#define ld long double
#define fr(a,b) for(ll j=a; j>=b; j--)
#define fi(a,b) for(ll j=a; j<b; j++)
#define fii(a,b) for(ll k=a; k<b; k++)
vll v[100050];
ll ans;

ll cnt(ll n)
{
    ll k=0, r=0;
    while((1<<k) <= n)
    {
        if((1<<k)&n)
            r++;
        k++;
    }
    return r;
}

ll fun(ll n, ll r)
{
    ll k=31, s=0;
    while(k>=0)
    {
        if((1<<k) & n)
        {
            if(s < r)
                s++;
            else {  n >>= (k+1);  ans+=k+1; break;}
        }
        k--;
    }
    return n;
}

void fun2(ll n, ll i)
{
    ll k = 31;
    while(!((1<<k)&n))
        k--;
    k--;
    ll r=0;
    while(k>= 0)
    {
        if((1<<k)&n)
        {   v[i].pb(r);    r=0; }
        else r++;
        k--;
    }
}

/*ll fun3(ll n, ll i)
{
    ll k = 31, c=0;
    while(k >= 0)
    {
        if(c==i+1)
        {
            ans+=k+1;
            n>>=k;
            break;
        }
        else if((1<<k)&n)
            c++;
    }
    return n;
}*/

ll fun4(ll n, ll b)
{
    if(n == b) return 0;
    ll r=0;
    while(n < b)
    {
        n<<=1;
        r++;
    }
    while(n > b)
    {
        n >>= 1;
        r++;
    }
    return r;
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

    ll n;
    cin>>n;
    ll a[n], m1=1e18;
    f(0, n)
    {
        cin>>a[i];
        m1 = min(m1, cnt(a[i]));
    }
    f(0, n) a[i] = fun(a[i], m1);
    f(0, n) fun2(a[i], i);
    ll ppp=0;
    bool ok = true;
    f(0, v[0].size())
    {
        ll kk = v[0][i];
        fi(1, n)
        {
            if(v[j][i] != kk)
            {
                ok = false;
                ppp = i;
                break;
            }
        }
        if(!ok) break;
    }
    if(!ok)
    {
        f(0, n) a[i] = fun(a[i], ppp+1);
    }
    ll gmn=1e18;
    fr(30, 0)
    {
        ll kk = (1<<j), mn=0;
        fii(0, n){
            mn += fun4(a[k]&(-1*a[k]), kk);
        }
        gmn = min(gmn, mn);
    }
    ans += gmn;
    cout<<ans;

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}

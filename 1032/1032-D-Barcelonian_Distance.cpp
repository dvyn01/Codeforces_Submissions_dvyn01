/*
          * AUTHOR : Divyanshu *
*/

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
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
typedef tree<ll ,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

struct pt{
    ld x, y;
};

ld dist(ld x1, ld y1, ld x2, ld y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
 //    freopen("output.txt", "wt", stdout); *Nope*
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ld a, b, c;
    cin>>a>>b>>c;
    ld x1, x2, y1, y2;
    cin>>x1>>y1>>x2>>y2;
    ld ans = 1e15;
    pt p1, p2, p3, p4;
    p1.y = y1;
    p1.x = (b * p1.y + c) / a * (-1.0);
    p2.x = x1;
    p2.y = (a * p2.x + c) / b * (-1.0);
    p3.y = y2;
    p3.x = (b * p3.y + c) / a * (-1.0);
    p4.x = x2;
    p4.y = (a * p4.x + c) / b * (-1.0);
    ld d1 = dist(x1, y1, p1.x, p1.y);
    ld d2 = dist(x1, y1, p2.x, p2.y);
    ld d3 = dist(x2, y2, p3.x, p3.y);
    ld d4 = dist(x2, y2, p4.x, p4.y);
    ld f1 = dist(p2.x, p2.y, p3.x, p3.y);
    ld f2 = dist(p2.x, p2.y, p4.x, p4.y);
    ld f3 = dist(p1.x, p1.y, p3.x, p3.y);
    ld f4 = dist(p1.x, p1.y, p4.x, p4.y);
    ans = abs(x1 - x2) + abs(y1 - y2);
    ans = min(ans, d2 + f1 + d3);
    ans = min(ans, d2 + f2 + d4);
    ans = min(ans, d1 + f3 + d3);
    ans = min(ans, d1 + f4 + d4);
    cout<<fixed<<setprecision(10)<<ans;

    #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
    return 0;
}


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

    ll n, m;
    vector<tuple<ll,ll,ll>> t;
    cin>>n>>m;
    bool b[n+2][m+2];
    memset(b, false, sizeof(b));
    string s[n+2], z;
    f(0, m+2) { s[0]+='.'; s[n+1]+='.';}
    f(1, n+1) {s[i]+='.'; cin>>z; s[i]+=z; s[i]+='.'; }
    f(2, n)
    {
        fi(2, m)
        {
            if(s[i][j]=='*')
            {
                ll p=0, k=1;
                while(s[i+k][j]=='*' && s[i-k][j]=='*' && s[i][j+k]=='*' && s[i][j-k]=='*')
                {
                    b[i][j]=true;   b[i+k][j]=true;   b[i-k][j]=true;   b[i][j+k]=true;   b[i][j-k]=true;
                    k++;
                    p++;
                }
                if(p>0)
                   t.pb(make_tuple(i, j, p));
            }
        }
    }
    bool ok = true;
    f(1, n+1)
    {
        fi(1, m+1){
            if(s[i][j]=='*' && !b[i][j])
            {
                ok = false;
                break;
            }
        }
        if(!ok) break;
    }
    if(!ok) cout<<-1;
    else{
        cout<<t.size()<<"\n";
        f(0, t.size())
            cout<<get<0>(t[i])<<" "<<get<1>(t[i])<<" "<<get<2>(t[i])<<"\n";
    }


     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}
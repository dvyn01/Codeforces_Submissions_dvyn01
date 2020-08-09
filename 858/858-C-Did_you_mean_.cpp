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

    string s;
    cin>>s;
    map<char, ll> m;
    m['a']++; m['e']++; m['i']++; m['o']++; m['u']++;
    f(0, s.length())
    {
        if(i==s.length()-1 || i==s.length()-2){cout<<s[i]; continue; }
        if(m[s[i]]){cout<<s[i]; continue;}
        if(m[s[i+1]] || m[s[i+2]]){cout<<s[i]; continue; }
        if(m[s[i]]==0 && m[s[i+1]]==0 && m[s[i+2]]==0)
        {
            ll k=i;
            while(k<s.length()-2 && !m[s[k+2]] && !m[s[k]] && !m[s[k+1]])
            {
                if(s[k]!=s[k+1] || s[k]!=s[k+2] || s[k+1]!=s[k+2])
                { cout<<s[k]<<s[k+1]<<" "; k+=2; continue; }
                char c = s[k];
                while(k<s.length() && s[k] == c)
                {
                    cout<<s[k];
                    k++;
                }
                if(k==s.length()) break;
                if(!m[s[k]]) cout<<" ";
            }
            i = k-1;
        }
    }

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}


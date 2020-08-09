//          * AUTHOR : Divyanshu *

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define f(a,b) for(ll i=a; i<b; i++)
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define vll vector<ll>;
#define pll vector<pair<ll,ll>>

int pal(string s)
{
    int l = 0;
    int h = s.length()-1;
    while (h > l)
    {
        if (s[l++] != s[h--])
        {
            return 0;
        }
    }
    return 1;
}


int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	//freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    string s;
    cin>>s;
    if(!pal(s))
        cout<<s.length();
    else
    {
        ll c=0;
        f(1,s.length())
            if(s[i] == s[i-1])
                c++;
        if(c==s.length()-1)
            cout<<"0\n";
        else cout<<s.length()-1;
    }

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

//          * AUTHOR : Divyanshu *

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define f(a,b) for(ll i=a; i<b; i++)
#define mod 1000000007

int main()
{
    #ifndef ONLINE_JUDGE
	   freopen("input.txt", "rt", stdin);
   	//freopen("output.txt", "wt", stdout); *No Need*
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    ll n,a,b, s=0, f=0;
    cin>>n>>a>>b;
    ll ar[n];
    if(a+b > n-1 || (n==2 && a>0) || (b==0 && a==n-1 && n>1))
    {
        cout<<"-1\n";
        f++;
    }
    if(f==0)
    {
        ar[0] = 1;
        s = 1;
        ll maxx = 1;
        f(1,n)
        {
            if(b != 0)
            {
                ar[i] = s+1;
                maxx = ar[i];
                b--;
            }
            else if(a != 0)
            {
                if(maxx+1 > s)
                    ar[i] = 1;
                else
                {ar[i] = maxx + 1;
                maxx = ar[i];
                a--;
                }
            }
            else ar[i] = 1;
            s += ar[i];
        }
        f(0,n) cout<<ar[i]<<" ";
    }

     #ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
}

#include<bits/stdc++.h>
using namespace std; 
#define ll long long
double pi=3.14159265359;
int main()
{
	int n,i;
	    ll r,h,s;
        cin>>n;
		map<ll,ll> m;
		m[0]=0;
		for(i=0;i<n;++i)
		{
			cin>>r>>h;
			s=r*r*h;
			map<ll,ll>::iterator left=m.lower_bound(s);
			map<ll,ll>::iterator right=left;
		    ll cnt=(--right)->second+s;
			right=left;
			for( ; right!= m.end() && right->second<=cnt; ++right);
			m.erase(left,right);
			m[s]=cnt;
		}
	    cout<<std::fixed<<setprecision(8)<<(--m.end())->second*pi; 
	return 0;
} 
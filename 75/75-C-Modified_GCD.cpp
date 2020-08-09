#include<bits/stdc++.h>
using namespace std;
#define ln "\n"

long long gcd(int a ,int b){
	if(a%b==0)
		return b;
	else
		return gcd(b,a%b);
}
int main(){

	long long a,b,l,h;
	cin>>a>>b;
	int q;	cin>>q;
	long long n = gcd(a,b);
	vector<long long> v;
	for(long long i=1; i<=sqrt(n); i++)
	{
	    if(n%i == 0){
	        long long p = n/i;
	        if(p != i){ v.push_back(i); v.push_back(p); }
	        else v.push_back(i);
	    }
	}
	sort(v.begin(), v.end());
	while(q--){
		cin>>l>>h;
		long long r = lower_bound(v.begin(), v.end(), h) - v.begin();
		if(r<v.size() && v[r] == h){
		    cout<<h<<"\n";
		    continue;
		}
		r -= 1;
	     if(v[r]>=l && v[r]<=h)
		    cout<<v[r]<<"\n";
		 else cout<<"-1\n";
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	int n;
	cin>>n;
	int a[n];
	for(int i = 0; i < n; i++) {
		cin>>a[i];
	}
	sort(a, a + n);
	if(a[n-2] + a[n-3] <= a[n-1]) {
		cout<<"NO";
		return 0;	
	} else {
		cout<<"YES\n";
		cout<<a[n-2]<<" ";
		for(int i = 0; i < n; i++) {
			if(i == n - 2) {
				continue;
			} else {
				cout<<a[i]<<" ";
			}
		}
	}
}
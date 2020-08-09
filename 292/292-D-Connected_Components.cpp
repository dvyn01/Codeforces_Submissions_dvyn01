#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int n,m,k,l,r,res;
vector<pii> neigh[505];
bool taken[505];
void move(int i){
	taken[i]=1;
	for(int j=0;j<neigh[i].size();j++){
		pii x=neigh[i][j];
		if((x.second<l || x.second>r ) && !taken[x.first])
			move(x.first);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		neigh[a].push_back(pii(b,i));
		neigh[b].push_back(pii(a,i));
    }
    scanf("%d",&k);
    while(k--){
    	scanf("%d%d",&l,&r);
    	fill(taken+1,taken+n+1,0);
    	res=0;
    	for(int i=1;i<=n;i++)
    		if(!taken[i]){
    			res++,move(i);
			}
			printf("%d\n",res);
	}
	return 0;	
}    
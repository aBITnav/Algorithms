#include<bits/stdc++.h>
using namespace std;
int n,x,y;
vector<int> g[10002],dis(10002);

void dfs(int x,int p){
	for(int i:g[x])	if(i!=p){
		dis[i]=dis[x]+1;
		dfs(i,x);
	}
}

signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,0);
	int mx=0,mxi;
	for(int i=1;i<=n;i++)
		if(dis[i]>=mx){
			mx=dis[i];
			mxi=i;
		}
	//cout<<dis[1]<<" "<<dis[2]<<" "<<dis[3]<<endl;
	for(int i=1;i<=n;i++) dis[i]=0;
	dfs(mxi,0);
	mx=0;
	for(int i=1;i<=n;i++)
		mx=max(mx,dis[i]);
	cout<<mx;
}





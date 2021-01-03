#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define fi first
#define se second
#define deb(x) cout << #x << "=" << x << endl
#define clr(x) memset(x, 0, sizeof(x))
#define rep(i,k,n) for(int i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
const int M=1e9+7,N=200100;

vector<int> g[N];
vector<vector<int>> up(N,vector<int> (20));

void dfs(int s,int p){
	up[s][0]=p;
	rep(i,1,20) up[s][i]=up[up[s][i-1]][i-1];
	for(int i:g[s]) if(i!=p) dfs(i,s); 
}

int par(int s,int k){
	for(int i=19;i>=0;i--)
		if(k>=(1ll<<i)) s=up[s][i],k-=(1ll<<i);
	return s;
}

signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,q,x;
	cin>>n>>q;
	rep(i,2,n+1){
		cin>>x;
		g[i].pb(x);
		g[x].pb(i);
	}
	dfs(1,0);
	while(q--){
		cin>>n>>x;
		if(!par(n,x)) cout<<"-1\n";
		else cout<<par(n,x)<<"\n";
	}
	
}





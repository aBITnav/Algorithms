#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define Fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
 
bool comp(pii a, pii b){
	return a.second > b.second;
}
 
void countDfs(vector<int> tree[], vi &count, vi &visited, int node, int n)
{
	visited[node] = 1;
	for(int i=0;i<tree[node].size();i++){
		if(visited[tree[node][i]] == 0){
			countDfs(tree, count, visited, tree[node][i], n);
			count[node] += (count[tree[node][i]]+1);
		}
	}
}
 
void dfs(vector<int> tree[], vi &isTourist, vi &visited, int node, int n, int d,vi &dep, int noOfTourAbove, vi &tourArr){
	visited[node] = 1;
	dep[node] = d;
	tourArr[node] = noOfTourAbove;
 
	for(int i=0;i<tree[node].size();i++){
		if(visited[tree[node][i]] == 0){
			// if(isTourist[tree[node][i]] == 0){
				int t = noOfTourAbove;
				if(isTourist[node]) ++t;
				dfs(tree, isTourist, visited, tree[node][i], n, d+1, dep, t, tourArr);
				dep[tree[node][i]] = d+1;	
			// }
		}
	}
}
 
int main(){
	Fastio
	int n,k;cin>>n>>k;
 
	vector<int> tree[n+1];
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		tree[u].pb(v);
		tree[v].pb(u);
	}
 
	int x = n-k;
 
	 vi count(n+1,0);
	 vi visited(n+1,0);
 
 
	 countDfs(tree, count, visited, 1, n);
 
 
 
	 vector<pii> arr;
	 for(int i=1;i<=n;i++){
	 	arr.pb(make_pair(i,count[i]));
	 }
	 sort(arr.begin(), arr.end(), comp);
 
 
	 vector<int> isTourist(n+1);
	 for(int i=0;i<x;i++){
	 	isTourist[arr[i].first] = 1;
	 }
 
	 visited.clear();
	 visited.assign(n+1,0);
	 vi dep(n+1,0);
	 vi tourArr(n+1,0);
	 dfs(tree, isTourist, visited, 1, n, 0, dep, 0, tourArr);
 
	 // for(int i=1;i<=n;i++){
	 // 	cout<<dep[i]<<" ";
	 // }cout<<endl;
 
 
	 ll ans = 0;
	 for(int i=1;i<=n;i++){
	 	if(isTourist[i] == 0){
	 		ans += tourArr[i];
	 	}
	 }
	 cout<<ans<<"\n";
 
	return 0;
}

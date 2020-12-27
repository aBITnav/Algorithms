#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,k,n) for(int i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)

int query(vector<vector<int>>&bit,int i,int j){
	int x=0;
	for(;i>0;i-=i&-i) for(;j>0;j-=j&-j)	x+=bit[i][j];
	return x;
}

void update(vector<vector<int>>&bit,int l,int i,int j,int x){
	for(;i<l;i+=i&-i) for(;j<l;j+=j&-j)  bit[i][j]+=x;
}


signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,i,j,x,y,p;
		cin>>n;
		n++;
		vector<vector<int>> bit(n,vector<int> (n,0));
		while(1){
			string in;
			cin>>in;
			if(in=="END") break;
			else if(in=="SET"){
				cin>>i>>j>>x;
				update(bit,n,i+1,j+1,x);
			}
			else{
				cin>>x>>y>>i>>j;
				int ans=query(bit,i+1,j+1)+query(bit,x,y)-query(bit,x,j+1)-query(bit,i+1,y);
				cout<<ans<<"\n";
			} 	
		}
	}
}





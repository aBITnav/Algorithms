#include<bits/stdc++.h>
using namespace std;


signed main(){
	int f[]={1,2,3,4,5,6};
	int s,d;
	cin>>s>>d;
	vector<vector<int> > dp(d+1,vector<int> (s+1,0));
	dp[0][0]=1;
	for(int k=1;k<=d;k++){
		for(int i:f)
			for(int j=i;j<=s;j++)
				dp[k][j]+=dp[k-1][j-i];
		//for(int i=1;i<=s;i++) cout<<i<<" "<<dp[i]<<endl;
		}
	
	cout<<dp[d][s];
}




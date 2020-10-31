#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(i=0;i<n;i++)
#define pb push_back
#define all(a) a.begin(),a.end()
#define fi first
#define se second
int M=1e9+7;
int mm(int x,int y){x%=M,y%=M;return (x*y)%M;}//Modular Multiply
int po(int x,int y){ if(!y)return 1;int a=po(x,y/2)%M;if(y%2)return mm(a,mm(a,x));return mm(a,a);}//(x**y)%M

signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,s,mx=0;
	cin>>n>>s;
	int w[n],dp[s+1]={},v[n];
	for(int i=0;i<n;i++) cin>>w[i]>>v[i];
	for(int i=0;i<n;i++)
		for(int j=s;j>=w[i];j--) 
			dp[j]=max(dp[j-1],dp[j-w[i]]+v[i]);
	cout<<dp[s];
	for(int i:dp) mx=max(mx,i);
	//cout<<mx;
}

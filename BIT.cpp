#include<bits/stdc++.h>
using namespace std;
string bin(int n){
	string s;
	while(n){
		s+=n%2+'0';
		n/=2;
	}
	reverse(s.begin(),s.end());
	return s;
}

signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int m,n;
	cin>>n;
	vector<int> v;
	int c=0;
	while(n&(n+1)){
		c++;
		if(c%2){
			string s=bin(n);
			int i=0;
			while(s[i]=='1') i++;
			i=s.size()-i;
			n=n^((1<<i)-1);
			v.push_back(i);
		}
		else n++;
	}
	cout<<c<<"\n";
	for(int i:v) cout<<i<<" ";
	
	
}





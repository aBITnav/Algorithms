#include<bits/stdc++.h>
using namespace std;

int main(){

int n,k;
cin>>n>>k;
int a[n];
for(int i=0;i<n;i++) cin>>a[i];

for(int i=0;i<(1<<n);i++)
{
vector<int> v;
int sum=0;
for(int j=0;j<n;j++)

if(i&1<<j) {v.push_back(a[j]);
sum+=a[j];
	if(sum>k) break;

}
if(sum==k){
for(int p=0;p<v.size();p++) cout<<v[p]<<" ";
cout<<endl;
}
}
}



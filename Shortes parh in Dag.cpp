#include<bits/stdc++.h>
using namespace std;
int dag[1000][1000];
vector<int>ts;
vector<bool>b;
void toposort(int i,int n){
b[i]=false;
for(int j=0;j<n;j++){
if(b[j]&&a[i][j]!=-1)toposort(j,n);
}
ts.push_back(i);
}


int main(){
int n;
cin>>n;
int dist[n];

for(int i=0;i<n;i++){
dist[i]=10000000;
for(int j=0;j<n;j++){
cin>>a[i][j];
}
}
b.assign(n,true);
toposort(0,n);
reverse(ts.begin(),ts.end());

dist[0]=0;
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
if(dag[ts[i]][j]!=-1)
dist[j]=min(dist[j],dist[ts[i]]+dag[ts[i]][j]);
}
}
for(int i=0;i<n;i++){
cout<<dist[i]<<" ";}

return 0;
}

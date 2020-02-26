#include<iostream>
using namespace std;

int main(){

int n;
cout<<"Enter the distance matrix"<<endl;
cin>>n;
int g[n][n];
for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
cin>>g[i][j];

for(int k=0;k<n;k++)
for(int i=0;i<n;i++)
for(int j=0;j<n;j++)
g[i][j]=min(g[i][j],g[i][k]+g[k][j]);

for(int i=0;i<n;i++)



{
for(int j=0;j<n;j++)
cout<<g[i][j]<<" ";
cout<<endl;
}
}

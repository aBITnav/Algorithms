#include<bits/stdc++.h>
using namespace std;

int main(){

vector <int> v [2000];
    int dis [1000];
    int m,from,next,weight;
    cin>>m;

    for(int i = 0; i < m + 2; i++){
        v[i].clear();
        dis[i] = 2e9;}

   for(int i = 0; i < m; i++){
        cin>>from>>next>>weight;
        v[i].push_back(from);
        v[i].push_back(next);
        v[i].push_back(weight); }
    dis[0] = 0;
    for(int i = 0; i < m - 1; i++){
        int j = 0;
        while(v[j].size() != 0){
        	dis[v[j][1]]=min(dis[v[j][1]],dis[v[j][0]]+v[j][2]);
            j++;
        }   }
	 for(int i=0;i<m;i++) cout<<dis[i]<<" ";
	}

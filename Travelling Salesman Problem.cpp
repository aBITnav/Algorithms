#include <bits/stdc++.h> 
using namespace std; 
int V;
int graph[50][50];
  
int tsp(int s) 
{ 
    vector<int> vertex; 
    for (int i = 0; i < V; i++) 
            vertex.push_back(i); 
  
    int min_path = INT_MAX; 
    do { 
        int weight = 0; 
        int k = s; 
        for (int i = 0; i < vertex.size(); i++) { 
            weight += graph[k][vertex[i]]; 
            k = vertex[i]; 
        } 
        weight += graph[k][s]; 
  
        min_path = min(min_path, weight); 
         
    } while (next_permutation(vertex.begin(), vertex.end())); 
  
    return min_path; 
} 
int main() 
{   cout<<"Enter Number of vertex\n";
	cin>>V;
	cout<<"Enter the distance Matrix\n";
	for(int i=0;i<V;i++)
		for(int j=0;j<V;j++)
			cin>>graph[i][j];
    /*int graph[][V] = { { 0, 10, 15, 20 }, 
                       { 10, 0, 35, 25 }, 
                       { 15, 35, 0, 30 }, 
                       { 20, 25, 30, 0 } }; */
    int s = 0; 
    cout << tsp(s) << endl; 
    return 0; 
} 

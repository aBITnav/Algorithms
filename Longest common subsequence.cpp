#include <bits/stdc++.h>

using namespace std;
int di[100][100];
string s;
void lcs(string x,string y,int m,int n,int l){
    if(di[m][n]>=1&&l>=0){
        if(di[m][n]==7){
            s[l-1]=x[m-1];
            m=m-1;n=n-1;
            l=l-1;
        }
        else if(di[m][n]==4)
            n=n-1;
        else if(di[m][n]==8)
            m=m-1;
        lcs(x,y,m,n,l);
    }
}

int main() {
	string x,y,r;
	cin>>x>>y;
	int m=x.size(),n=y.size();
	int c[m+1][n+1];
	
	for(int i=0;i<=m;i++){
	    c[i][0]=0;
	    di[i][0]=0;
	}
	for(int i=1;i<=n;i++){
	    c[0][i]=0;
	    di[0][i]=0;
	}
	    
	for(int i=1;i<=m;i++){
	    for(int j=1;j<=n;j++){
	        if(x[i-1]==y[j-1]){
	            c[i][j]=c[i-1][j-1]+1;
	            di[i][j]=7;
	        }
	        else if(c[i-1][j]>=c[i][j-1]){
	            c[i][j]=c[i-1][j];
	            di[i][j]=8;
	        }
	        else{
	            c[i][j]=c[i][j-1];
	            di[i][j]=4;
	        }
	    }
	}
	
    s.resize(c[m][n]);
	lcs(x,y,m,n,c[m][n]);
	cout<<c[m][n]<<endl;
	cout<<s;
}

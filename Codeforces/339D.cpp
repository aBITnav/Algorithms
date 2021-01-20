#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define all(a) a.begin(),a.end()
#define fi first
#define se second
#define deb(x) cout << #x << "=" << x << endl
#define clr(x) memset(x, 0, sizeof(x))
#define rep(i,k,n) for(int i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
const int M=1e9+7,N=140000;

int mm(int x,int y){x%=M,y%=M;return (x*y)%M;}//Modular Multiply
int po(int x,int y){ if(!y)return 1;int a=po(x,y/2)%M;if(y%2)return mm(a,mm(a,x));return mm(a,a);}//(x**y)%M


int tree[4*N],a[N];

void build(int n,int tl,int tr,bool op){
	if(tl==tr) {
		tree[n]=a[tl];
		return;
	}
	int tm=(tl+tr)/2;
	build(2*n,tl,tm,!op);
	build(2*n+1,tm+1,tr,!op);
	if(op)	tree[n]=tree[2*n]|tree[2*n+1];
	else 	tree[n]=tree[2*n]^tree[2*n+1];
}


void update(int n,int tl,int tr,int pos,int x,bool op){
	if(tl==tr){
		tree[n]=x;
		return;
	}
	int tm=(tl+tr)/2;
	if(pos<=tm)
		update(2*n,tl,tm,pos,x,!op);
	if(pos>tm)
		update(2*n+1,tm+1,tr,pos,x,!op);
	if(op)	tree[n]=tree[2*n]|tree[2*n+1];
	else 	tree[n]=tree[2*n]^tree[2*n+1];
}

signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,q,l,r;
	cin>>n>>q;
	int p=n;
	n=(1<<n);
	rep(i,1,n+1) cin>>a[i];
	build(1,1,n,p%2);
	while(q--){
		cin>>l>>r;
		a[l]=r;
		update(1,1,n,l,r,p%2);
		cout<<tree[1]<<"\n";
		//rep(i,1,n+1) cout<<tree[i]<<" ";cout<<"\n";
	}
}

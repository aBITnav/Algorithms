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
const int M=1e9+7,N=205001;

int mm(int x,int y){x%=M,y%=M;return (x*y)%M;}//Modular Multiply
int po(int x,int y){ if(!y)return 1;int a=po(x,y/2)%M;if(y%2)return mm(a,mm(a,x));return mm(a,a);}//(x**y)%M


int tree[4*N],a[N];

void build(int n,int tl,int tr){
	if(tl==tr) {
		tree[n]=a[tl];
		return;
	}
	int tm=(tl+tr)/2;
	build(2*n,tl,tm);
	build(2*n+1,tm+1,tr);
	tree[n]=min(tree[2*n],tree[2*n+1]);
}

int query(int n,int tl,int tr,int l,int r){
	if(l>r) return 0;
	if(tl==l and tr==r) return tree[n];
	int tm=(tl+tr)/2;
	int al=query(2*n,tl,tm,l,min(r,tm));
	int ar=query(2*n+1,tm+1,tr,max(l,tm+1),r);
	return min(al,ar);
}

void update(int n,int tl,int tr,int pos,int x){
	if(tl==tr){
		tree[n]=x;
		return;
	}
	int tm=(tl+tr)/2;
	if(pos<=tm)
		update(2*n,tl,tm,pos,x);
	if(pos>tm)
		update(2*n+1,tm+1,tr,pos,x);
	tree[n]=min(tree[2*n],tree[2*n+1]);
}

signed main(){
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,q;
	string s;
	cin>>n;
	rep(i,1,n+1) cin>>a[i];
	build(1,1,n);
	cin>>q;
	getline(cin,s);
	rep(i,0,q){
		getline(cin,s);
		int b1=s.find(' ');
		int b2=s.find(' ',b1+1);
		if(b2!=-1){
			int l=stoll(s.substr(0,b1));
			int r=stoll(s.substr(b1+1,b2-b1));
			int x=stoll(s.substr(b2+1));
			cout<<l<<" "<<r<<" "<<x<<endl;
		}
		else{
			int l=stoll(s.substr(0,b1));
			int r=stoll(s.substr(b1+1));
			cout<<l<<" "<<r<<endl;
		}
		//cin>>l>>r;
		//if(c==2)	cout<<query(1,1,n,l,r)<<"\n";
		//else update(1,1,n,l,r);
	}
}





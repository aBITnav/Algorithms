#include<bits/stdc++.h>
using namespace std;

struct node{
	node* next[26];
	bool nd;
	node(){
		memset(next,0,sizeof(next));
		nd=0;
	}
};


void insert(node* p,string s){
	for(int i:s){
		i-='a';
		if(!p->next[i])
			p->next[i]=new node(); 
		p=p->next[i];
	}
	p->nd=true;
}

void print(node* start,string &s){
	if(start->nd)
		cout<<s<<"\n";
	for(int i=0;i<26;i++)
		if(start->next[i]){
			s+='a'+i;
			print(start->next[i],s);
			s.pop_back();
		}
}

bool find(node* p,string s){
	for(int i:s){
		i-='a';
		if(!p->next[i])
			return false;
		p=p->next[i];
	}
	string t;
	print(p,t);
	return p->nd;
}



int main(){
	
	node* head=new node;			
	string keys[] = { };
	for(int i=0;i<15;i++) insert(head,keys[i]);
	string s;
	cin>>s;
	find(head,s);
	
	
}





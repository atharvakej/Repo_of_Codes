#include<bits/stdc++.h>
using namespace std;

struct Tree{
	string name;
	Tree* head;
	vector<Tree*> childrens;
	bool islocked;
	set<Tree*> bottom;
	int locked;
	
	Tree(string n,Tree*m){
		name=n;
		locked=-1;
		head=m;
		islocked=false;
	}
	void add(vector<string> & str){
		for(string &it:str){
			childrens.push_back(new Tree(it,this));
		}
	}
};

struct Tree2{
	Tree* val;
	unordered_map<string, Tree*> mp;
	Tree2(string str){
		val=new Tree(str,nullptr);
	}
	void buildTree(vector<string>& str,int n){
		queue<Tree*> q;
		int k=1,i,size=str.size();
		q.push(val);

		while(!q.empty()){
			Tree* r=q.front();
			q.pop();
			mp[r->name]=r;
			vector<string>b;
			for(i=k;i<min(size,k+n);i++){
				b.push_back(str[i]);
			}
			r->add(b);
			for(Tree* child : r->childrens){
				q.push(child);
			}
			k=i;
		}
	}

	void update(Tree* r, Tree* current){
		while(r){
			r->bottom.insert(current);
			r=r->head;
		}
	}


	bool lock(string name, int id){
		Tree* r=mp[name];
		if(r->islocked or r->bottom.size()) return false;
		Tree* par =r->head;
		while(par){
			if(par->islocked) return false;
			par=par->head;
		}
		update(r->head,r);
		r->islocked=true;
		r->locked=id;
		return true;
	}

	bool upgrade(string name, int id){
		Tree* r=mp[name];
		if(r->islocked or r->bottom.size()==0) return false;
		for(Tree* it: r->bottom){
			if(it->locked!=id) return false;
		}
		Tree* par =r->head;
		while(par){
			if(par->islocked) return false;
			par=par->head;
		}
		set<Tree* > st= r->bottom;
		for(Tree* it: st){
			unlock(it->name,id);
		}
		lock(name,id);
		return true;
	}

	bool unlock(string name, int id){
		Tree* r=mp[name];
		if(!r->islocked or r->locked!=id) return false;
		
		Tree* par =r->head;
		while(par){
			par->bottom.erase(r);
			par=par->head;
		}
		r->islocked=false;
		r->locked=1;
		return true;
	}

	

};


int main(){
	int size,m,testcases,i,type,id;
	string name;
	cin>>size>>m>>testcases;
	vector<string> a(size);
	for(int i=0;i<size;i++){
		cin>>a[i];
	}
	Tree2* tree=new Tree2(a[0]);
	tree->buildTree(a,m);
	while(testcases--){
		cin>>type>>name>>id;
		if(type==1){
			if(tree->lock(name,id)){
				cout<<"true";
			}
			else{
				cout<<"false";
			}
		}
		else if(type==2){
			if(tree->unlock(name,id)) cout<<"true";
			else cout<<"false";
		}
		else if(type==3){
			if(tree->upgrade(name,id)) {
				cout<<"true";
			}
			else cout<<"false";
		}
		cout<<"\n";
	}
}
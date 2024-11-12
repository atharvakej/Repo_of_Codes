#include<bits/stdc++.h>
using namespace std;

class Tree{
    public:
	string name;
	Tree* parent;
	int locker;
	bool islocked;
	vector<Tree*> child;
	unordered_set<Tree*> lowers;
	
	Tree(string str,Tree*Parent){
		locker = -1;
		parent=Parent;
		name=str;
		islocked=0;
	}


	void add(vector<string> & str){
		for(string &it:str){
            Tree* temp = new Tree(it,this);
			child.push_back(temp);
		}
	}
};

class ParentTree{
    public:
	Tree* val;
	unordered_map<string, Tree*> mp;
	ParentTree(string str){
		val= new Tree(str,nullptr);
	}
	void buildTree(vector<string>& str,int n){
		queue<Tree*> q;
		int idx=1,i,size=str.size();
		q.push(val);
		while(!q.empty()){
			Tree* r =q.front();
			q.pop();
			mp[r->name]=r;
			vector<string>b;
			for(i=idx;i<min(size,idx+n);i++){
				b.push_back(str[i]);
			}
			r->add(b);
			for(Tree* child : r->child){
				q.push(child);
			}
			idx=i;
		}
	}

	void storechild(Tree* r, Tree* current){
		while(r){
			r->lowers.insert(current);
            //cout<<r->name<<" "<<current->name<<endl;
			r=r->parent;
		}
	}


	bool lock(string name, int id){
		Tree* r=mp[name];
		if(r->islocked || r->lowers.size()) return 0;
		Tree* par =r->parent;
		while(par!=nullptr){
			if(par->islocked) return 0;
			par=par->parent;
		}
		r->islocked=1;
		r->locker=id;
		storechild(r->parent,r);
		return 1;
	}

	bool upgrade(string name, int id){
		Tree* r=mp[name];
		if(r->islocked || r->lowers.size()==0) return 0;
		for(Tree* it: r->lowers){
			if(it->locker!=id) return 0;
		}
		Tree* par =r->parent;
		while(par){
			if(par->islocked) return 0;
			par=par->parent;
		}
		unordered_set<Tree*> st;

        for(auto it:r->lowers){
            st.insert(it);
        }
		for(Tree* it: st){
			unlock(it->name,id);
		}
		lock(name,id);
		return 1;
	}

	bool unlock(string name, int id){
		Tree* r=mp[name];
		if(!r->islocked || r->locker!=id) return 0;
		
		Tree* par =r->parent;
		while(par){
			par->lowers.erase(r);
			par=par->parent;
		}
		r->islocked=0;
		r->locker=1;
		return 1;
	}

	

};


int main(){
	int size,m,tt;
	cin>>size>>m>>tt;
	vector<string> a(size);
	for(int i=0;i<size;i++){
		cin>>a[i];
	}
	ParentTree* tree=new ParentTree(a[0]);
	tree->buildTree(a,m);
	while(tt--){
        int type,id;
        string name;
		cin>>type>>name>>id;
		if(type==1){
			if(tree->lock(name,id)){
				cout<<"true";
			}
			else cout<<"false";
		}
		else if(type==2){
			if(tree->unlock(name,id)) cout<<"true";
			else cout<<"false";
		}
		else{
			if(tree->upgrade(name,id)) {
				cout<<"true";
			}
			else cout<<"false";
		}
		cout<<endl;
	}
}
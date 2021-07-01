#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node{
    char s;
    vector<pair<node*, int>> k;
    node(char a){
        s = a;
    }

};

class graph{

  vector<node*> g;

  public:
    void insert(char from, char to, int w){
        if(g.empty()){
            node* f = new node(from);
            node* t = new node(to);
            pair<node*, int> a;
            a.first = t;
            a.second = w;
            (f->k).push_back(a);
            g.push_back(f);
            g.push_back(t);
            return;
        }

        vector<node*>::iterator it = g.begin();
        node* f = NULL;
        node* t = NULL;
        while(it != g.end()){
            if((*it)->s == from){
                f = (*it);
            }
            if((*it)->s == to){
                t = (*it);
            }
            it++;
        }

        bool x = false, y = false;
        if(f==NULL){
            f = new node(from);
            x = true;
        }
        if(t == NULL){
            t = new node(to);
            y = true;
        }
        pair<node*, int> a;
        a.first = t;
        a.second = w;
        (f->k).push_back(a);
        if(x) g.push_back(f);
        if(y) g.push_back(t);
        return;
    }

    void display(){
        if(g.empty()) return;

        vector<node*>::iterator it = g.begin();
        while(it != g.end()){
            cout<<(*it)->s<<"->";
            vector<pair<node*, int>>::iterator iter = ((*it)->k).begin();
            while(iter != ((*it)->k).end()){
                cout<<(iter->first)->s<<"->";
                iter++;
            }
            cout<<endl;
            it++;
        }
        return;
    }

    vector<char> bfs(char from, char to){
        vector<char> ans;
        node* f = NULL;
        node* t = NULL;
        vector<node*>::iterator it = g.begin();
        while(it != g.end()){
            if((*it)->s == from){
                f = (*it);
            }
            if((*it)->s == to){
                t = (*it);
            }
            it++;
        }
        if(f == NULL || t == NULL) return ans;

        vector<node*> q;
        q.push_back(f);

        bool visited[128];
        memset(visited, false, sizeof(visited));

        visited[f->s] = true;

        node* parent[128];

        for(int i = 0; i < 128; i++) parent[i] = NULL;

        while(!q.empty()){
            node* cur = q.front();
            q.erase(q.begin());
            vector<pair<node*, int>>::iterator it = (cur->k).begin();

            while(it != (cur->k).end()){
                if(!visited[(it->first)->s]){
                    visited[(it->first)->s] = true;
                    q.push_back(it->first);
                    parent[(it->first)->s] = cur;
                }
                it++;
            }
        }

        if(parent[to] == NULL) return ans;

        ans.insert(ans.begin(), to);
        char x  = to;
        while(x != from){
            ans.insert(ans.begin(), parent[x]->s);
            x = parent[x]->s;
        }
        cout<<endl;
        return ans;
    }


};


int main(){
    graph x;
    x.insert('a','b',2);
    x.insert('c','d',5);
    x.insert('a','c',3);
    x.insert('a','d',1);
    x.insert('e','a',1);
    x.insert('e','f',1);
    x.insert('f','g',1);
    x.insert('f','d',1);
    x.insert('f','c',1);
    x.insert('g','e',1);
    x.insert('g','c',1);
    x.insert('h','a',1);
    x.display();
    vector<char> f = x.bfs('a', 'd');

    vector<char>::iterator it = f.begin();
    while( it != f.end()){
        cout<<*it<<" ";
        it++;
    }
}

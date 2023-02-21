#include<bits/stdc++.h>
using namespace std;
const int N= 1e5+10;

vector<pair<int,int>> g[N];
vector<int> dist(N,INT_MAX);
int ver,edge;

int bfs(){
    deque<int> dqu;
    dqu.push_back(1);
    dist[1]=0;

    while(!dqu.empty()){
        int dis= dqu.front();
        dqu.pop_front();

        for(auto child : g[dis]){
            int child_n= child.first;
            int wt= child.second;

            if(dist[dis] + wt < dist[child_n]){
                dist[child_n]= dist[dis] + wt;

                if(wt==1){
                    dqu.push_back(child_n);
                }
                else{
                    dqu.push_front(child_n);
                }
            }
        }
    }

    return dist[ver]==INT_MAX? -1: dist[ver];
}

int main(){
    
    cout<<"Enter the vertices and edges: ";
    cin>>ver>>edge;

    for(int i=0; i<edge; i++){
        int x, y;
        cin>>x>>y;
        if(x==y) continue;

        g[x].push_back({y,0});
        g[y].push_back({x,1});

    }
    cout<<bfs();
}
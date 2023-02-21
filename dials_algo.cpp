#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m;
vector<pair<int,int>> g[N];

void dial(int src, int w){
    vector<pair<int,list<int>::iterator>> dist(n);
    
    for(int i=0; i<n; i++){
        dist[i].first = INT_MAX;
    }

    list<int> B[w*n +1];

    B[0].push_back(src);
    dist[src].first=0;

    int idx=0;
    while(1){
        while(B[idx].size()==0 && idx<w*n)
            idx++;

        if(idx==w*n)
            break;
        
        int u= B[idx].front();
        B[idx].pop_front();

        for(auto it: g[u]){
            int v= it.first;
            int wt= it.second;
             
             
            if(dist[u].first + wt < dist[v].first){

                if(dist[v].first != INT_MAX)
                    B[dist[v].first].erase(dist[v].second);
                
                dist[v].first= dist[u].first+ wt;

                B[dist[v].first].push_front(v);

                dist[v].second= B[dist[v].first].begin();
            }
        }
    }

    printf("Vertex Distance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d     %d\n", i, dist[i].first);
}    

int main(){
    
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int x,y,wt;
        cin>> x >>y >> wt;

        g[x].push_back({y,wt});
        g[y].push_back({x,wt});
    }

    dial(0,14);
}
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int INF=1e9+10;

vector<pair<int,int>> g[N];
  
void dijkstra(int source)
{
   // vector<int> vis(N,0);
    vector<int> dist(N,INF);

    set<pair<int,int>> st;

    st.insert({0,source});
    dist[source]=0;

    while(st.size()>0)
    {
        auto node= *st.begin();
        int dist_v=node.first;
        int v=node.second;

        st.erase(st.begin());

        // if(vis[v])  continue;

        // vis[v]=1;

        for(auto child: g[v])
        {
            int child_v=child.first;
            int wt= child.second;
            if(dist[v]+wt < dist[child_v]){
                dist[child_v]=dist[v]+wt;
                st.insert({dist[child_v],child_v});
            }
        }
    }
    int des;
    cin>>des;
    cout<<"path: "<<dist[des];

}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y,wt;
        cin>> x >> y >> wt;
        g[x].push_back({y,wt});
    } 
    dijkstra(1);
    
}


// // Strivers solution------gfg problem

// class Solution
// {
// 	public:
// 	//Function to find the shortest distance of all the vertices
//     //from the source vertex S.
//     vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
//     {
//     // Using priority queue    
        
//         // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
//         // vector<int> dist(V,INT_MAX);
//         // dist[S]=0;
        
//         // pq.push({0,S});
        
//         // while(!pq.empty()){
//         //     int dis= pq.top().first;
//         //     int node= pq.top().second;
//         //     pq.pop();
            
//         //     for(auto it: adj[node]){
//         //         int nodedist= it[1];
//         //         int nodeele= it[0];
                
//         //         if(dis + nodedist< dist[nodeele]){
//         //             dist[nodeele]=dis+nodedist;
//         //             pq.push({dist[nodeele],nodeele});
//         //         }
//         //     }
//         // }
//         // return dist;
        
        
//     //---------------------------------------------------------------------------
    
//     // Using set
    
//         set<pair<int,int>> s;
//         vector<int> dist(V,INT_MAX);
        
//         s.insert({0,S});
//         dist[S]=0;
        
//         while(!s.empty()){
//             auto it= *(s.begin());
//             int dis= it.first;
//             int node= it.second;
//             s.erase(it);
            
//             for(auto it: adj[node]){
//                 int nodedist= it[1];
//                 int nodeele= it[0];
                
//                 if(dis+nodedist < dist[nodeele]){
//                     if(dist[nodeele]!=INT_MAX){
//                         s.erase({dist[nodeele], nodeele});
//                     }
                    
//                     dist[nodeele]= dis+ nodedist;
//                     s.insert({dist[nodeele],nodeele});
                    
//                 }
//             }
//         }
//         return dist;
//     }
// };

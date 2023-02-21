// #include<bits/stdc++.h>
// using namespace std;

// const int N=1e5+10;
// vector<int> g[N];

// int vis[N];
// int level[N];

// void bfs(int source)
// {
//     queue<int> q;
//     q.push(source);
//     vis[source]=1;

//     while(!q.empty())
//     {
//         int curr=q.front();
//         q.pop();
//         cout<<curr<<" ";
//         for(int child: g[curr]){
//             if(!vis[child])
//             {
//                 q.push(child);
//                 vis[child]=1;
//                 level[child]=level[curr]+1;
//             }
//         }
//     }
//     cout<<endl;
// }

// int main()
// {
//     int n;
//     cin>>n;

//     for(int i=0;i<n-1;i++)
//     {
//         int x,y;
//         cin>>x>>y;

//         g[x].push_back(y);
//         g[y].push_back(x);
//     }
//     bfs(1);
//     for(int i=1;i<=n;i++)
//     {
//         cout<<i<<" : "<<level[i]<<endl;
//     }
    
// }

#include<bits/stdc++.h>
using namespace std;

const int N= 1e5+10;
int vis[N];
int level[N];
vector<int> graph[N];

void bfs(int source){
    queue<int> q;
    q.push(source);
    vis[source]=1;

    while(!q.empty()){
        int curr= q.front();
        q.pop();
        cout<<curr<<" ";

        for(int child: graph[curr]){
            if(!vis[child]){
                q.push(child);
                vis[child]=1;
                level[child]= level[curr]+1;
            }
        }
    }
} 

int main(){
    int ver, edge;
    cout<<"Enter the edges and vertices: ";
    cin>>ver>>edge;

    cout<<"Enter the graph: ";

    for(int i=0; i<edge; i++){
        int x,y;
        cin>>x>>y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    cout<<"The output is: \n";
    bfs(1);

    for(int i=1; i<=ver; i++){
        cout<<i<<" : "<<level[i]<<endl;
    }

}

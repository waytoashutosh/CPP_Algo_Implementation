#include<bits/stdc++.h>
using namespace std;
#define INF 2e9+7
int n;
vector<int> dist;
vector<bool> processed;

void dijkstra( vector<pair<int,int>> adj[], int v)
{
    priority_queue<pair<int,int>> q;

    for(int i=0; i<n; i++)
    {
        dist[i]=INF;
    }

    dist[v]=0;
    q.push({0,v});

    while(!q.empty())
    {
        
        int node = (q.top()).second;
        
        q.pop();

        if(processed[node]) continue;  
        processed[node]=true;      

        for(auto e: adj[node])
        {
            int next = e.first;
            int w = e.second;

            if(dist[node]+ w < dist[next] )
            {
                
                dist[next] = dist[node] + w;
                q.push({-dist[next] , next});
            }

            
        }   
    }
    
}

int main()
{
    

    //Single source shortest path
    cout<<"Enter the number of nodes : ";
    cin>>n;
    
    dist.resize(n);
    processed.resize(n);

    vector<pair<int,int>> adj[n];

    int x,w, y;
    for(int i=0; i<n; i++)
    {
        cout<<"Enter number of connections to "<<i<<" th node : ";
        cin>>y;

        while(y--)
        {
            
            cout<<i<<" -> x, w ? ";
            cin>>x>>w;
            adj[i].push_back({x,w});
            adj[x].push_back({i,w});

        }
    }

    int v; 
    cout<<"\nEnter the source vertex :  ";
    cin>>v; 

    dijkstra(adj,v);

    for(int i=0; i<n; i++)
    {
        cout<<v<<" -> "<<i<<" = "<<dist[i]<<"\n";
    }

    return 0;
}
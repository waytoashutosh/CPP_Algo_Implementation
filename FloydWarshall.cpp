#include<bits/stdc++.h>
using namespace std;
#define INF 1e9+7;

int main()
{
    //All Pair Shortest Path Floyd Warshall Algorithm O(n^3)

    int n;
    cout<<"Enter the number of nodes : ";
    cin>>n;

    vector<vector<int>> distance(n, vector<int> (n));

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

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n ;j++)
        {
            distance[i][j]=INF;
            
        }
    }


    for(int i = 0; i<n; i++)
    {
        for(auto x: adj[i])
        {
            distance[i][x.first] = x.second;
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n ;j++)
        {
            if(i==j)
            {
                distance[i][j]=0;
            }
            
        }
    }


    for(int i=0; i<n ; i++)                 //i th node acts as intermediate
    {
        for(int j=0; j<n ; j++)             // jth as starting 
        {
            for(int k=0; k<n; k++)          // kth as ending
            {
                if(distance[j][i]+distance[i][k]<distance[j][k])
                {
                    distance[j][k] =   distance[j][i]+distance[i][k];
                }
            }
        }
    }

    cout<<"   ";
    for(int i=0; i<n ; i++)
    {
        cout<<i<<"  ";
    }cout<<"\n";

    for(int i=0; i<n; i++)
    {
        cout<<i<<"  ";
        for(int j=0; j<n ;j++)
        {
            cout<<distance[i][j]<<"  ";
        }cout<<"\n";
    }


    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define INF 1e9+7

#define N 8 
int n=8;
  

int shortestDist(int graph[][N]) { 
  
    
    int dist[n]; 
  
    dist[n-1] = 0; 
  
   
    for (int i = n-2 ; i >= 0 ; i--) 
    { 
  
        dist[i] = INF; 
  
 
        for (int j = i ; j < n ; j++) 
        { 
            if (graph[i][j] == INF) 
                continue; 
  
          
            dist[i] = min(dist[i], graph[i][j] + dist[j]); 
        } 
    } 
  
    return dist[0]; 
}

int main()
{
    
    //Shortest Path in Multi Stage path


    cout<<"Enter the number of vertices : ";
    cin>>n;

    int adjMat[8][8];

    for(int i=0; i<n ; i++)
    {
        for(int j=0; j<n ;j++)
        {
            adjMat[i][j]=INF;
        }
    }
    for(int i=0;  ; i++)
    {
        int x,y,z;
        cout<<"Enter the (source node, dest node, distance)(-1 -1 -1 to break) : ";
        
        cin>>x>>y>>z;
        if(x == -1)
        	break;
			
        adjMat[x][y]=z;
    }
    cout<<"Sortest distance between 0 to "<<n-1<<" th node = "<<shortestDist(adjMat);
    

    return 0;
}
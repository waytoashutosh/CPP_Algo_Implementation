#include<bits/stdc++.h>
using namespace std;
#define nl cout<<"\n";

vector<bool> visited;
vector<int> answer;
vector<vector<int>> adj;

void dfs(int i)
{
	if(visited[i])
	{
		return;
	}
	
	visited[i]=true;
	
	for(auto e: adj[i])
	{
		dfs(e);
	}
	answer.push_back(i);
	
}
	


int main()
{
	//this is code for top sort
	
	int n;
	
	cout<<"Enter the number of nodes: ";
	cin>>n;
	visited.resize(n);
	
	//for this i am going to create adjacency list.
	
	
	for(int i=0; i<n; i++)
	{
		vector<int> v;
		int x;
		
		cout<<"(-1 to end)enter nodes "<<i<<" -> ";
		cin>>x;
		while(x!=-1)
		{
			v.push_back(x);
			cin>>x;
			
		}
		adj.push_back(v);
		
	}
	nl;
	for(int i=0; i<n; i++)
	{
		cout<<i<<" -> ";
		for(int j=0; j<(int)adj[i].size(); j++)
		{
			cout<<adj[i][j]<<" ";
		}nl;
	}
	
	//now the adjacency list is ready -----NOTE : without any cycle------
	
	//now we will perform top sort
	for(int i=0; i<n; i++)
	{
		if(visited[i]) continue;
		dfs(i);
	}nl;
	
	reverse(answer.begin(), answer.end());
	for(auto e: answer)
	{
		cout<<e<<" ";
	}nl;
	
	
	
	
	return 0;
	
}


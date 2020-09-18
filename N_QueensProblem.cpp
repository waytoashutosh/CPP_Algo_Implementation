#include<bits/stdc++.h>
using namespace std;
#define nl cout<<"\n";

vector<int> column;
vector<int> diag1;
vector<int> diag2;
vector<vector<int>> solution;
int n;
int coun;

void search(int y)
{
    if(y==n)
    {
        coun++;

        //process the soution

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<solution[i][j]<<" ";
            }nl;
        }nl;
        return;
    }

    for(int x=0; x<n; x++)
    {
        if(diag1[x+y] || diag2[x-y+n-1] || column[x]) continue;

        solution[x][y]=1;
        diag1[x+y] =diag2[x-y+n-1] =column[x]=1;
        search(y+1);
        diag1[x+y] =diag2[x-y+n-1] =column[x]=0;
        solution[x][y]=0;
        
    }
}

int main()
{

    coun=0;
    
    
    cin>>n;
    vector<vector<int>> sol(n,vector<int>(n,0));
    solution=sol;
    column.resize(100);
    diag2.resize(100);
    diag1.resize(100);
    search(0);
    cout<<"Number of Solutions = "<<coun;
   

    return 0;
}
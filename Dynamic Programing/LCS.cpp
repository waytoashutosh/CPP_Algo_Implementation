#include<bits/stdc++.h>
using namespace std;

string a,b;



int main()
{

    //Longest commmon subsequece
    a="asdfg";
    b="afasdg";
    
    int n=a.size();
    int m=b.size();

    int dp[n][m];

    int i=n-1;
    int j=m-1;


    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            
            if(a[i]!=b[j])
            {
                dp[i][j]=max(i-1==-1?0:dp[i-1][j],j-1==-1?0:dp[i][j-1]);
            }
            else
            {
                dp[i][j]=1+(i-1==-1 || j-1 == -1 ?0:dp[i-1][j-1]);
            }
        }

    cout<<dp[n-1][m-1];




    return 0;
}
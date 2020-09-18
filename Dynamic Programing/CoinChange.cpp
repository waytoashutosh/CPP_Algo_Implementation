#include<bits/stdc++.h>
using namespace std;


#define INF 1e9+7

int main()
{
    //Coin change problem
    int n;
    cout<<"Enter the number of distinct coins : ";
    cin>>n;

    vector<int> coins(n);

    cout<<"Enter the coins : ";
    for(int i=0; i<n; i++)
    {
        cin>>coins[i];
    }
    int y;
    cout<<"Enter the amount you want : ";
    cin>>y;

    vector<int> dp(y+1,INF);

    dp[0]=0;
    for(int i=1; i<=y; i++)
    {
        for(auto c:  coins)
        {
            if(i-c>=0)
            dp[i] = min(dp[i], dp[i-c]+1);
        }

    }
    cout<<"\n";
    cout<<"Minimum coins req for "<<y<<" = "<<dp[y];


    return 0;
}
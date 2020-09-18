#include<bits/stdc++.h>
using namespace std;

vector<int> a;
int tsum=0;
int n;
vector<int> global;
int gsum;
vector<vector<int>> dp;
int solve(int i, vector<int> ans, int csum)
{
    
    //base case 
    if(i==n)
    {
       
        if(abs(tsum-csum-csum)<gsum)
        {
            gsum=abs(tsum-csum-csum);
            global=ans;
        }

        return abs(tsum-csum-csum);
    }
    if(dp[i][csum]!=0)
    return dp[i][csum];

    ans.push_back(a[i]);
    int x = solve(i+1,ans,csum+a[i]);
    ans.pop_back();
    int y = solve(i+1,ans,csum);

    /* for(auto e: ans)
    {
        cout<<e<<" ";
    }cout<<"\n\n"; */
    dp[i][csum]=min(x,y);
    return min(x,y);

}


int main()
{
    //divide the subset into two subsets such that difference of sums is minimum
    auto start = chrono::high_resolution_clock::now();


    vector<vector<int>> d(100,vector<int>(100,0));
    dp=d;
    gsum=1e9;
    a={1,6,11,5,5,4,3,6,7,8,9,1,12,35,56,75,32,43,532,12214,5};
    n=a.size();
    for(int i=0; i<n; i++)
    {

        tsum+=a[i];
    }
    //cout<<"tsum: "<<tsum;
    vector<int> r;
    cout<<"min difference: "<<solve(0,r,0);
    cout<<"\nset 1: \n";
    for(auto w: global)
    {
        cout<<w<<" ";
    }
    auto end = chrono::high_resolution_clock::now();
    double time_taken =  
      chrono::duration_cast<chrono::nanoseconds>(end - start).count(); 
  
    time_taken *= 1e-9; 
  
    cout << "Time taken by program is : " << fixed  
         << time_taken << setprecision(20); 
    cout << " sec" << endl; 




    return 0;

}
#include <bits/stdc++.h>
using namespace std;

vector<int> v;
vector<int> m;
int dp[101][101];

//so in the solve funcion we are just partitioning the matrices
//ex
// (A0)  (A1  A2  A3)
// (A0  A1)  (A2  A3)
// and so on
//the loop is going from 0 to 3
//i.e selecting the first part then the second part


int solve(int l, int r){
    if(r==l){
        return 0;
    }
    if(r-l==1){
        return v[l]*v[l+1]*v[l+2];
    }
    if(dp[l][r]!=-1){
        return dp[l][r];
    }
    
    int mi = INT_MAX;
    
    for(int i=l; i<r; i++){
        mi = min(mi, solve(l,i)+solve(i+1,r)+v[l]*v[i+1]*v[r+1]);
    }
    dp[l][r]=mi;
    return mi;
}


int main() {
	//code
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    
	    v.resize(n);
	    for(int i=0; i<n; i++){
	        cin>>v[i];
	    }
	    
	    m.resize(n-1);
	    for(int i=0; i<n-1; i++){
	        m[i]=i+1;
	    }
	    memset(dp,-1,sizeof(dp));

        //number of matrices = n-1
        //hence the counting matrices from 0 -> we wiill have range [0,n-2]
	    cout<<solve(0,n-2)<<"\n";
	    
	    
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;



int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    //we are going to create sparse table 
    //for minimum queries in constant time 
    //ans n log n space
    int n;
    cin>>n;

    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    //now creating the sparse table for this

    //v = {4,3,6,1,2,8,9,1,4}
    //i = {0,1,2,3,4,5,6,7,8}
    map<pair<int,int>,int> m;

    for(int i=0; i<n; i++){
        m[{i,i}]=v[i];
    }

    for(int len=2; len<=n; len=len*2){
        for(int i=0; i+len-1<n; i++){
            m[{i,i+len-1}]=min(m[{i,i+len/2-1}], m[{i+len/2,i+len-1}]);
            
        }
    }

    int q;
    cin>>q;

    while(q--){
        int l, r;
        cin>>l>>r;

        int length = r-l+1;
        int size = 1;
        while(size*2<length) size=size*2;

        cout<< size<<" "<<l<<" "<<r<<" = "<<min(m[{l,l+size-1}], m[{r-size+1,r}])<<"\n";
    }
    
    // for(int i=0; i<n; i++){
    //     cout<<v[i]<<" ";
    // }cout<<"\n";

    // for(auto itr=m.begin(); itr!=m.end(); itr++){
    //     cout<<(itr->first).first<<" "<<(itr->first).second<<" = " <<itr->second<<"\n";
    // }

    return 0;
}

#include<bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin>>s;
    int n = s.size();
    //we are going to use the z algorithm for string matching

    int l=0,r=0;
    vector<int> z(n);
    for(int i=1; i<n; i++){

        if(i+z[i-l]<r){
            z[i]=z[i-l];
        }
        else{
            while(i+z[i]<n && s[z[i]]==s[i+z[i]]){
                l=i;
                r=i+z[i];
                z[i]++;
            }
        }

    }

    for(int i=0; i<n; i++){
        cout<<z[i]<<" ";
    }
}


int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t;
    cin>>t;
    
    while(t--)
    {
        solve();
    }
    return 0;
}

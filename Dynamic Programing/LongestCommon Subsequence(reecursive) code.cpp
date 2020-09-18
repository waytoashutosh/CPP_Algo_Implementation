#include<bits/stdc++.h>
using namespace std;

int LCS(string a, string b)
{
    //base case
    if(a.size()==0 || b.size()==0)
    return 0;

    int x=0,y=0,z=0;
        
    if(a.back()==b.back())
    {
        a.pop_back();
        b.pop_back();
         x = 1 + LCS(a,b);
    }
    else{
        y = LCS(a,b);
        z = LCS(a,b);
    }

    return max(x,y,z);


}


int main()
{

    cout<<LCS("asdfg","adg");


    return 0;

}
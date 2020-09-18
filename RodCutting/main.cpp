#include <bits/stdc++.h>
using namespace std;
#define nl cout<<"\n";
int main()
{
    cout<<"Rod Cutting Problem.\n";
    int p[11]={0,1,5,8,9,10,17,17,20,24,30};

    cout<<"Rod Table :\nlength: ";
    for(int i=1; i<=10; i++)
    {
        printf("%4d ",i);
    }nl;
    cout<<"price:  ";
    for(int i=1; i<=10; i++)
    {
        printf("%4d ",p[i]);
    }nl;

    //solving th problem using dynamic programing (bottom up solution)
    int ans[11]={0};
    int path[11];
    for(int i=1; i<=10; i++)
    {
        ans[i]=p[i];
        path[i]=i;
        for(int j=i; j>=1; j--)
        {
            if(ans[i]<p[j]+ans[i-j])
            {
                ans[i]=p[j]+ans[i-j];
                path[i]=j;
            }
        }
    }

    cout<<"solut:  ";
    for(int i=1; i<=10; i++)
    {
        printf("%4d ",ans[i]);
    }nl;

    cout<<"path:   ";
    for(int i=1; i<=10; i++)
    {
        printf("%4d ",path[i]);
    }nl;


    return 0;
}

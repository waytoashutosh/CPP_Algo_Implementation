#include <iostream>
using namespace std;

unsigned long long int n;
unsigned long long int solve(unsigned long long int i)
{
    if(i>=n)
    {
        return 0;
    }
    
    unsigned long long int x=0,y=0;
    
    if(i+1<=n)
    x = 1+solve(i+1);
    
    if((unsigned long long int)(i*2)<=n)
    y = 1+solve(i*2);
    
    return min(x,y);
}

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    
	    cout<<1+solve(1)<<"\n";
	}
	return 0;
}
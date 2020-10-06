#include<stdio.h>

int f() 
{ 
   return x; 
} 
  
// g() has its own variable 
// named as x and calls f() 
int g() 
{ 
   int x = 20; 
   return f(); 
} 
  
int main() 
{ 
  printf("%d",g());
  return 0; 
}
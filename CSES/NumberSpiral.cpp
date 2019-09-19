#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main() {
   int t;
   std::cin>>t;

   while(t--) {
       long long y,x;
       std::cin>>y>>x;

       if(x>=y) {
           if(x%2==0)
            std::cout<<(x-1)*(x-1)+y<<"\n";
           else
            std::cout<<x*x - y  + 1<<"\n"; 
       } else {
           if(y%2==0)
            std::cout<<y*y -x+1<<"\n";
           else
            std::cout<<(y-1)*(y-1) + x<<"\n";
       }
   }
   return 0;
}
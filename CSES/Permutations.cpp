#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;

    if(n==2||n==3){
        std::cout<<"NO SOLUTION"<<"\n";
        return 0;
    }

    int front = n/2+(n%2==0?0:1);
    int end = n;
    int count = n/2 +1;
    int middle = front;

    for(int i=0;i<count;i++) {
        if(front!=0)
            std::cout<<front--<<" ";
        if (end!=middle)
            std::cout<<end--<<" ";
    }

    return 0;
}
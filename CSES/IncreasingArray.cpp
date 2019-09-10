#include <iostream>


int main() {
    int n;
    int * arr;
    long long turn = 0;
    std::cin>>n;

    arr = new int[n];

    for(int i=0;i<n;i++) {
        std::cin>>arr[i];
    }

    for(int i=1;i<n;i++) {
        for(;arr[i]<arr[i-1];arr[i]++)
            turn ++;
    }

    std::cout<<turn<<"\n";

    delete[] arr;

    return 0;
}
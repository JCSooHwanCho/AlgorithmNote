#include<iostream>

int main() {
    long long n;

    std::cin>>n;

    while(n>1) {
        std::cout<<n<<" ";
        if (n%2==0)
            n /= 2;
        else 
            n = 3*n + 1;
    }

    std::cout<<n<<"\n";
}
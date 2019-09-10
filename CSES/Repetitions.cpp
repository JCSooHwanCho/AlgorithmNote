#include<iostream>

using namespace std;
const int STR_MAX = 1000000;
int main() {
    char str[STR_MAX+1];

    std::cin>>str;

    int maxLength = 1;
    int currentIndex = 1;
    int currentLength = 1;
    char current = str[0];

    while(str[currentIndex]!='\0') {
        if(str[currentIndex]!=current) {
            maxLength = max(maxLength,currentLength);
            currentLength = 1;
            current = str[currentIndex];
        } else {
            currentLength++;
        }
        currentIndex++;
    }
    maxLength = max(maxLength,currentLength);
    std::cout<<maxLength<<"\n";

    return 0;
}
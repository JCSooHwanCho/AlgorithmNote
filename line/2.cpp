#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;


int main() {
    char s[100];

    cin.getline(s,100);

    vector<int> arr;
    
    int i=0;
    int num=0;
    while(s[i]!='\0') {
        if(s[i]>='0'&&s[i]<='9')
            num += s[i] - '0';
        else {
            arr.push_back(num);
            num = 0;
        }
        i++;
    }
    arr.push_back(num);

    int k;
    cin>>k;

    sort(arr.begin(),arr.end());

    do {
        k--;
        if(k==0)
            for(int a:arr)
                std::cout<<a;
    }while(next_permutation(arr.begin(),arr.end()));

    std::cout<<"\n";
    return 0;
}
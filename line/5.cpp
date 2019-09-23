#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

long long combination(int n,int c) {
    if(n-c<=c)
        c= n-c;

    long long result = 1;
    
    long long rN = c;
    long long rC = 1;

    while(rN-->0) {
        result *= (n-rN);

        while(rC<=c&&result%rC==0) {
            result /= rC++;
        }
    }
    return result;
}

int main() {
    int n,m;
    cin>>n>>m;

    int x,y;
    cin>>x>>y;

    if(x>n||y>m) { // 모눈종이 밖을 벗어났을 때
        cout<<"fail"<<"\n";
    } else {
        cout<<x+y<<"\n";
        cout<<combination(x+y,x)<<"\n";
    }

    return 0;
}
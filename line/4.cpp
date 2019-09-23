#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int n;
    cin>>n;

    vector<int> seat(n+2,0);

    for(int i=1;i<=n;i++)
        cin>>seat[i];  

    int l=0;
    int r=1;
    int answer = 1;
    while(l<=n) {
        while(r<=n&&seat[r]==0)
            r++;
        int isOpened = seat[l]*seat[r];

        int dist = (r-l)/(1+isOpened) - (1-isOpened);
        answer = answer>dist?answer:dist; 
        l = r++;
    }

    cout<<answer<<"\n";
    return 0;
}
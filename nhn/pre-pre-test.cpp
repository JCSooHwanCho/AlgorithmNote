#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string ** arr;

void swap(string& a,string& b) {
    string temp = a;
    a = b;
    b = temp;
}

pair<int,int> getBoardIndex(int depth,int l, int index) {
    int q = index /l;
    int r = index %l;
    int x = depth +(((q+1)/2)%2)*l + pow(-1,q/2)*(1-q%2)*r;
    int y = depth + (q/2)*l + pow(-1,q/2)*(q%2)*r;

    return make_pair(x,y);
}

int gcd (int a,int b) {
    int r = 0;

    while(b!=0) {
        r= a%b;
        a=b;
        b=r;
    }
    return a;
}

void rotate(int n, int depth, int k) {
    int l = n-2*depth-1;
    int length = 4*(n-2*depth-1);

    int direction = 1;

    if(k<0) {
        k*=-1;
        direction = -1;
    }
    k%=length;
    
    if(direction==-1)
        k = length-k;
    
    if(k==0||k==length)
        return;

    int loopCount = gcd(k,length);

    for(int i=0;i<loopCount;i++) {
        int index = i;

        string cache = "";
        do {
            auto point = getBoardIndex(depth,l,index);

            if(cache=="") {
                cache = arr[point.second][point.first];
            }

            int nextIndex = (index+k)%length;
            
            auto nextPoint = getBoardIndex(depth,l,nextIndex);

            swap(cache,arr[nextPoint.second][nextPoint.first]);
            
            index = nextIndex;
        } while(index!=i);
    }

}

int main() {
	int n, k;

    cin>>n>>k;

    arr = new string*[n];
    for(int i=0;i<n;i++) 
        arr[i] = new string[n];

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>arr[i][j];
        }
    }

    int direction = 1;
    for(int i=0;i<n/2;i++){
        rotate(n,i,direction*k);
        direction*=-1;
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++)
            cout<<arr[i][j]<<" ";
        cout<<"\n";
    }
    for(int i=0;i<n;i++) 
        delete[] arr[i];

    delete[] arr;

	return 0;
}
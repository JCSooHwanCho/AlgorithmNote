#include<vector>
using namespace std;

int solve(vector<int>& h, int left,int right) {
    if(left==right) return h[left];

    int mid = (left + right) / 2;

    int answer = max(solve(h,left,mid), solve(h,mid+1,right));

    int lo = mid, hi = mid+1;

    int height = min(h[lo],h[hi]);

    answer = max(answer,height*2);

    while(left < lo|| hi < right) {
        if(hi < right && (lo==left || h[lo-1]< h[hi+1])) {
            ++hi;
            height= min(height,h[hi]);
        } else {
            --lo;
            height = min(height,h[lo]);
        }
        answer = max(answer,height*(hi-lo+1));
    }
    return answer;
}

long largestRectangle(vector<int> h) {
 int N = h.size();

 return solve(h,0,N-1);
}

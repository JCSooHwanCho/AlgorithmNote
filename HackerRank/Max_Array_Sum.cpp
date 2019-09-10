#include <vector>
#include <algorithm>

using namespace std;

int cache[100001];
int solve(vector<int>& arr,int index) {
    if(index>=arr.size()) {
        return 0;
    } else {
        if (cache[index]!=-1)
            return cache[index];
        cache[index] = max(arr[index]+ solve(arr,index+2),solve(arr,index+1));
        return cache[index];
    }
}
// Complete the maxSubsetSum function below.
int maxSubsetSum(vector<int> arr) {
    memset((void*) cache,-1,sizeof(int)*100001);
    return solve(arr,0);
}

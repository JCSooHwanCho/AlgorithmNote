// 구간 질의 트리

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int impact(char c){
    if(c=='A')
        return 1;
    if(c=='C')
        return 2;
    if(c=='G')
        return 3;
    if(c=='T')
        return 4;
}
int initRangeMin(string& S, vector<int>& rangeMin,int left,int right,int node){
    if(left==right) {
        return rangeMin[node] = impact(S[left]);
    } else {
        int mid = (left + right) / 2;
        int leftMin = initRangeMin(S,rangeMin,left,mid,node*2);
        int rightMin = initRangeMin(S,rangeMin,mid+1,right,node*2+1);
        return rangeMin[node] = min(leftMin,rightMin);
    }
}

int query(vector<int>& rangeMin,int left,int right,int node,int nodeLeft,int nodeRight){
    if(right<nodeLeft||nodeRight<left) return 5;
    
    if(left<=nodeLeft&&nodeRight<=right)
        return rangeMin[node];
    
    int mid = (nodeLeft + nodeRight) / 2;
    return min(query(rangeMin,left,right,node*2,nodeLeft,mid),query(rangeMin,left,right,node*2+1,mid+1,nodeRight));
}
vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> rangeMin(S.size()*4);
    vector<int> answer(P.size());
    initRangeMin(S,rangeMin,0,S.size()-1,1);
    
    for(int i=0;i<P.size();i++) {
        answer[i] = query(rangeMin,P[i],Q[i],1,0,S.size()-1);    
    }
    
    return answer;
}

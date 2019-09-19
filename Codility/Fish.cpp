#include <vector>
#include<iostream>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
using namespace std;

int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> st(1,0);
    
    for(int Q = 1;Q<A.size();Q++) {
        int P = st.back();
        
        if(B[P]==1&&B[Q]==0) {
            while(B[P]==1&&B[Q]==0) {
                if(A[P]<A[Q]) {
                    st.pop_back();
                    
                    if(st.empty()||B[st.back()]==B[Q]) {
                        st.push_back(Q);
                        break;
                    } 
                    
                    P = st.back();
                } else
                    break;
            }
        } else {
            st.push_back(Q);
        }
    }
    
    return st.size();
}
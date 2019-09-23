#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

int main() {
    int n;
    cin>>n;

    vector<pair<int,int> > arr;

    for(int i=0;i<n;i++) {
        int b,e;
        cin>>b>>e;

        arr.push_back({b,e});
    }

    sort(arr.begin(),arr.end());

    stack<pair<int,int> >  st;
    int answer = 1;
    for(int i=0;i<n;i++) {

        while(!st.empty()&&st.top().second<=arr[i].first)
            st.pop();
            
        st.push(arr[i]);
        answer = answer>st.size()? answer:st.size();
    }

    std::cout<<answer<<"\n";

    return 0;
}
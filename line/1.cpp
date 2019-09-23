#include<iostream>
#include<queue>

using namespace std;

int main() {
 
    int m,c;
    cin>>m>>c;

    priority_queue<int> q;

    for(int i=0;i<m;i++) {
        int temp;
        cin>>temp;
        if(q.size()<c)
            q.push(-temp);
        else {
            
            int smallest = -q.top();
            q.pop();
            smallest += temp;
            q.push(-smallest);
        }
    }

    while(q.size()>1)
        q.pop();

    std::cout<<-q.top()<<"\n";

    return 0;
}
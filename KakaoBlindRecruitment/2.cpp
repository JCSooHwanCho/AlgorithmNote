#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isCorrect(string& s) {
    stack<char> st;

    for(char c: s) {
        if(c == '(') {
            st.push(c);
        } else {
            if(st.empty()) {
                return false;
            }
            st.pop();
        }
    }

    if(st.empty())
        return true;
    else
        return false;
}

int getPointsToDivide(string &s){
    int openCount = 0;
    int closeCount = 0;
    int result = 0;
    for(char c: s) {
        if (c == '(')
            openCount++;
        else 
            closeCount++;

        result++;
        if (openCount==closeCount)
            return result;
    }
    return result;
}

string trimAndReverse(string &s) {
    string result;

    for(auto it = s.begin()+1;it!= s.end()-1;it++) {
        if (*it=='(')
            result+=')';
        else
            result+='(';
    }
    return result;
}
string solution(string p) {
    
    if(p.empty())
        return "";
    
    int dividePoint = getPointsToDivide(p);
    string u = p.substr(0,dividePoint);
    string v = p.substr(dividePoint);

    if (isCorrect(u)) {
        return u + solution(v);
    } else {
        string result = "(";
        result += solution(v);
        result += ")";
        result += trimAndReverse(u);
        
        return result;
    }
}
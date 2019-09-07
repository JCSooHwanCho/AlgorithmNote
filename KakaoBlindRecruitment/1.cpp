#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.size();
    int maxPiece = s.size() / 2;
    
    for(int i=1;i<=maxPiece;i++) {
        int length = 0;
        for(int j=0;j<s.size();j+=i) {
            string current = s.substr(j,i);
            int count = 1;
            while(j+i<s.size()&&current == s.substr(j+i,i)){
                count++;
                j+=i;
            }
            int digit = 0;
            
            if(count != 1){
                while (count>0) {
                    digit++;
                    count/=10;
                }
            }
            length += current.size() + digit;
        }
        
        answer = answer>length? length:answer;
    }
    return answer;
}
문제 번호 : 874 
문제명 : Walking Robot Simulator  
문제 링크 : https://leetcode.com/problems/walking-robot-simulation/
소요시간 : 2시간

---

문제 풀이

이 문제에서 빠졌던 함정은, 최종 위치의 거리가 아니라 **가장 멀어졌을 때의 거리**를 반환해야 한다는 것이였다. 그것만 아니였음 30분 내로 풀었을 것이다.(이것도 오래 걸린 거긴 하지만)

문제 이름에서 드러나지만 간단한 시뮬레이션 문제다. 앞으로 움직이게 하는 것은 문제도 아니다. 여기서 두가지 문제를 해결해야 한다.

1. 방향을 어떻게 표현할 것인가? - 기본값인 북쪽을 0, 시계방향으로 순서대로 1,2,3의 번호를 매긴다. 이렇게 하면 방향 전환을 숫자를 빼고 더하는 것으로 쉽게 표현할 수 있다. 방향 값은 (0,3)의 범위를 가지고, 이 범위를 벗어나면 보정을 해준다.

2. 장애물을 어떻게 체크할 것인가?
   1. X좌표와 Y좌표를 키로하고, 반대 좌표(X좌표가 키면 Y좌표가 값)의 vector를 값으로하는 map을 두개 만들어 장애물을 순차적으로 검색하게 한다. -> 해결은 되나, 속도가 많이 느렸다. map의 속도와 vector의 순차 검색이 병목인 듯 하다. 
   2. 장애물 전체를 하나의 Set으로 담아서, 매 단계 1칸씩 움직이면서 장애물을 Set으로 검색하게 한다. -> 상당한 속도 개선이 있었다. (약 50 ms) 
      * 이 때 set의 키를 vector나 pair로 하지않고, 정수값으로 두었을 때 훨씬 빨라졌다. 이 때, 이를 정수값으로 바꿀 때 충돌을 막기 위해 한 좌표에 입력값의 범위를 고려하여 100000를 곱하여 서로 더한다. 단, 오버플로 문제가 있기 때문에 자료형은 long long으로 해야합니다.

프로그램의 시간복잡도를 분석해보면, 장애물을 Set에 넣는 과정에서 장애물의 갯수를 m이라고 하면 O(m), 장애물 검색은 Set으로 하면 O(1)이다. 또한 매 명령마다 상수 횟수만큼의 명령을 수행하기 때문에 명령 수행의 시간 복잡도는 명령의 수를 n이라 하면 O(n)이다. 즉 전체 시간 복잡도는 O(m+n)이다.

```c++
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<queue>
#include<functional>

using namespace std;
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int> >& obstacles) {
        int x = 0, y = 0;
        int direction = 0;
        int answer = 0;
        const int KEY_X = 100000;

        set<long long> ob;

        for (auto it = obstacles.begin();it != obstacles.end();it++) {
            ob.insert(static_cast<long long>((*it)[0])*KEY_X + (*it)[1]);
        }

        for (int comm: commands) {
            if (comm == -2) {
                direction = (3 + direction)%4;
            } else if(comm == -1) {
                direction = (5 + direction)%4;
            } else {
                if(direction%2==0) { // YPosition Move
                    int dY = 1 - direction;
                    for (int i = 0;i<comm;i++) {
                        if (ob.find(static_cast<long long>(x)*KEY_X+y+dY)!=ob.end())
                            break;
                        y += dY;
                        }
                    } else { //XPosition Move
                    int dX = 2 - direction;
                    for(int i=0;i<comm;i++) {
                        if(ob.find((static_cast<long long>(x)+dX)*KEY_X + y)!= ob.end())
                            break;
                        x+=dX;
                    }
                }
                int temp = x*x + y*y;
                answer = answer>temp? answer:temp;
            }
            
        }
        return answer;
    }
};
```

```swift
class Solution {
    func robotSim(_ commands: [Int], _ obstacles: [[Int]]) -> Int {
        var x = 0
        var y = 0
        var direction = 0
        var answer = 0
        
        var ob:Set<Int> = Set();
        
        for o in obstacles {
            ob.insert(o[0]*100000 + o[1]);
        }
        
        for comm in commands {
            if comm == -2 {
                direction = (3 + direction) % 4
            } else if comm == -1 {
                direction = (5 + direction) % 4
            } else {
                if direction%2 == 0 {
                    let dy = 1 - direction
                    for _ in 0..<comm {
                        if ob.contains(x*100000+y+dy) {
                            break
                        }
                        y += dy;
                    }
                } else {
                    let dx = 2 - direction
                        for _ in 0..<comm {
                            if ob.contains((x+dx)*100000+y) {
                                break
                            }
                        x += dx
                    }

                }
                
                let temp = x*x + y*y
                if answer<temp {
                    answer = temp
                }
            }
        }
        return answer;
    }
}

```
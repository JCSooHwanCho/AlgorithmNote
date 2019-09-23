#include<iostream>
#include<vector>
#include<string>

using namespace std;

enum alignment {
    top, middle,bottom
};


int N;  
alignment Global_ALIGN;
char ** board;

const int numSeg[10][8] = {
    {1,2,3,5,6,7,},//0
    {3,6,},//1
    {1,3,4,5,7,},//2
    {1,3,4,6,7,},//3
    {2,3,4,6,},//4
    {1,2,4,6,7,},//5
    {1,2,4,5,6,7,},//6
    {1,2,3,6},// 7
    {1,2,3,4,5,6,7,}, // 8
    {1,2,3,4,6,} // 9
};

void fillSegment(int segNum,int x,int y,int width, int height) {
    switch(segNum) {
        case 1:
            for(int i=0;i<width;i++) {
                board[y][x+i] = '#';
            }
            break;
        case 2:
            for(int i=0;i<=height/2;i++) {
                board[y+i][x] = '#';
            }
            break;
        case 3:
            for(int i=0;i<=height/2;i++) {
                board[y+i][x+width-1] = '#';
            }
            break;
        case 4:
            for(int i=0;i<width;i++) {
                board[y+height/2][x+i] = '#';
            }
            break;
        case 5:
            for(int i=0;i<=height/2;i++) {
                board[y+height/2+i][x] = '#';
            }
            break;
        case 6:
            for(int i=0;i<=height/2;i++) {
                board[y+height/2+i][x+width-1] = '#';
            }
            break;
        case 7:
            for(int i=0;i<width;i++) {
                board[y+height-1][x+i] = '#';
            }
            break;

    }
}
void fillNumber(int number,int x,int y, int width,int height) {
    int index = 0;
    while(numSeg[number][index]!=0) 
        fillSegment(numSeg[number][index++],x,y,width,height);
}

void fillBoard(int cursor,int height, pair<int,string> needToPrint) {
    int width = needToPrint.first;
    int numberHeight = 2*width - 1;

    for(int i=0;i<needToPrint.second.size();i++){
        int currentCursor = cursor+(width+1)*i;
        switch(Global_ALIGN) {
        case top:
            fillNumber(needToPrint.second[i]-'0',currentCursor,0,width,numberHeight);
            break;
        case middle:
            fillNumber(needToPrint.second[i]-'0',currentCursor,height/2 - numberHeight/2,width,numberHeight);
            break;
        case bottom:
            fillNumber(needToPrint.second[i]-'0',currentCursor,height-numberHeight,width,numberHeight);
        }
        for(int i=0;i<height;i++) {
            board[i][currentCursor-1] = ' ';
        }
    }
}

int main() {

    vector<pair<int,string> > needToPrint;
    string a;
    cin>>N>>a;

    if(a=="TOP") {
        Global_ALIGN = alignment(top);
    } else if(a=="MIDDLE") {
        Global_ALIGN = alignment(middle);
    } else 
        Global_ALIGN = alignment(bottom);

    int maxWidth = 0;
    int totalWidth=0;
    for(int i=0;i<N;i++){
        int t;
        string s;
        cin>>t>>s;

        needToPrint.push_back({t,s});

        maxWidth = maxWidth>t?maxWidth:t;
        totalWidth+=(needToPrint[i].first+1)*s.size();
    } 
    
    int height = maxWidth*2 -1;
    board = new char*[height];

    for(int i=0;i<height;i++) {
        board[i] = new char[totalWidth];
        for(int j=0;j<totalWidth;j++) 
            board[i][j] = '.';
    }

    
    int cursor = 0;
    for(int i=0;i<needToPrint.size();i++) {
        fillBoard(cursor,height,needToPrint[i]);
        cursor+=(needToPrint[i].first+1) * needToPrint[i].second.size();
    }

    for(int i=0;i<height;i++) {
        board[i][totalWidth-1] = '\0';
        cout<<board[i]<<"\n";
    }

    for(int i=0;i<height;i++)
        delete[] board[i];

    delete[] board;
    return 0;
}
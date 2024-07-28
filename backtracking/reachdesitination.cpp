#include<iostream>
#include<vector>
using namespace std;

bool canreachdestination(int sx,int sy,int dx,int dy){
    //base condition
    if(sx==dx&&sy==dy){
        return true;
    }
    //is valid move for x point
    if(sx+sy<=dx&&canreachdestination( sx+sy,sy, dx, dy)){
        return true;
    }
    //is valid move for y point
     if(sx+sy<=dy&&canreachdestination( sx,sx+sy, dx, dy)){
        return true;
    }
    return false;

}
int main(){
    int sx=1;
    int sy=1;
    int dx=3;
    int dy=5;
    bool isreachable=canreachdestination(sx,sy,dx,dy);
    cout<<isreachable<<endl;
} 
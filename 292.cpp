#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canWinNim(int n) {//拿走几个给对面剩下4个，则自己能赢
                            //所以如果是4的倍数，则自己会输
        if(n%4==0)
            return false;
        return true;

    }
};

int main(){

    

    return 0;
}
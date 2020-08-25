#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPowerOfThree(int n) {//递归实现
        if(n==0)
            return false;
        if(n==1)
            return true;
        if(n==3)
            return true;
        if(n%3!=0)
            return false;
        return isPowerOfThree(n/3);
    }
};

int main(){

    

    return 0;
}
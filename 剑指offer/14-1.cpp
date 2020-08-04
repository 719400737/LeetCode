#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int cuttingRope(int n) {
        int res=1;
        vector<int> vec={1,1,2,4};//从结果中尽可能的取出3，但不能剩余1.
        if(n<=4)
            return vec[n-1];
        while(n>4){
            n-=3;
            res*=3;
            if(n<=4){
                res*=n;
                break;
            }
        }
        return res;

    }
};

int main(){



    return 1;
}
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int cuttingRope(int n) {
        long long mod=pow(10,9)+7;
        long long res=1LL;
        vector<int> vec={1,1,2,4};//从结果中尽可能的取出3，但不能剩余1.
        if(n<=4)
            return vec[n-1];
        while(n>4){
            n-=3;
            res*=3;
            res%=mod;
            if(n<=4){
                res*=n;
                res%=mod;
                break;
            }
        }
        return res;

    }
};

int main(){



    return 1;
}
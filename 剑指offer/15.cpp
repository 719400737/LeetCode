#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res=0;
        for(int i=0;i<32;i++){ //二进制操作，右移32次，查看每位是否为1.
            if(n&1==1)
                res++;
            n>>=1;
        }
        return res;
    }
};

int main(){



    return 1;
}
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res=0;
        for(int i=0;i<32;i++){
            res=(res<<1)+(n&1);
            n>>=1;
        }
        return res;
    }
};

int main(){
    uint32_t n=54;
    Solution s;
    uint32_t res=s.reverseBits(n);
    cout<<res<<endl;
    return 0;
}
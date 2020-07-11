#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int a=1;
        int res=0;
        for(int i=0;i<32;i++){
            if(n>>i & a )
                res++;
        }
        return res;
    }
};

int main(){


    return 0;
}
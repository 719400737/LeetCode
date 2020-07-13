#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int a=-1;
        long long num=0;
        while(num<n){
            a++;
            num=pow(2,a);
        }
        if(num==n)
            return true;
        else    return false;
    }
};

int main(){



    return 1;
}
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sumNums(int n) {
        if(n==1)
            return 1;
        return n+sumNums(n-1);
    }
};

int main(){



    return 0;
}
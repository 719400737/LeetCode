#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> res;
        int num=pow(10,n);
        for(int i=1;i<num;i++){
            res.push_back(i);
        }
        return res;
    }
};

int main(){



    return 1;
}
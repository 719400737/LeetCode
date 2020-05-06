#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size()-1;
        int b=0;
        for(;n>=0;n--){
            if(digits[n]!=9){
                digits[n]++;
                b=1;
                break;
            }
            else
                digits[n]=0;
        }
        if(!b){
            digits[0]=1;
            digits.push_back(0);
        }
        return digits;
    }
};

int main(){


    return 0;
}
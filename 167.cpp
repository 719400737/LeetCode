#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int left=0;
        int right=numbers.size()-1;
        while(left<right){
            if(numbers[left]+numbers[right]==target){
                res.push_back(left+1);
                res.push_back(right+1);
            }
            if(numbers[left]+numbers[right]<target){
                left++;
            }
            else
                right--;
        }
        return res;
        
    }
};

int main(){


    return 0;
}
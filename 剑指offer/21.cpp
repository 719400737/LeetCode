#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        vector<int> v1,v2;
        for(auto i:nums){
            if(i%2==1)
                v1.push_back(i);
            else    v2.push_back(i);
        }
        for(auto i:v2)
            v1.push_back(i);
        return v1;
    }
};

int main(){



    return 1;
}
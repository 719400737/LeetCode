#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    /*vector<int> singleNumbers(vector<int>& nums) { //虽然不会超时，但是使用了额外的内存空间
        vector<int> res;
        set<int> s;
        for(auto i:nums){
            if(s.count(i))
                s.erase(i);
            else    s.insert(i);
        }
        for(auto i:s)
            res.push_back(i);
        return res;
    }*/
    vector<int> singleNumbers(vector<int>& nums) {
        int temp=0;         //假定两个数是a和b
        for(auto i:nums){  //找到a和b异或后的结果
            temp^=i;
        }
        int flag=1;
        while((flag & temp)==0)
            flag<<=1;
        int a=0,b=0;
        for(auto i:nums){
            if((flag&i)==0)
                a^=i;
            else
                b^=i;
        }
        return vector<int>{a,b};
    }

};

int main(){
    vector<int> v={4,1,4,6};
    Solution s;
    s.singleNumbers(v);


    return 1;
}
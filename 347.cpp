#include<bits/stdc++.h>
using namespace std;


class Solution {
    static bool cmp(pair<int,int>& p1,pair<int,int>& p2){
        return p1.second>p2.second;
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //先使用map来存储每个数以及每个数出现的次数
        //使用vector来存储每个数字对，并按照第二个参数进行排序，
        //注意自己写的排序算法需要声明为static类型。
        unordered_map<int,int> m;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        vector<pair<int,int>> vec;
        for(auto i:m){
            vec.push_back(make_pair(i.first,i.second));
        }
        sort(vec.begin(),vec.end(),cmp);
        for(auto it=vec.begin();it<vec.begin()+k;it++){
            res.push_back(it->first);
        }
        return res;
    }
};

int main(){
    vector<int> vec={1,2,1,1,2,3};
    Solution s;
    s.topKFrequent(vec,2);

    return 0;
}
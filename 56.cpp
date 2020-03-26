#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //按照首个元素排序
        sort(intervals.begin(),intervals.end());
        vector<int> pre;
        vector<int> now;
        vector<vector<int>> res;
        if(intervals.size()==0)
            return res;
        vector<int> path;
        pre=intervals[0];
        for(int i=1;i<intervals.size();i++){
            now=intervals[i];
            if(pre[1]>=now[0]){//有交集
                if(pre[1]>now[1]){
                    //pre 不变
                }
                else
                {
                    path.clear();
                    path.push_back(pre[0]);
                    path.push_back(now[1]);
                    pre=path;
                }
                
            }
            else{//无交集
                res.push_back(pre);
                pre=intervals[i];
            }
        }
        res.push_back(pre);
        return res;
    }
};

int main(){
    Solution s;
    
    vector<vector<int>> vec={{1,4},{0,2},{3,5}};
    vector<vector<int>> res;
    res=s.merge(vec);
    for(auto i:res){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
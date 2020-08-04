#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<vector<int>> res;
    void push(int pre,int last){
        vector<int> path;
        for(int i=pre;i<=last;i++)
            path.push_back(i);
        res.push_back(path);
    }
    int helper(int pre,int last){
        int s=(pre+last)*(last-pre+1)/2;
        return s;
    }
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int pre=1,last=1+1;
        for(;last<=(target/2+1);last++){
            int s=helper(pre,last);
            if(s==target)
                push(pre,last);
            else if(s>target){
                pre++;
                last=pre;
            }

        }
        return res;
    }
};

int main(){

    int v=9;
    Solution s;
    s.findContinuousSequence(v);

    return 1;
}
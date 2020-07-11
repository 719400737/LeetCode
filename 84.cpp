#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {//使用最小栈来存储
        stack<int> s;
        int res=INT_MIN;
        int m=heights.size();
        if(m==0)
            return 0;
        s.push(0);
        for(int i=1;i<m;i++){
            while(!s.empty() && heights[s.top()]>heights[i]){
                int h=heights[s.top()];
                s.pop();
                int w=i;
                if(!s.empty())
                    w=i-s.top()-1;
                res=max(res,h*w);
                
            }
            s.push(i);
        }
        while(!s.empty()){
            int h=heights[s.top()];
            s.pop();
            int w=m;
            if(!s.empty())
                w=m-1-s.top();
            res=max(res,h*w);
        }
        return res;
    }
};

int main(){
    vector<int> vec={3,6,5,7,4,8,1};
    Solution s;
    int res=s.largestRectangleArea(vec);
    cout<<res<<endl;
    return 0;
}
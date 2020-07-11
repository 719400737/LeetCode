#include<bits/stdc++.h>
using namespace std;
class Solution {//借用最大矩形题的解决方法
public:
    int helper(vector<int>& heights) {
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
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        if(m==0)
            return 0;
        int n=matrix[0].size();
        int res=0;
        vector<int> v(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1')
                    v[j]+=1;
                else    v[j]=0;
            }
            res=max(res,helper(v));
        }
        return res;
    }
};

int main(){
    int a=0;
    cout<<a<<endl;

    return 0;
}
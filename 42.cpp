#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==0)
            return 0;
        vector<int> vec=height;
        sort(vec.begin(),vec.end());
        int len=vec.size();
        int h=vec[len-1];
        int l=0,r=0,i=0,j=0,res=0;
        while(i<len-1 && height[i]<height[i+1])//从0开始到最高点，计算可接的雨水
            i++;
        for(;i<len;){
            if(height[i]<h){
                l=height[i];
                while(l>=height[i])
                    res+=l-height[i++];
            }
            else
                break;
        }
        j=len-1;
        while(j>0 && height[j]<height[j-1])//从右开始到最高点，计算可以接的雨水
            j--;
        for(;j>=0;){
            if(height[j]<h){
                r=height[j];
                while(r>=height[j])
                    res+=r-height[j--];
            }
            else
                break;
        
        }
        for(int a=i;a<j;a++){ //最高点之间可以接的雨水
            res+=h-height[a];
        }

        return res;
    }
};

int main(){
    vector<int> vec={2,0,2};
    Solution s;
    int res=s.trap(vec);
    cout<<res<<endl;
    return 0;
}
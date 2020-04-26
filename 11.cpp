#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int first=0; //首
        int second=height.size()-1;//尾
        int res=0;
        while(first<second){
            res=max(res,(second-first)*min(height[first],height[second]));
            if(height[first]<height[second])
                first++;
            else{
                second--;
            }
        }
        return res;
    }
};

int main(){


    return 0;
}
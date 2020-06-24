#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {    //使用动态规划来解
public:
    int numTrees(int n) {
        if(n==1||n==2)
            return n;
        vector<int> res={0,1,2};
        int r=0;
        for(int i=3;i<=n;i++){// i为总数
            r=0;
            for(int j=1;j<=i;j++){ //j为根节点数
                if(res[j-1]==0||res[i-j]==0)
                {
                    r=r+res[j-1]+res[i-j];//当左右子树有空时，左树个数+右树个数
                }   
                else
                {
                    r=r+res[j-1]*res[i-j]; //左子树数×右子树数
                }
                
            }
            res.push_back(r);
        }
        return res.back();
    }
};

int main(){
    Solution s;
    int res=s.numTrees(8);
    cout<<res<<endl;
    return 0;
}
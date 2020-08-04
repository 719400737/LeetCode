#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int m=a.size();
        vector<vector<int>> v(m,vector<int>(m,1));
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                dp[i][j]=dp[i][j-1]*a[j];
            }
        }
    }
};

int main(){



    return 0;
}
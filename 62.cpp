#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        int a[100][100];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0||j==0){
                    a[i][j]=1;
                }
                else
                {
                    a[i][j]=a[i-1][j]+a[i][j-1];
                }
                
            }
        }
        return a[n-1][m-1];
    }
};

int main(){
    Solution s;
    int n=s.uniquePaths(7,3);
    cout<<n<<endl;
    return 0;
}
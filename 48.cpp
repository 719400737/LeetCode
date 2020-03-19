#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//in place rotate Matrix
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int s=matrix.size();
        int tmp;
        for(int i=0;i<s-1;i++){
            for(int j=i;j<s-1;j++){
                tmp=matrix[s-1-j][i];
                matrix[s-1-j][i]=matrix[s-1-i][s-1-j];
                matrix[s-1-i][s-1-j]=matrix[j][s-1-i];
                matrix[j][s-1-i]=matrix[i][j]; 
                matrix[i][j]=tmp;
            }
            
        }
    }
};

int main(){
    vector<vector<int>> M={{1,2,3},{4,5,6},{7,8,9}};
    for(auto i:M){
        for(auto j:i)
            cout<<j<<" ";
        cout<<endl;
    }
    Solution s;
    s.rotate(M);
    for(auto i:M){
        for(auto j:i)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
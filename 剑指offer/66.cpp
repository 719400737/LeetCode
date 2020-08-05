#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int m=a.size();
        vector<int> b(m,1); //画个表格，将对角线置1，借用备忘录的思想，计算下三角，和上三角的乘积
        for(int i=0;i<m;i++){
            if(i==0)
                continue;
            b[i]=a[i-1]*b[i-1];
        }
        int temp=1;
        for(int i=m-1;i>=0;i--){
            if(i==m-1)
                temp=1;
            else
                temp*=a[i+1];
            b[i]*=temp;
        }
        
        return b;
    }
};

int main(){
    vector<int> v={1,2,3,4,5};
    Solution s;
    v=s.constructArr(v);
    for(auto i:v)
        cout<<i<<endl;

    return 0;
}
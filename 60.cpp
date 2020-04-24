#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> vec;
        vec.push_back(1);
        for(int i=1;i<=n;i++){
            vec.push_back(i*vec[i-1]);
        }
        vector<int> cankao(n,1);
        for(int i=0;i<n;i++){
            cankao[i]=i+1;
        }
        int res=0;
        for(int z=n;z>0;z--){
            int i=k/vec[z-1];//vec中存放的是z-1的阶乘
            int j=k%vec[z-1];
            if(j==0){
                res=res*10+cankao[i-1];
                vector<int>::iterator it=cankao.begin()+i-1;
                cankao.erase(it);
                for(int i=cankao.size()-1;i>=0;i--){
                    res=res*10+cankao[i];
                }
                break;
            }
            else{
                res=res*10+cankao[i];
                vector<int>::iterator it=cankao.begin()+i;
                cankao.erase(it);
                k=j;
            }
            
        }
        string s;
        s=to_string(res);
        return s;
    }
};
int main(){

    Solution s;
    int n=3,k=3;
    string res;
    res=s.getPermutation(n,k);
   
    cout<<res<<endl;


    return 0;
}
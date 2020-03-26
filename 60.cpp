#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<long>  vec;
        vec.push_back(1);
        for(int i=1;i<=n;i++){
            vec.push_back(vec[i-1]*i);
        }
        vector<int> cankao;
        for(int i=0;i<n;i++){
            cankao.push_back(i+1);
        }
        int res=0;
        for(int z=n;z>=1;z--){
            int i=k/vec[z-1];
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
            };
            
        }
        string s;
        s=to_string(res);
        return s;
        //第一位为i+1；第二位为j
    }
};

int main(){
    Solution s;
    int n=1,k=1;
    string res;
    res=s.getPermutation(n,k);
   
    cout<<res<<endl;
    return 0;
}
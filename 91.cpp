#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0')
            return 0;
        vector<int> vec;
        int res=0;
        for(int i=0;i<s.size();i++){
            if(i==0){
                if(s[i]=='0')
                    vec.push_back(0);
                else
                    vec.push_back(1);    
            }
            else{
                //s[i]可以作为单独单位插入，也可以和前一个作为1体插入
                if(s[i]=='0'){//为0时，只能与前者作为一体插入
                    if(s[i-1]<='2'&&s[i-1]>'0'){
                        if(i-2>=0)
                            res=vec[i-2];
                        else
                            res=1;    
                    }
                    else{
                        res=0;
                        return res;
                    }
                    vec.push_back(res);    
                }
                else{//不为0，可以分两种情况
                    res=vec[i-1];
                    if(s[i-1]=='1'){
                        if(i-2>=0)
                            res=res+vec[i-2];
                        else
                            res++;
                    }
                    if(s[i-1]=='2'&&s[i]<'7'){
                        if(i-2>=0)
                            res=res+vec[i-2];
                        else
                            res++;
                    }
                    vec.push_back(res);
                }
            }  
        }
        res=vec[s.size()-1];
        return res;

    }
};
// class Solution {
// public:
//     int numDecodings(string s) {
//         if(s[0]=='0')
//             return 0;
//         vector<int> vec;
//         int res=0;

//         for(int i=0;i<s.size();i++){
//             int a=s[i]-'0';
//             int b=0;
//             string s1=s;
//             if(i>0){
//                 s1.substr(i-1,2);
//                 b=(int)s1;
//             }

//         }
//         res=vec[s.size()-1];
//         return res;

//     }
// };

int main(){
    Solution s;
    string s1="10111";
    int res=s.numDecodings(s1);
    cout<<res<<endl;
    return 0;
}
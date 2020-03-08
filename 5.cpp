#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string s("cbaabaa");
    int len=s.size();
    int cur;
    int r=0;
    //string res(begin(s)+1,begin(s)+3);
    string res;
    
    for(cur=0;cur<len;cur++){
        int qian=cur;
        int hou=cur;
        while(qian>=0&&hou<len&&s[qian]==s[hou]){
            qian--;
            hou++;
        }
        if((hou-qian-1)>r){
            r=hou-qian-1;
            res=s.substr(qian+1,r);
        }
   
    
        qian=cur;
        hou=cur+1;
        while(qian>=0&&hou<len&&s[qian]==s[hou]){
            qian--;
            hou++;
        }
        if((hou-qian-1)>r){
            r=hou-qian-1;
            res=s.substr(qian+1,r);
        }
    }
    cout<<res;
    return 0;
}
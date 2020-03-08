#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//遍历1遍，每次以遍历元素为中心，找两边元素是否相等，若不相等，则遍历后一个元素，若相等则继续遍历元素两边，获得最长的回文子串
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

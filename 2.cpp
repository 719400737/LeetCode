#include<bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* creatList(vector<int> vec){
    ListNode* head=new ListNode(vec[0]);
    ListNode* a=head;
    for(int i=1;i<vec.size();i++){
        ListNode* temp=new ListNode(vec[i]);
        a->next=temp;
        a=a->next;
    }
    return head;
}
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int tag=0;
        ListNode* prehead=new ListNode(0);
        ListNode* head=prehead;
        while(!l1 || !l2){
            int sum=0;
            if(l1){
                sum+= l1->val;
                l1=l1->next;
            }
            if(l2){
                sum+= l2->val;
                l2=l2->next;
            }
            sum+=tag;
            tag=sum/10;
            sum%=10;
            head->next=new ListNode(sum);
            head=head->next;
        }
        if(tag){
            head->next=new ListNode(1);
        } 
    return prehead->next;    
    }
};

int main(){
    vector<int> v1={5},v2={5};
    ListNode* h1=creatList(v1);
    ListNode* h2=creatList(v2);
    Solution s;
    s.addTwoNumbers(h1,h2);
    return 0;
}
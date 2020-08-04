#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* CreateList(vector<int> vec){
        if(vec.size()==0)
            return NULL;
        ListNode* prehead=new ListNode(-1);
        ListNode* cur=prehead;
        for(int i=0;i<vec.size();i++){
            cur->next=new ListNode(vec[i]);
            cur=cur->next;
        }
        ListNode* res=prehead->next;
        delete prehead;
        return res;
    }
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* prehead=new ListNode(-1);
        ListNode* cur=prehead;
        prehead->next=head;
        while(cur->next!=NULL){
            ListNode* temp=cur->next;
            if(cur->next->val==val){
                cur->next=cur->next->next;
                //delete temp;
                break;
            }
            cur=cur->next;
        }
        ListNode* res=prehead->next;
        delete prehead;
        return res;
    }
};

int main(){
    Solution s;
    vector<int> v{1,2,3};
    ListNode* head=s.CreateList(v);
    ListNode* res=s.deleteNode(head,1);


    return 1;
}
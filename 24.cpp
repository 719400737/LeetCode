#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* Creat(int a[],int N){
    ListNode *tail;
    ListNode *prehead=new ListNode(-1);
    ListNode *head=prehead;
    for(int i=0;i<N;i++){
        tail=new ListNode(a[i]);
        head->next=tail;
        head=tail;
    }
    return prehead->next;
}
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {//2个交换一次
        ListNode* prehead=new ListNode(0);
        prehead->next=head;
        if(!head)
            return prehead->next;
        ListNode* frist=prehead,*second=head->next;
        ListNode* temp1,*temp2;
        while (second)
        {
            temp1=frist->next;
            temp2=second->next;
            frist->next=second;
            second->next=temp1;
            temp1->next=temp2;

            frist=temp1;
            if(!temp2)
                second=NULL;
            else second=temp2->next;            
        }
        return prehead->next;
        
    }
};

int main(){

    int a2[]={};
    cout<<"Creat list"<<endl;
    ListNode *head2=Creat(a2,4);
    Solution s;
    
    s.swapPairs(head2);
    return 0;
}
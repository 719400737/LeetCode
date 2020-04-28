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
    ListNode* partition(ListNode* head, int x) {
        ListNode* prehead=new ListNode(0);
        prehead->next=head;
        ListNode* first=prehead;
        ListNode* second=prehead;
        
        while(second->next!=NULL){
            if(second->next->val<x){//判断second后面的元素大小 接在first后面
                if(second==first){
                    second=second->next;
                    first=first->next;
                }
                else{
                    ListNode* temp=second->next;
                    second->next=second->next->next;
                    ListNode* temp2=first->next;
                    first->next=temp;
                    first=temp;
                    first->next=temp2;
                }
            }
            else{
                second=second->next;
            }
        }
        return prehead->next;

    }
};

int main(){
    int a2[]={1,2,4,2};
    cout<<"Creat list"<<endl;
	ListNode *head=Creat(a2,4);
    Solution s;
    s.partition(head,3);

    return 0;
}
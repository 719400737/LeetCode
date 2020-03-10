#include<iostream>

using namespace std;
 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
//两次遍历
// ListNode* removeNthFromEnd(ListNode* head, int n) {
    
//     int i=0;
//     ListNode *prehead=new ListNode(-1);
//     prehead->next=head;
//     ListNode* cur=prehead;
//     while(cur->next){
//         cur=cur->next;
//         i++;
//     }
//     //i为链表长度
//     if(i<n)
//         return head;
//     cur=prehead;
//     for(int j=0;j<i-n;j++){
//         cur=cur->next;
//     }
//     cur->next=cur->next->next;
    
//     return prehead->next;


// }
//1次遍历双指针
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *prehead=new ListNode(-1);
    prehead->next=head;
    ListNode *first=prehead;
    ListNode *second=prehead;
    for(int i=0;i<n;i++){
        first=first->next;
    }
    while (first->next)
    {
        first=first->next;
        second=second->next;
    }
    second->next=second->next->next;
    return prehead->next;
}
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
	
int main(){

    int a2[]={1,3,5,8};
    cout<<"Creat list"<<endl;
	ListNode *head=Creat(a2,4);
    head=removeNthFromEnd(head,1);
	cout<<"l2 mumber :"<<endl;
	while(head){
		cout<<head->val<<" ";
		head=head->next;
	}
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
     int val;
   ListNode *next;
 ListNode() : val(0), next(nullptr) {}
 ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

void go_through(ListNode *p)
{
    while (p != nullptr) {
        std::cout << p->val <<" ";
        p = p->next;
    }
   std:: cout<<'\n';
}

void push_back(ListNode **head_ref,int data){
ListNode *head=new ListNode;
head->val=data;
head->next=nullptr;
(*head_ref)=head;
}
void append(ListNode **head,int data){
ListNode *node=new ListNode;
ListNode *bak=*head;
node->val=data;
node->next=nullptr;
if(*head==nullptr){
    *head=node;
    return;
}
while(bak->next!=nullptr)
    bak=bak->next;
bak->next=node;
return;
}
void delete_node(ListNode **head,int key){
ListNode *tmp=*head;
ListNode *prev=nullptr;
if(tmp!=nullptr&&tmp->val==key){
    *head=tmp->next;
    delete tmp;
    return;
}
else{
while(tmp!=nullptr&&tmp->val!=key){
        prev=tmp;
    tmp=tmp->next;
}
prev->next=tmp->next;
delete tmp;
}

}
ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p=head;
        while(head->next!=nullptr){
                int t=head->val;
                if(t==(head->next)->val){
                delete_node(&p,t);
                }
                head=head->next;
        }
        return p;

}
int main()
{
    ListNode A[5];
    for(int i = 0; i < 5; i++) {
        A[i].val = i+1;
        A[i].next = A + i + 1;
    }
    A[4].next = nullptr;
    A[3].val=5;
    A[2].val=5;
   ListNode *p=A;
    go_through(p);
    ListNode *k=deleteDuplicates(p);
    go_through(k);

    return 0;
}

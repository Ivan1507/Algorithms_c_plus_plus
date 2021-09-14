#include <bits/stdc++.h>
class Node_T{
	public:
	int val;
	Node_T *next;
};

struct ListNode{
	int val;
	ListNode *next;
	~ListNode(){
		delete next;
	}
	void push_back(ListNode **head,int data){	
		if(*head==nullptr){
			ListNode *n=new ListNode;
			*head=n;
			n->next=nullptr;
			n->val=data;
			return;
		}

		ListNode *newNode=new ListNode;
		newNode->val=data;
		newNode->next=nullptr;
		ListNode *tmp=*head;
		while(tmp->next!=nullptr){	
			tmp=tmp->next;
		}
		tmp->next=newNode;


	}
	void push_front(ListNode **head,int data){
		ListNode *newNode=new ListNode;
		newNode->val=data;
		newNode->next=*head;
		*head=newNode;
	}
	ListNode* insertionSortList(ListNode *head){
		ListNode *start=head;
		while(start->next!=nullptr){
			ListNode *tmp=start->next;
			
			ListNode *first=head;
			//std::cout<<first->val<<" ";
			if(first->val>tmp->val){
				ListNode *tmp1=tmp->next;
				//std::cout<<tmp1->val<<'\n';
				tmp->next=first;
				start->next=tmp1;
				head=tmp;
				start=tmp;
			}
			else if(tmp->val<start->val){
			while(tmp!=nullptr&&first->next!=tmp){
				if(first->next->val>tmp->val){
					ListNode *tmp1=tmp->next;
					tmp->next=first->next;
					first->next=tmp;
					start->next=tmp1;
					start=tmp;
					//std::cout<<start->val<<" "<<first->val<<'\n';
					//return head;
					break;
				}
				//std::cout<<"DEBAG!\n";
				first=first->next;
				//std::cout<<"DEBAG@\n";
			}
			}
			//return head;
			//go_through(head);
			//std::cout<<start->val<<'\n';
			start=start->next;
		}
		return head;
	}
	void reorderList(ListNode *head){
		if(head==nullptr||head->next==nullptr) return;
		ListNode *lp=head;
		ListNode *rp=head->next;
		ListNode *tmp=rp;
		while(rp!=nullptr&&rp->next!=nullptr){
			if(tmp->next->next==nullptr){
				lp->next=tmp->next;
				tmp->next=nullptr;
				lp=lp->next;
				lp->next=rp;
				rp=rp->next;
				lp=lp->next;
				tmp=rp;
			}
			else tmp=tmp->next;
		}	
	}
	void reverse(ListNode **head){
		ListNode *prev=nullptr;
		ListNode *current=*head;
		ListNode *next=nullptr;
		while(current!=nullptr){
			next=current->next;// we take the pointer on the next Node
			current->next=prev;// we change the next node of current Node
			prev=current;// Now previous Node is current
			current=next;//it's just a next step of our loop
		}
		*head=prev;
	}
	ListNode *oddEvenList(ListNode *head){
		if(head==nullptr) return nullptr;
		int i=1;
		ListNode *lp=head;// Our pointer to collect odd list
		ListNode *rp=head->next;// Our pointer to collect even list
		ListNode *evenHead=rp;
		while(rp!=nullptr&&rp->next!=nullptr){
			lp->next=rp->next;
			lp=lp->next;
			rp->next=lp->next;
			rp=rp->next;
		}
		lp->next=evenHead;
		return head;
	}
	void deleteNode(ListNode *node){
		ListNode *tmp=node->next;
		node->val=tmp->val;
		node->next=tmp->next;
		delete tmp;
	}
	void go_thr(){
		ListNode *tmp=this;
		while(tmp!=nullptr){
			std::cout<<tmp->val<<" ";
			tmp=tmp->next;
		}
		std::cout<<'\n';
	}
	void go_through(ListNode *head){
		ListNode *tmp=head;
		while(tmp!=nullptr){
			std::cout<<tmp->val<<" ";
			tmp=tmp->next;
		}
		std::cout<<'\n';
	}
};
int main(){
	std::list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_front(5);
	auto s=l.begin();
	auto e=l.end();
	ListNode *node=nullptr;
	node->push_back(&node,4);
	node->push_back(&node,2);
	node->push_back(&node,1);
	node->push_back(&node,3);
        node->push_back(&node,9);
	node->push_back(&node,6);
	node->push_back(&node,7);
	node->go_thr();
	//node->doMagic(node);
	ListNode *ans=node->insertionSortList(node);
	ans->go_thr();
	return 0;
}

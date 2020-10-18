#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int P=257;
struct Node{
int64_t value;
Node *next;
};
void push_back(Node **current_node, int64_t value){
Node *new_node=new Node();
new_node->value=value;
new_node->next=(*current_node);
(*current_node)=new_node;
}
Node* mergeLists(Node* first_node, Node *second_node)
{
    Node* result=nullptr;
    if(first_node==nullptr)
        return second_node;
    if(second_node==nullptr)
        return first_node;
    if(first_node->value==second_node->value){
        result=first_node;
        result->next=mergeLists(first_node->next,second_node->next);
    }
    else if(first_node->value<second_node->value){
        result=first_node;
        result->next=mergeLists(first_node->next,second_node);
    }

    else{
        result=second_node;
        result->next=mergeLists(first_node,second_node->next);
    }

    return result;
}

 uint32_t hash(string s){
     uint32_t sum=0;
     uint32_t factor=1;
 for(int i=s.length()-1;i>=0;i++){
    sum+=s[i]*factor;
    factor*=P;
 }
 }
 void printList(Node *node){
 while(node!=nullptr){
    cout<<node->value<<" ";
    node=node->next;
 }

 }
int main(){
    /*string s;
    string pattern;
     //std::getline(cin,s);
     //std::getline(cin,pattern);
     uint32_t pattern_hash=hash(pattern);

     uint32_t M=pattern.length();*/
     Node *A=nullptr;
     Node *B=nullptr;
     Node *res=nullptr;
     push_back(&A,3);
     push_back(&A,2);
     push_back(&A,1);
     push_back(&B,5);
     push_back(&B,4);
     push_back(&B,3);
     res=mergeLists(A,B);
    printList(res);
}

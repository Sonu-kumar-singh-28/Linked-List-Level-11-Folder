#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    Node(){
        this->data =0;
        this->next = NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

 void inseartathead(Node* &head,Node* &tail ,int data){
    Node* newnode = new Node(data);
    if(head == NULL){
        head= newnode;
        tail = newnode;
    }else{
        newnode->next = head;
        head = newnode;
    }
}

 void inseartattail(Node* &head,Node* &tail ,int data){
    Node* newnode = new Node(data);
    if(tail == NULL){
        head= newnode;
        tail = newnode;
    }else{
        tail->next = newnode;
        tail= newnode;
    }
}

void print(Node* head){
    Node* temp = head;
    while(temp !=NULL){
        cout<<temp->data << " " ;
        temp = temp->next;
    }
    cout<< endl;
}
// function for last node insert 
int findlength(Node* &head){
    int len =0 ;
    Node*temp  = head;
    while(temp!=NULL){
        temp= temp->next;
        len++;
    }
    return len;
}

void insertatposition(int position , Node* &head, Node* &tail, int data){
    Node* newnode = new Node(data);
    if(head ==NULL){
        head = newnode;
        tail = newnode;
    }
    // insert at first node;
    if(position==0){
         inseartathead(head,tail, data);
        return;
    }
    
    // insert at last node
    int len =findlength(head);
    if(position >=len){
       inseartattail(head,tail,data);
        return;
    }
    
 // Insert in the middle
    int i = 1;
    Node* prev = head;
    while(i < position){
        prev = prev->next;
        i++;
    }
    Node* curr = prev->next;

    newnode->next = curr;
    prev->next = newnode;
}
int main(){
Node* head = NULL;
Node* tail = NULL;
inseartathead(head,tail,10);
inseartathead(head,tail,20);
inseartathead(head,tail,30);
inseartathead(head,tail,40);
inseartathead(head,tail,50);
inseartathead(head,tail,60);

print(head);
 inseartattail(head, tail,156);
 print(head);
 
 insertatposition(5,head, tail,1258);
 print(head);
}
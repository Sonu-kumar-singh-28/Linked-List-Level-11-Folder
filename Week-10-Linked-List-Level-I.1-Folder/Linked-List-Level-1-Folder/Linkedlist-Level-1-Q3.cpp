#include<iostream>

// insert first and last 
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


void insertathead(Node* &head , Node* &tail , int data){
    //step1
    //create new node
    Node* newnode = new Node(data);

    //step 2;
    //new node create address to point 

    if(head == NULL){
       head = newnode;
       tail = newnode;
    }else{
        newnode->next = head;
        head = newnode;
    }
}

void insertattail(Node* &head, Node* &tail , int data){
    Node* newnode = new Node(data);

    if(tail==NULL){
        head = newnode;
        tail = newnode;
    }else{
        tail->next = newnode;
        tail = newnode;
    }
}

void print(Node* head){
    Node* temp = head;
    while(temp!= NULL){
        cout<<temp->data << " ";
        temp = temp->next;
    }
    cout<< endl;
}
int main(){
    Node* head = NULL;
    Node* tail = NULL;

    insertathead(head,tail,10);
    insertathead(head,tail,20);
    insertathead(head,tail,30);
    insertathead(head,tail,40);
    insertattail(head,tail,100);
    cout<<" The linked list is " << endl;
    print(head);
}
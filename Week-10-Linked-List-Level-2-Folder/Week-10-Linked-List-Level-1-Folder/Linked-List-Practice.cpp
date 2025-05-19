#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(){
        this->data =0;
        this->next =NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void inseartatfirst(Node* &head, Node* &tail, int data){
    Node* newnode = new Node(data);

    if(head == NULL){
        head = newnode;
        tail = newnode;
    }else{
        newnode->next = head;
        head = newnode;
    }
}

void inseartatlast(Node* &head, Node* &tail, int data){
    Node* newnode = new Node(data);
    if(tail == NULL){
        head = newnode;
        tail= newnode;
    }else{
        tail->next = newnode;
        tail = newnode;
    }
}


void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<< temp->data << " ";
        temp = temp->next;
    }
}

int findlen(Node* &head){
    int len=0;
    Node* temp = head;
    while(temp!=NULL){
         temp = temp->next;
         len++;
    }
   return len;
}


void insertatposition(int position, Node* &head, Node* &tail, int data){
    Node* newnode = new Node(data);

    if(position == 0){
        inseartatfirst(head,tail,data);
    }

    int len = findlen(head);

    if(position == len){
        inseartatlast(head, tail, data);
    }

    if(head == NULL){
        head = newnode;
        tail = newnode;
        return;
    }

    int i=1;
    Node* prev = head;
    while(i<position){
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

    inseartatfirst(head, tail, 100);
    inseartatfirst(head, tail, 200);
    inseartatfirst(head, tail, 300);
    inseartatfirst(head, tail, 400);
    cout<<" Printing linked-list Before last Inserctions"<< endl;
    print(head);

    cout<<endl;

    cout<<" Printing Linked-list after last Inserctions "<< endl;
    inseartatlast(head,tail,500);
    print(head);
    cout<< endl;

    cout<<"Insert at mid in the Linked-List" << endl;
    insertatposition(2,head,tail,1000);
    print(head);

}
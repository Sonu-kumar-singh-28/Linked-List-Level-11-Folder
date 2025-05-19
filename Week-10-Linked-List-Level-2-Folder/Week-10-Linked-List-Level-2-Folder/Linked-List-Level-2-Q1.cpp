// Double -Linkedlist 


#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(){
        this->data =0;
        this->prev = NULL;
        this->next = NULL;
    }

    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

int findlen(Node* &head){
    int len =0;
    Node* temp = head;
    while(temp!=NULL){
        temp = temp->next;
        len++;
    }
    return len;
}


void inseartatfirst(Node* &head, Node* &tail, int data){
    Node* newnode = new Node(data);
    if(head == NULL){
        head = newnode;
        tail = newnode;
    }else{
        newnode->next = head;
        head->prev= newnode;
        head = newnode;
    }
}

void inseartatlast(Node* &head, Node* &tail, int data){
    Node* newnode = new Node(data);

    if(tail == NULL){
        head = newnode;
        tail = newnode;
    }else{
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}
void inseartatmid(int position ,Node* &head, Node* &tail, int data){
    Node* newnode = new Node(data);

    if(head == NULL){
        head = newnode;
        tail = newnode;
        return;
    }

    // insert at start 
    if(position == 1){
        inseartatfirst(head, tail, data);
        return;
    }

    int len = findlen(head);
    if(position >= len){
        inseartatlast(head, tail, data);
        return;
    }

    // Insert at mid
    int i = 1; 
    Node* prevnode = head;
    while(i < position - 1){
        prevnode = prevnode->next;
        i++;
    }

    Node* curr = prevnode->next;

    prevnode->next = newnode;
    newnode->prev = prevnode;
    newnode->next = curr;
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}



int main(){
   Node* head = NULL;
   Node* tail = NULL;

   inseartatfirst(head, tail, 10);
   inseartatfirst(head, tail, 20);
   inseartatfirst(head, tail, 30);
   inseartatfirst(head, tail, 40);
   inseartatfirst(head, tail, 50);
 

// Node* first = new Node(10);
// Node* second = new Node(20);
// Node* third = new Node(30);

// first->next = second;
// second->prev = first;

// second->next = third;
// third->prev = second;



   cout<<" The printing linked-list is : " << endl;
   print(head);
   cout<< endl;

   cout<< " INsert at last " << endl;
    inseartatlast(head, tail, 100);
    print(head);

    cout<< " Insert at Position " << endl;

    inseartatmid(4,head,tail, 1500);
    print(head);
}
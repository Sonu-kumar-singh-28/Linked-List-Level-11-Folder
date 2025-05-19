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
        this->next =NULL;
    }

    Node(int data){
        this->data =data;
        this->prev = NULL;
        this->next = NULL;
    }
};


void inseartatfirst(Node* &start, Node* &end, int data){
    Node* newnode = new Node(data);
    if(start == NULL){
        start = newnode;
        end = newnode;
    }else{
        newnode->next = start;
        start->prev = newnode;
        start = newnode;
    }
}


void inseartatlast(Node* &start, Node* &end, int data){
    Node* newnode = new Node(data);
    if(end == NULL){
        start = newnode;
        end = newnode;
    }else{
        end->next = newnode;
        newnode->prev= end;
        end = newnode;
    }
}





void print(Node* &start){
    Node* temp = start;
    while(temp != NULL){
        cout<< temp->data << " ";
        temp = temp->next;
    }
}

int main(){
    Node* start = NULL;
    Node* end = NULL;

    inseartatfirst(start,end,10);
    inseartatfirst(start,end,20);
    inseartatfirst(start, end,30); 
    inseartatfirst(start,end,40);
    inseartatfirst(start,end,50);
    inseartatlast(start, end, 100);

    cout<< " Printing Linked-List is " << endl;
    print(start);

}
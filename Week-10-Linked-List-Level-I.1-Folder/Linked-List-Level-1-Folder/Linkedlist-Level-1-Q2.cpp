#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() {
        this->data = 0; 
        this->next = NULL;
    }

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertathead(Node* &head, int data) {
    Node* newnode = new Node(data);
    newnode->next = head;
    head = newnode;
}


void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    insertathead(head, 10);
    insertathead(head, 20);
    insertathead(head, 30);
    insertathead(head, 10);
    insertathead(head, 20);

    print(head);

    return 0;
}

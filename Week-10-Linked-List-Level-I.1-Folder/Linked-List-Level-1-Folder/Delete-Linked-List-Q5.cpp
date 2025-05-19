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

    ~Node() {
        cout << "Node with value " << this->data << " Deleted" << endl;
    }
};

void insertAtHead(Node*& head, Node*& tail, int data) {
    Node* newnode = new Node(data);
    if (head == NULL) {
        head = newnode;
        tail = newnode;
    } else {
        newnode->next = head;
        head = newnode;
    }
}

void insertAtTail(Node*& head, Node*& tail, int data) {
    Node* newnode = new Node(data);
    if (tail == NULL) {
        head = newnode;
        tail = newnode;
    } else {
        tail->next = newnode;
        tail = newnode;
    }
}

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int findLength(Node*& head) {
    int len = 0;
    Node* temp = head;
    while (temp != NULL) {
        temp = temp->next;
        len++;
    }
    return len;
}

void insertAtPosition(int position, Node*& head, Node*& tail, int data) {
    if (head == NULL || position == 0) {
        insertAtHead(head, tail, data);
        return;
    }

    int len = findLength(head);
    if (position >= len) {
        insertAtTail(head, tail, data);
        return;
    }

    Node* newnode = new Node(data);
    Node* prev = head;
    int i = 1;
    while (i < position) {
        prev = prev->next;
        i++;
    }

    newnode->next = prev->next;
    prev->next = newnode;
}

void deleteNode(int position, Node*& head, Node*& tail) {
    if (head == NULL) {
        cout << "Cannot delete, linked list is empty" << endl;
        return;
    }

    if (position == 1) {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;

        if (head == NULL) {
            tail = NULL;
        }
        return;
    }

    int len = findLength(head);
    if (position > len || position < 1) {
        cout << "Invalid position" << endl;
        return;
    }

    Node* prev = head;
    int i = 1;
    while (i < position - 1) {
        prev = prev->next;
        i++;
    }

    Node* curr = prev->next;
    prev->next = curr->next;

    if (curr == tail) {
        tail = prev;
    }

    curr->next = NULL;
    delete curr;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 10);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 50);
    insertAtHead(head, tail, 60);

    print(head);

    insertAtTail(head, tail, 156);
    print(head);

    insertAtPosition(5, head, tail, 1258);
    print(head);

    deleteNode(1, head, tail);  // delete head
    deleteNode(findLength(head), head, tail);  // delete tail
    deleteNode(3, head, tail);  // delete middle

    print(head);

    return 0;
}

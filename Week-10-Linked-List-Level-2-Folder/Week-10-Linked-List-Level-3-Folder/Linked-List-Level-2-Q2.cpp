#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node() {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }

    Node(int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node(){
        cout<< "Node With  Value " << this->data << " deleteted " << endl;
    }
};

int findlen(Node* &head) {
    int len = 0;
    Node* temp = head;
    while (temp != NULL) {
        temp = temp->next;
        len++;
    }
    return len;
}

void insertAtFirst(Node* &head, Node* &tail, int data) {
    Node* newnode = new Node(data);
    if (head == NULL) {
        head = newnode;
        tail = newnode;
    } else {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

void insertAtLast(Node* &head, Node* &tail, int data) {
    Node* newnode = new Node(data);
    if (tail == NULL) {
        head = newnode;
        tail = newnode;
    } else {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}

void insertAtMid(int position, Node* &head, Node* &tail, int data) {
    Node* newnode = new Node(data);
    if (head == NULL) {
        head = newnode;
        tail = newnode;
        return;
    }

    if (position == 1) {
        insertAtFirst(head, tail, data);
        return;
    }

    int len = findlen(head);
    if (position >= len + 1) {
        insertAtLast(head, tail, data);
        return;
    }

    int i = 1;
    Node* prevnode = head;
    while (i < position - 1) {
        prevnode = prevnode->next;
        i++;
    }

    Node* curr = prevnode->next;

    prevnode->next = newnode;
    newnode->prev = prevnode;
    newnode->next = curr;
    if (curr != NULL) {
        curr->prev = newnode;
    }
}

void deleteNode(int position, Node* &head, Node* &tail) {
    if (head == NULL) {
        cout << "Linked-List is Empty" << endl;
        return;
    }

    if (head->next == NULL) {
        Node* temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }

    if (position == 1) {
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
        return;
    }

    int len = findlen(head);
    if (position >= len) {
        Node* temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        temp->prev = NULL;
        delete temp;
        return;
    }

    // Delete in middle
    int i = 1;
    Node* left = head;
    while (i < position - 1) {
        left = left->next;
        i++;
    }

    Node* curr = left->next;
    Node* right = curr->next;

    left->next = right;
    right->prev = left;
    curr->next = NULL;
    curr->prev = NULL;
    delete curr;
}


void print(Node* &head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    insertAtFirst(head, tail, 10);
    insertAtFirst(head, tail, 20);
    insertAtFirst(head, tail, 30);
    insertAtFirst(head, tail, 40);
    insertAtFirst(head, tail, 50);

    cout << "The printing linked-list is: " << endl;
    print(head);

    cout << "\nInsert at last:" << endl;
    insertAtLast(head, tail, 100);
    print(head);

    cout << "\nInsert at position 4:" << endl;
    insertAtMid(4, head, tail, 1500);
    print(head);

    cout << "\nDelete node at position 1:" << endl;
    deleteNode(1, head, tail);
    print(head);

    cout << "\nDelete node at position 100 (last node):" << endl;
    deleteNode(100, head, tail);
    print(head);

    cout << "\nDelete node at position 3 (middle node):" << endl;
    deleteNode(3, head, tail);
    print(head);



    return 0;
}

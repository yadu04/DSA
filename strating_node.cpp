#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int data, Node* next = nullptr) {
        this->data = data;
        this->next = next;
    }
    Node(int data){
        this->data=data;
        next=nullptr;
    }
}
 Node* firstNode(Node *head){
        Node* fast=head;
        Node* slow=head;
        while(fast!=NULL || fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast)

        slow=head;
        while(slow!=head){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
    void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
};
int main() {
    // Create a sample linked list with a loop
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    node1-> next = node2;
    Node* node3 = new Node(3);
    node2-> next = node3;
    Node* node4 = new Node(4);
    node3->next = node4;
    Node* node5 = new Node(5);
    node4-> next = node5;

    // Make a loop from node5 to node2
    node5->next = node2;

    // Set the head of the linked list
    Node* head = node1;

    // Detect the loop in the linked list
    Node* loopStartNode = firstNode(head);

    if (loopStartNode) {
        cout << "Loop detected. Starting node of the loop is: "<< loopStartNode->data << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }

    return 0;
}

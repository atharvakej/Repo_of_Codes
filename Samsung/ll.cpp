#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    // Constructor with both data and next node
    Node(int data1, Node* next1) {
        this->data = data1;
        next = next1;
    }

    // Constructor with only data (assuming next is initially null)
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};
#include<iostream>
#include<climits>
using namespace std;

class node {
public:
    int data; 
    node* next;

    // Constructor
    node(int data) {
        this->data = data;
        next = nullptr;
    }
};

class stackusingLL {
    int size;
    node* head;

public:
    // Constructor
    stackusingLL() {
        head = nullptr;
        size = 0;
    }

    // Empty function
    bool isempty() {
        return size==0;
    }

    // Size function
    int Size() {
        return size;
    }

    // Insert function
    void push(int element) {
        node* newnode = new node(element);
        newnode->next = head; 
        head = newnode;
        size++;
    }

    // Delete function
    int pop() {
        if (isempty()) {
            cout << "stack is empty" << endl;
            return INT_MIN;
        }
        int top = head->data;
        node*temp=head;
        head = head->next;
        delete temp;
        size--;
        return top;
    }

    // Top function 
    int top() {
        if (isempty()) {
            cout << "stack is empty" << endl;
            return INT_MIN;
        }
        return head->data; 
    }
};

int main() {
    stackusingLL s1; // Corrected the object creation
    s1.push(1);
    cout << "Top element: " << s1.top() << endl;
    cout << "Size of stack: " << s1.Size() << endl;
    cout << "Popped element: " << s1.pop() << endl;
    cout << "Size of stack after pop: " << s1.Size() << endl;
    return 0;
}

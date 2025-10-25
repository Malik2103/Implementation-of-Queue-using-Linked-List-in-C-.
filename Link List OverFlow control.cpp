#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Queue class
class Queue {
private:
    Node* front;
    Node* rear;
    int count;        // to count number of elements
    int maxSize;      // limit for overflow

public:
    // Constructor
    Queue(int size = 5) { // default max size = 5
        front = rear = NULL;
        count = 0;
        maxSize = size;
    }

    // Function to check if queue is empty
    bool isEmpty() {
        return (front == NULL);
    }

    // Function to check if queue is full
    bool isFull() {
        return (count == maxSize);
    }

    // Enqueue (Insert element)
    void enQueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot insert " << value << endl;
            return;
        }

        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        if (rear == NULL) { // first element
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        count++;
        cout << value << " inserted into Queue." << endl;
    }

    // Dequeue (Remove element)
    void deQueue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Nothing to remove." << endl;
            return;
        }

        Node* temp = front;
        cout << temp->data << " removed from Queue." << endl;
        front = front->next;

        delete temp;
        count--;

        if (front == NULL)
            rear = NULL;
    }

    // Display all elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty." << endl;
            return;
        }

        Node* temp = front;
        cout << "Queue elements: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Count elements
    void totalElements() {
        cout << "Total elements in Queue: " << count << endl;
    }

    // Clear entire queue
    void clearQueue() {
        while (!isEmpty()) {
            deQueue();
        }
        cout << "Queue cleared successfully." << endl;
    }
};

// Main function
int main() {
    Queue q(5); // max size = 5

    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);
    q.enQueue(60);  // should show overflow

    q.display();
    q.totalElements();

    q.deQueue();
    q.deQueue();

    q.display();
    q.totalElements();

    q.clearQueue();
    q.display();

    return 0;
}

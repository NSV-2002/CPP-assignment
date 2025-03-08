#include <iostream>
#include <vector>
using namespace std;

// Abstract Base Class: LIST
class LIST {
public:
    virtual void store(int value) = 0;   // Pure virtual function
    virtual int retrieve() = 0;         // Pure virtual function
    virtual ~LIST() {}                   // Virtual destructor
};

// Derived Class: Stack (LIFO)
class Stack : public LIST {
    vector<int> stack;
public:
    void store(int value) override {
        stack.push_back(value);
    }
    int retrieve() override {
        if (stack.empty()) {
            cout << "Stack Underflow!\n";
            return -1;
        }
        int top = stack.back();
        stack.pop_back();
        return top;
    }
};

// Derived Class: Queue (FIFO)
class Queue : public LIST {
    vector<int> queue;
public:
    void store(int value) override {
        queue.push_back(value);
    }
    int retrieve() override {
        if (queue.empty()) {
            cout << "Queue Underflow!\n";
            return -1;
        }
        int front = queue.front();
        queue.erase(queue.begin());
        return front;
    }
};

// Main Function
int main() {
    LIST* s = new Stack();  // Stack object via LIST pointer
    LIST* q = new Queue();  // Queue object via LIST pointer

    // Store values
    s->store(10); s->store(20); s->store(30);
    q->store(100); q->store(200); q->store(300);

    // Retrieve values
    cout << "Stack Pop: " << s->retrieve() << endl;
    cout << "Stack Pop: " << s->retrieve() << endl;
    cout << "Queue Dequeue: " << q->retrieve() << endl;
    cout << "Queue Dequeue: " << q->retrieve() << endl;

    delete s; // Free memory
    delete q; // Free memory
    return 0;
}

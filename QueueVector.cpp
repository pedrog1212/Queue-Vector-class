#include <iostream>
#include <vector>
using namespace std;

class Queue {
private:
    int size;
    int front;
    int rear;
    vector<int> Q;

public:
    Queue();
    void enqueue(int x);
    int dequeue();
    void display();
};

Queue::Queue() {
    cout << "Enter the size of the queue: ";
    cin >> size;
    size++;
    Q.resize(size);
    front = 0;
    rear = 0;
}

void Queue::enqueue(int x) {
    if ((rear + 1) % size == front) {
        cout << "Queue is full\n";
    } else {
        rear = (rear + 1) % size;
        Q[rear] = x;
    }
}

int Queue::dequeue() {
    int x = -1;
    if (front == rear) {
        cout << "Queue is empty\n";
    } else {
        front = (front + 1) % size;
        x = Q[front];
    }
    return x;
}

void Queue::display() {
    if (front == rear) {
        cout << "Queue is empty\n";
        return;
    }
    int i = (front + 1) % size;
    do {
        cout << Q[i] << " ";
        i = (i + 1) % size;
    } while (i != (rear + 1) % size);
    cout << "\n";
}

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(67);
    cout << "Deleted " << q.dequeue() << endl;
    cout << "Deleted " << q.dequeue() << endl;
    q.display();
    return 0;
}

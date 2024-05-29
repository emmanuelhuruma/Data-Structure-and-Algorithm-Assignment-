#include <iostream>
#include <queue>
#include <stdexcept>

class Queue {
public:
    
    void enqueue(int item) {
        items.push(item);
    }
    
    
    int dequeue() {
        if (items.empty()) {
            throw std::out_of_range("Dequeue from an empty queue");
        }
        int front = items.front();
        items.pop();
        return front;
    }

    
    bool isEmpty() const {
        return items.empty();
    }


    int size() const {
        return items.size();
    }

    
    int peek() const {
        if (items.empty()) {
            throw std::out_of_range("Peek from an empty queue");
        }
        return items.front();
    }

    
    void print() const {
        std::queue<int> temp = items; 
        std::cout << "Queue: ";
        while (!temp.empty()) {
            std::cout << temp.front() << " ";
            temp.pop();
        }
        std::cout << std::endl;
    }

private:
    std::queue<int> items;
};


int main() {
    Queue queue;

    
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    std::cout << "Queue after enqueuing 10, 20, 30: ";
    queue.print();

    
    int item1 = queue.dequeue();
    std::cout << "Dequeued item: " << item1 << std::endl;
    std::cout << "Queue after dequeuing an item: ";
    queue.print();

    
    int item2 = queue.peek();
    std::cout << "Next item to be dequeued (peek): " << item2 << std::endl;

    
    int item3 = queue.dequeue();
    int item4 = queue.dequeue();

    std::cout << "Dequeued items: " << item3 << ", " << item4 << std::endl;
    std::cout << "Queue after dequeuing all items: ";
    queue.print();

    return 0;
}
    
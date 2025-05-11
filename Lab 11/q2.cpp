#include<iostream>
#include<exception>
using namespace std;

class QueueFullException : public exception {};
class QueueEmptyException : public exception {};

template<typename T>
class CircularQueue {
private:
    T* items;
    int frontIndex, rearIndex, elementCount;
    int maxSize;

public:
    CircularQueue(int size) : maxSize(size), frontIndex(0), rearIndex(0), elementCount(0) {
        items = new T[maxSize];
    }

    ~CircularQueue() {
        delete[] items;
    }

    void add(T element) {
        if (elementCount == maxSize) {
            throw QueueFullException();
        }
        items[rearIndex] = element;
        rearIndex = (rearIndex + 1) % maxSize;
        elementCount++;
    }

    T remove() {
        if (elementCount == 0) {
            throw QueueEmptyException();
        }
        T temp = items[frontIndex];
        frontIndex = (frontIndex + 1) % maxSize;
        elementCount--;
        return temp;
    }

    bool empty() {
        return elementCount == 0;
    }

    bool full() {
        return elementCount == maxSize;
    }

    int length() {
        return elementCount;
    }
};

int main() {
    CircularQueue<int> queue(3);

    try {
        cout << "Inserting elements..." << endl;
        queue.add(5);
        queue.add(15);
        queue.add(25);
        queue.add(35);
    } catch (QueueFullException& e) {
        cout << "Queue capacity reached!" << endl;
        cout << "Details: " << e.what() << endl;
    }

    try {
        cout << "Removing entries:" << endl;
        cout << queue.remove() << endl;
        cout << queue.remove() << endl;
        cout << queue.remove() << endl;
        cout << "Trying to remove again..." << endl;
        cout << queue.remove() << endl;
    } catch (QueueEmptyException& e) {
        cout << "Queue is empty now!" << endl;
        cout << "Details: " << e.what() << endl;
    }

    return 0;
}

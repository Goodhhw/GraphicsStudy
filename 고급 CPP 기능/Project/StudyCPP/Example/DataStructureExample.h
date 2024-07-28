#pragma once
#include "BaseExample.h"

// Stack 클래스 정의
template <typename T>
class Stack {
public:
    Stack(size_t initialSize = 10)
        : capacity(initialSize), topIndex(-1), elements(new T[initialSize]) {}

    ~Stack() {
        delete[] elements;
    }

    void push(const T& item) {
        if (isFull()) {
            resize(capacity * 2);
        }
        elements[++topIndex] = item;
    }

    void pop() {
        if (isEmpty()) {
            throw std::out_of_range("Stack<>::pop(): empty stack");
        }
        --topIndex;
    }

    T top() const {
        if (isEmpty()) {
            throw std::out_of_range("Stack<>::top(): empty stack");
        }
        return elements[topIndex];
    }

    bool isEmpty() const {
        return topIndex == -1;
    }

    bool isFull() const {
        return topIndex == capacity - 1;
    }

    size_t size() const {
        return topIndex + 1;
    }

    size_t getCapacity() const {
        return capacity;
    }

private:
    void resize(size_t newCapacity) {
        T* newElements = new T[newCapacity];
        for (size_t i = 0; i <= topIndex; ++i) {
            newElements[i] = elements[i];
        }
        delete[] elements;
        elements = newElements;
        capacity = newCapacity;
    }

    size_t capacity;
    int topIndex;
    T* elements;
};

template <typename T>
class Queue {
public:
    Queue(size_t initialSize = 10)
        : capacity(initialSize), frontIndex(0), backIndex(0), itemCount(0), elements(new T[initialSize]) {}

    ~Queue() {
        delete[] elements;
    }

    void enqueue(const T& item) {
        if (isFull()) {
            resize(capacity * 2);
        }
        elements[backIndex] = item;
        backIndex = (backIndex + 1) % capacity;
        ++itemCount;
    }

    void dequeue() {
        if (isEmpty()) {
            throw std::out_of_range("Queue<>::dequeue(): empty queue");
        }
        frontIndex = (frontIndex + 1) % capacity;
        --itemCount;
    }

    T front() const {
        if (isEmpty()) {
            throw std::out_of_range("Queue<>::front(): empty queue");
        }
        return elements[frontIndex];
    }

    bool isEmpty() const {
        return itemCount == 0;
    }

    bool isFull() const {
        return itemCount == capacity;
    }

    size_t size() const {
        return itemCount;
    }

    size_t getCapacity() const {
        return capacity;
    }

private:
    void resize(size_t newCapacity) {
        T* newElements = new T[newCapacity];
        for (size_t i = 0; i < itemCount; ++i) {
            newElements[i] = elements[(frontIndex + i) % capacity];
        }
        delete[] elements;
        elements = newElements;
        frontIndex = 0;
        backIndex = itemCount;
        capacity = newCapacity;
    }

    size_t capacity;
    int frontIndex;
    int backIndex;
    int itemCount;
    T* elements;
};

class DataStructureExample : public ExampleBase
{
public:

protected:
    virtual void ChildRun() override
    {
        // 스택 테스트
        Stack<int> stack;
        stack.push(1);
        stack.push(2);
        stack.push(3);
        std::cout << "Stack top: " << stack.top() << std::endl;
        stack.pop();
        std::cout << "Stack top after pop: " << stack.top() << std::endl;

        // 큐 테스트
        Queue<int> queue;
        queue.enqueue(1);
        queue.enqueue(2);
        queue.enqueue(3);
        std::cout << "Queue front: " << queue.front() << std::endl;
        queue.dequeue();
        std::cout << "Queue front after dequeue: " << queue.front() << std::endl;

    }

    virtual string getTitle() const override
    {
        return "DataStructureExample";
    }
};

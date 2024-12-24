#pragma once
#include <iomanip>
#include <iostream>
#include <string>

#define MAX_TRANSPORT 10

template <typename T>
struct StackElement
{
    T data;
    StackElement* next;
};

template <typename T>
class Stack
{
private:
    
    StackElement<T>* top;
    int count;

public:
    Stack() : top(nullptr), count(0) {};
    void push(T data);
    void pop();
    T peek();
    bool isEmpty();
    int size();
    void print();
    ;
};

// ����� push: ��������� ������� � ����
template <typename T>
void Stack<T>::push(T data) {
    StackElement<T>* newElement = new StackElement<T>{ data, top };
    top = newElement;
    count++;
}

// ����� pop: ������� ������� � ������� �����
template <typename T>
void Stack<T>::pop() {
    if (isEmpty()){
        std::cerr << "Error: Stack is empty. Cannot pop." << std::endl;
        return;
    }

    StackElement<T>* oldTop = top;
    top = top->next;
    delete oldTop;
    count--;
}

// ����� peek: ���������� ������� �� ������� �����
template <typename T>
T Stack<T>::peek() {
    if (isEmpty()) {
        std::cerr << "Error: Stack is empty. Cannot peek." << std::endl;
    }
    return top->data;
}

// ����� isEmpty: ���������, ���� �� ����
template <typename T>
bool Stack<T>::isEmpty() {
    return top == nullptr;
}

// ����� size: ���������� ���������� ��������� � �����
template <typename T>
int Stack<T>::size() {
    return count;
}

template <typename T>
void Stack<T>::print()
{
    if (isEmpty())
    {
        std::cout << "Stack is empty" << std::endl;
        return;
    }

    StackElement<T>* current = top;

    std::string data;

    current->data.printHead();

    while (current != nullptr)
    {
        std::cout << current->data;
        current = current->next;
    }
}
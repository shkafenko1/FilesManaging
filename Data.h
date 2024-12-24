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

// Метод push: добавляет элемент в стек
template <typename T>
void Stack<T>::push(T data) {
    StackElement<T>* newElement = new StackElement<T>{ data, top };
    top = newElement;
    count++;
}

// Метод pop: удаляет элемент с вершины стека
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

// Метод peek: возвращает элемент на вершине стека
template <typename T>
T Stack<T>::peek() {
    if (isEmpty()) {
        std::cerr << "Error: Stack is empty. Cannot peek." << std::endl;
    }
    return top->data;
}

// Метод isEmpty: проверяет, пуст ли стек
template <typename T>
bool Stack<T>::isEmpty() {
    return top == nullptr;
}

// Метод size: возвращает количество элементов в стеке
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
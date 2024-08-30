#pragma once
#include <iostream>
#include <stdexcept>

template<typename T>
class NodeS
{
public:
    T data;
    NodeS<T>* next;

    NodeS(T value) : data(value), next(nullptr) {}
};

template<typename T>
class Stack
{
public:
    Stack() : m_top(nullptr), m_size(0) {}

    ~Stack() 
    {
        while (m_top) 
        {
            NodeS<T>* temp = m_top;
            m_top = m_top->next;
            delete temp;
        }
    }

    void push(T value) 
    {
        NodeS<T>* newNode = new NodeS<T>(value);
        newNode->next = m_top;
        m_top = newNode;
        ++m_size;
    }

    void pop() 
    {
        if (isEmpty()) 
        {
            throw std::out_of_range("Stack is empty");
        }

        NodeS<T>* temp = m_top;
        m_top = m_top->next;
        delete temp;
        --m_size;
    }

    T peek() const 
    {
        if (isEmpty()) 
        {
            throw std::out_of_range("Stack is empty");
        }
        return m_top->data;
    }

    bool isEmpty() const 
    {
        return m_size == 0;
    }

    size_t size() const 
    {
        return m_size;
    }

    void print() const 
    {
        NodeS<T>* current = m_top;
        while (current) 
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

private:
    NodeS<T>* m_top;
    size_t m_size;
};

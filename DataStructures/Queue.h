#pragma once
#include <iostream>
#include <stdexcept>

template<typename T>
class NodeQ
{
public:
    T data;
    NodeQ<T>* next;

    NodeQ(T value) : data(value), next(nullptr) {}
};

template<typename T>
class Queue
{
public:
    Queue() : m_front(nullptr), m_back(nullptr), m_size(0) {}

    ~Queue() 
    {
        while (m_front) 
        {
            NodeQ<T>* temp = m_front;
            m_front = m_front->next;
            delete temp;
        }
    }

    void enqueue(T value) 
    {
        NodeQ<T>* newNode = new NodeQ<T>(value);
        if (m_back) 
        {
            m_back->next = newNode;
        } 
        else 
        {
            m_front = newNode;
        }
        m_back = newNode;
        ++m_size;
    }

    void dequeue() 
    {
        if (isEmpty()) 
        {
            throw std::out_of_range("Queue is empty");
        }

        NodeQ<T>* temp = m_front;
        m_front = m_front->next;
        if (m_front == nullptr) 
        {
            m_back = nullptr;
        }
        delete temp;
        --m_size;
    }

    T front() const 
    {
        if (isEmpty()) 
        {
            throw std::out_of_range("Queue is empty");
        }
        return m_front->data;
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
        NodeQ<T>* current = m_front;
        while (current) 
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

private:
    NodeQ<T>* m_front;
    NodeQ<T>* m_back;
    size_t m_size;
};


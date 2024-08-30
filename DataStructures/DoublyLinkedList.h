#pragma once
#include <iostream>
#include <stdexcept>

template<typename T>
class NodeDLL
{
public:
    T data;
    NodeDLL<T>* next;
    NodeDLL<T>* prev;

    NodeDLL(T value) : data(value), next(nullptr), prev(nullptr) {}
};

template<typename T>
class DoublyLinkedList
{
public:
    DoublyLinkedList() : m_count(0), m_head(nullptr), m_tail(nullptr) {}

    DoublyLinkedList(T value) 
        : m_head(new NodeDLL<T>(value)), 
          m_tail(m_head), 
          m_count(1) {}

    ~DoublyLinkedList() 
    {
        clear(); // Manually clear the linked list to free memory
    }

    DoublyLinkedList(const DoublyLinkedList&) = delete; // Prevent copying
    DoublyLinkedList& operator=(const DoublyLinkedList&) = delete; // Prevent assignment

    DoublyLinkedList(DoublyLinkedList&& other) noexcept 
        : m_head(other.m_head), m_tail(other.m_tail), m_count(other.m_count) 
    {
        other.m_head = nullptr;
        other.m_tail = nullptr;
        other.m_count = 0;
    }

    DoublyLinkedList& operator=(DoublyLinkedList&& other) noexcept 
    {
        if (this != &other) 
        {
            clear(); // Clear the current list
            
            // Transfer ownership
            m_head = other.m_head;
            m_tail = other.m_tail;
            m_count = other.m_count;

            other.m_head = nullptr;
            other.m_tail = nullptr;
            other.m_count = 0;
        }
        return *this;
    }

    uint8_t num() const { return m_count; }

    void append(T value) 
    {
        NodeDLL<T>* newNode = new NodeDLL<T>(value);
        if (m_tail) 
        {
            m_tail->next = newNode;
            newNode->prev = m_tail;
            m_tail = newNode;
        } 
        else 
        {
            m_head = m_tail = newNode;
        }
        ++m_count;
    }

    void set(size_t index, T value) 
    {
        if (index >= m_count) 
        {
            throw std::out_of_range("Index out of bounds");
        }

        NodeDLL<T>* current = m_head;
        for (size_t i = 0; i < index; ++i) 
        {
            current = current->next;
        }
        current->data = value;
    }

    void reverse() 
    {
        if (m_count <= 1) 
        {
            // No need to reverse if the list is empty or has only one element
            return;
        }

        NodeDLL<T>* current = m_head;
        NodeDLL<T>* temp = nullptr;

        m_tail = m_head; // The original head will become the new tail

        while (current != nullptr) 
        {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        if (temp != nullptr) 
        {
            m_head = temp->prev;
        }
    }

    bool remove(T value) 
    {
        NodeDLL<T>* current = m_head;

        while (current) 
        {
            if (current->data == value) 
            {
                if (current->prev) 
                {
                    current->prev->next = current->next;
                } 
                else 
                {
                    m_head = current->next;
                }

                if (current->next) 
                {
                    current->next->prev = current->prev;
                } 
                else 
                {
                    m_tail = current->prev;
                }

                delete current; // Free the memory
                --m_count;
                return true;
            }
            current = current->next;
        }
        return false; // Value not found
    }

    bool isEmpty() const 
    {
        return m_count == 0;
    }

    bool find(T value) const 
    {
        NodeDLL<T>* current = m_head;
        while (current) 
        {
            if (current->data == value) 
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void clear() 
    {
        while (m_head) 
        {
            NodeDLL<T>* temp = m_head;
            m_head = m_head->next;
            delete temp;
        }
        m_tail = nullptr;
        m_count = 0;
    }

    T get(size_t index) const 
    {
        if (index >= m_count) 
        {
            throw std::out_of_range("Index out of bounds");
        }

        NodeDLL<T>* current = m_head;
        for (size_t i = 0; i < index; ++i) 
        {
            current = current->next;
        }
        return current->data;
    }

    void insert(size_t index, T value) 
    {
        if (index > m_count) 
        {
            throw std::out_of_range("Index out of bounds");
        }

        NodeDLL<T>* newNode = new NodeDLL<T>(value);

        if (index == 0) 
        {
            newNode->next = m_head;
            if (m_head) 
            {
                m_head->prev = newNode;
            }
            m_head = newNode;
            if (m_count == 0) 
            {
                m_tail = m_head;
            }
        } 
        else 
        {
            NodeDLL<T>* current = m_head;

            for (size_t i = 0; i < index - 1; ++i) 
            {
                current = current->next;
            }

            newNode->next = current->next;
            newNode->prev = current;

            if (current->next) 
            {
                current->next->prev = newNode;
            }
            current->next = newNode;

            if (newNode->next == nullptr) 
            {
                m_tail = newNode;
            }
        }

        ++m_count;
    }

    void print() const 
    {
        NodeDLL<T>* current = m_head;
        while (current) 
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

private:
    uint8_t m_count;
    NodeDLL<T>* m_head;
    NodeDLL<T>* m_tail;
};

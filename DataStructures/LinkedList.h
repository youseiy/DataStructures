
#include <iostream>
#include <stdexcept>

template<typename T>
class Node
{
public:
    T data;
    Node<T>* next;

    Node(T value) : data(value), next(nullptr) {}
};

template<typename T>
class LinkedList
{
public:
    LinkedList() : m_count(0), m_head(nullptr), m_tail(nullptr) {}

    LinkedList(T value) 
        : m_head(new Node<T>(value)), 
          m_tail(m_head), 
          m_count(1) {}

    ~LinkedList() 
    {
        clear(); // free memory
    }

    LinkedList(const LinkedList&) = delete; // Prevent copying
    LinkedList& operator=(const LinkedList&) = delete; // Prevent assignment

    LinkedList(LinkedList&& other) noexcept 
        : m_head(other.m_head), m_tail(other.m_tail), m_count(other.m_count) 
    {
        other.m_head = nullptr;
        other.m_tail = nullptr;
        other.m_count = 0;
    }

    LinkedList& operator=(LinkedList&& other) noexcept 
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
        Node<T>* newNode = new Node<T>(value);
        if (m_tail) 
        {
            m_tail->next = newNode;
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

        Node<T>* current = m_head;
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

        Node<T>* prev = nullptr;
        Node<T>* current = m_head;
        Node<T>* next = nullptr;

        m_tail = m_head; // The original head will become the new tail

        while (current != nullptr) 
        {
            next = current->next; // Store next node
            current->next = prev; // Reverse the link
            prev = current; // Move prev up
            current = next; // Move current up
        }

        m_head = prev; // Update the head to the new first node
    }

    bool remove(T value) 
    {
        Node<T>* current = m_head;
        Node<T>* previous = nullptr;

        while (current) 
        {
            if (current->data == value) 
            {
                if (previous) 
                {
                    previous->next = current->next;
                    if (current == m_tail) 
                    {
                        m_tail = previous;
                    }
                } 
                else 
                {
                    m_head = current->next;
                    if (m_head == nullptr) 
                    {
                        m_tail = nullptr;
                    }
                }
                delete current; // Free the memory
                --m_count;
                return true;
            }
            previous = current;
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
        Node<T>* current = m_head;
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
            Node<T>* temp = m_head;
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

        Node<T>* current = m_head;
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

        Node<T>* newNode = new Node<T>(value);

        if (index == 0) 
        {
            newNode->next = m_head;
            m_head = newNode;
            if (m_count == 0) 
            {
                m_tail = m_head;
            }
        } 
        else 
        {
            Node<T>* current = m_head;
            Node<T>* previous = nullptr;

            for (size_t i = 0; i < index; ++i) 
            {
                previous = current;
                current = current->next;
            }

            newNode->next = current;
            if (previous) 
            {
                previous->next = newNode;
            }
            if (current == nullptr) 
            {
                m_tail = newNode;
            }
        }

        ++m_count;
    }

    void print() const 
    {
        Node<T>* current = m_head;
        while (current) 
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

private:
    uint8_t m_count;
    Node<T>* m_head;
    Node<T>* m_tail;
};

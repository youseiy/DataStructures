#pragma once
#include <iostream>
#include <vector>

template<typename T>
class Heap
{
public:
    Heap() = default;

    void insert(T value) 
    {
        data.push_back(value);
        heapifyUp(data.size() - 1);
    }

    T extractMax() 
    {
        if (data.empty()) 
        {
            throw std::runtime_error("Heap is empty");
        }

        T maxValue = data.front();
        data[0] = data.back();
        data.pop_back();
        heapifyDown(0);
        return maxValue;
    }

    T peekMax() const 
    {
        if (data.empty()) 
        {
            throw std::runtime_error("Heap is empty");
        }
        return data.front();
    }

    bool isEmpty() const 
    {
        return data.empty();
    }

    size_t size() const 
    {
        return data.size();
    }

    void print() const 
    {
        for (const T& value : data) 
        {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

private:
    std::vector<T> data;

    void heapifyUp(size_t index) 
    {
        while (index > 0) 
        {
            size_t parentIndex = (index - 1) / 2;
            if (data[index] <= data[parentIndex]) 
            {
                break;
            }
            std::swap(data[index], data[parentIndex]);
            index = parentIndex;
        }
    }

    void heapifyDown(size_t index) 
    {
        size_t leftChild, rightChild, largest;
        while (true) 
        {
            leftChild = 2 * index + 1;
            rightChild = 2 * index + 2;
            largest = index;

            if (leftChild < data.size() && data[leftChild] > data[largest]) 
            {
                largest = leftChild;
            }

            if (rightChild < data.size() && data[rightChild] > data[largest]) 
            {
                largest = rightChild;
            }

            if (largest == index) 
            {
                break;
            }

            std::swap(data[index], data[largest]);
            index = largest;
        }
    }
};

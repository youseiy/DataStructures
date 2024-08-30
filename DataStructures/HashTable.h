#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <utility> // for std::pair

template<typename K, typename V>
class HashTable
{
public:
    HashTable(size_t size = 10) : table(size) {}

    void insert(const K& key, const V& value) 
    {
        size_t hashValue = hashFunction(key);
        for (auto& pair : table[hashValue]) 
        {
            if (pair.first == key) 
            {
                pair.second = value; // Update the value if key already exists
                return;
            }
        }
        table[hashValue].emplace_back(key, value);
    }

    bool find(const K& key, V& value) const 
    {
        size_t hashValue = hashFunction(key);
        for (const auto& pair : table[hashValue]) 
        {
            if (pair.first == key) 
            {
                value = pair.second;
                return true;
            }
        }
        return false;
    }

    void remove(const K& key) 
    {
        size_t hashValue = hashFunction(key);
        auto& chain = table[hashValue];
        for (auto it = chain.begin(); it != chain.end(); ++it) 
        {
            if (it->first == key) 
            {
                chain.erase(it);
                return;
            }
        }
    }

    bool isEmpty() const 
    {
        for (const auto& chain : table) 
        {
            if (!chain.empty()) 
            {
                return false;
            }
        }
        return true;
    }

    void print() const 
    {
        for (size_t i = 0; i < table.size(); ++i) 
        {
            std::cout << "Bucket " << i << ": ";
            for (const auto& pair : table[i]) 
            {
                std::cout << "[" << pair.first << ": " << pair.second << "] ";
            }
            std::cout << std::endl;
        }
    }

private:
    std::vector<std::list<std::pair<K, V>>> table;

    size_t hashFunction(const K& key) const 
    {
        return std::hash<K>()(key) % table.size();
    }
};

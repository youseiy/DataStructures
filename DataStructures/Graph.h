#pragma once
#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <vector>

template<typename T>
class Graph
{
public:
    void addVertex(const T& vertex) 
    {
        adjacencyList[vertex]; // Add vertex to the graph
    }

    void addEdge(const T& vertex1, const T& vertex2, bool bidirectional = true) 
    {
        adjacencyList[vertex1].push_back(vertex2);
        if (bidirectional) 
        {
            adjacencyList[vertex2].push_back(vertex1);
        }
    }

    void print() const 
    {
        for (const auto& pair : adjacencyList) 
        {
            std::cout << pair.first << " -> ";
            for (const auto& neighbor : pair.second) 
            {
                std::cout << neighbor << " ";
            }
            std::cout << std::endl;
        }
    }

    void breadthFirstSearch(const T& startVertex) const 
    {
        std::unordered_map<T, bool> visited;
        std::queue<T> queue;

        visited[startVertex] = true;
        queue.push(startVertex);

        while (!queue.empty()) 
        {
            T current = queue.front();
            queue.pop();
            std::cout << current << " ";

            for (const auto& neighbor : adjacencyList.at(current)) 
            {
                if (!visited[neighbor]) 
                {
                    visited[neighbor] = true;
                    queue.push(neighbor);
                }
            }
        }
        std::cout << std::endl;
    }

    void depthFirstSearch(const T& startVertex) const 
    {
        std::unordered_map<T, bool> visited;
        depthFirstSearchHelper(startVertex, visited);
        std::cout << std::endl;
    }

private:
    std::unordered_map<T, std::list<T>> adjacencyList;

    void depthFirstSearchHelper(const T& vertex, std::unordered_map<T, bool>& visited) const 
    {
        visited[vertex] = true;
        std::cout << vertex << " ";

        for (const auto& neighbor : adjacencyList.at(vertex)) 
        {
            if (!visited[neighbor]) 
            {
                depthFirstSearchHelper(neighbor, visited);
            }
        }
    }
};

#include <iostream>
#include "DoublyLinkedList.h"
#include "LinkedList.h"
#include "Queue.h"
#include "Stack.h"
#include "BinarySearchTree.h"
#include "HashTable.h"
#include "Graph.h"
#include "Heap.h"

int main()
{
    // LINKED LIST -----------------------------------------------------------------------
    std::cout << "LINKED LIST ----------------------------------------------------------------------\n";
    LinkedList<int> MyInts{10};

    MyInts.append(20);
    MyInts.insert(2, 10);
    MyInts.print();
    MyInts.set(0, 100);
    MyInts.print();
    MyInts.reverse();
    MyInts.print();
    std::cout << "LINKED LIST ----------------------------------------------------------------------\n";

    /*
    Linked List:
    - A linear collection of nodes where each node points to the next node.
    - Efficient for insertion/deletion at the beginning or middle of the list.
    - Does not require a contiguous memory block.
    - Big-O Complexities:
        - Access: O(n)
        - Search: O(n)
        - Insertion: O(1) (at head), O(n) (at tail or specific position)
        - Deletion: O(1) (at head), O(n) (at tail or specific position)
    */

    // DOUBLY LINKED LIST -----------------------------------------------------------------------
    std::cout << "DOUBLY LINKED LIST ----------------------------------------------------------------\n";
    DoublyLinkedList<int> MyInts2{10};

    MyInts2.append(20);
    MyInts2.insert(2, 10);
    MyInts2.print();
    MyInts2.set(0, 100);
    MyInts2.print();
    MyInts2.reverse();
    MyInts2.print();
    std::cout << "DOUBLY LINKED LIST -----------------------------------------------------------------\n";

    /*
    Doubly Linked List:
    - Similar to a linked list, but each node contains two pointers: one to the next node and one to the previous node.
    - Allows for traversal in both directions.
    - Efficient for insertion/deletion at both ends of the list.
    - Big-O Complexities:
        - Access: O(n)
        - Search: O(n)
        - Insertion: O(1) (at head/tail), O(n) (at specific position)
        - Deletion: O(1) (at head/tail), O(n) (at specific position)
    */

    // STACK -----------------------------------------------------------------------
    std::cout << "STACK ------------------------------------------------------------------------------\n";
    Stack<int> stack;
    
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.print(); // Output: 30 20 10
    std::cout << "Top element is: " << stack.peek() << std::endl; // Output: 30
    
    stack.pop();
    stack.print(); // Output: 20 10
    std::cout << "Stack size is: " << stack.size() << std::endl; // Output: 2
    std::cout << "STACK ------------------------------------------------------------------------------\n";

    /*
    Stack:
    - A LIFO (Last In, First Out) data structure where elements are added and removed from the top.
    - Used in situations like recursion, parsing, and backtracking algorithms.
    - Big-O Complexities:
        - Access: O(n)
        - Search: O(n)
        - Insertion: O(1)
        - Deletion: O(1)
    */

    // QUEUE  -----------------------------------------------------------------------
    std::cout << "QUEUE ------------------------------------------------------------------------------\n";
    Queue<int> queue;
    
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.print(); // Output: 10 20 30
    std::cout << "Front element is: " << queue.front() << std::endl; // Output: 10
    
    queue.dequeue();
    queue.print(); // Output: 20 30
    std::cout << "Queue size is: " << queue.size() << std::endl; // Output: 2
    std::cout << "QUEUE ------------------------------------------------------------------------------\n";

    /*
    Queue:
    - A FIFO (First In, First Out) data structure where elements are added at the back and removed from the front.
    - Used in scenarios like task scheduling, managing requests, and breadth-first search.
    - Big-O Complexities:
        - Access: O(n)
        - Search: O(n)
        - Insertion: O(1)
        - Deletion: O(1)
    */

    // BINARY SEARCH TREE -----------------------------------------------------------------------
    std::cout << "BINARY SEARCH TREE -----------------------------------------------------------------\n";
    BinarySearchTree<int> bst;
    
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    bst.printInOrder(); // Output: 20 30 40 50 60 70 80

    std::cout << "Is 40 in the tree? " << (bst.find(40) ? "Yes" : "No") << std::endl; // Output: Yes
    std::cout << "Is 25 in the tree? " << (bst.find(25) ? "Yes" : "No") << std::endl; // Output: No

    bst.remove(50);
    bst.printInOrder(); // Output: 20 30 40 60 70 80

    std::cout << "Tree size is: " << bst.size() << std::endl; // Output: 6
    std::cout << "BINARY SEARCH TREE -----------------------------------------------------------------\n";

    /*
    Binary Search Tree (BST):
    - A tree data structure where each node has at most two children, and the left child is less than the parent, while the right child is greater.
    - Efficient for dynamic sorted data and lookup operations.
    - Big-O Complexities:
        - Access: O(log n) (average), O(n) (worst case)
        - Search: O(log n) (average), O(n) (worst case)
        - Insertion: O(log n) (average), O(n) (worst case)
        - Deletion: O(log n) (average), O(n) (worst case)
    */

    // HASH TABLE -----------------------------------------------------------------------
    std::cout << "HASH TABLE -----------------------------------------------------------------------\n";
    HashTable<std::string, int> hashTable;

    hashTable.insert("apple", 1);
    hashTable.insert("banana", 2);
    hashTable.insert("cherry", 3);

    hashTable.print();

    int value;
    if (hashTable.find("banana", value)) 
    {
        std::cout << "Found banana: " << value << std::endl; // Output: Found banana: 2
    }

    hashTable.remove("banana");
    hashTable.print(); // Banana should no longer be in the table

    std::cout << "Is hash table empty? " << (hashTable.isEmpty() ? "Yes" : "No") << std::endl; // Output: No
    std::cout << "HASH TABLE -----------------------------------------------------------------------\n";

    /*
    Hash Table:
    - A data structure that stores key-value pairs and uses a hash function to compute the index of the key.
    - Provides fast access, insertion, and deletion.
    - Big-O Complexities:
        - Access: O(1) (average), O(n) (worst case)
        - Search: O(1) (average), O(n) (worst case)
        - Insertion: O(1) (average), O(n) (worst case)
        - Deletion: O(1) (average), O(n) (worst case)
    */

    // GRAPH -----------------------------------------------------------------------
    std::cout << "GRAPH -----------------------------------------------------------------------------\n";
    Graph<int> graph;

    graph.addVertex(0);
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addVertex(3);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);

    graph.print();

    std::cout << "BFS starting from vertex 0: ";
    graph.breadthFirstSearch(0); // Output: 0 1 2 3

    std::cout << "DFS starting from vertex 0: ";
    graph.depthFirstSearch(0); // Output: 0 1 2 3
    std::cout << "GRAPH -----------------------------------------------------------------------------\n";

    /*
    Graph:
    - A collection of vertices (nodes) connected by edges.
    - Can be directed or undirected, and can represent various structures like networks, social connections, etc.
    - Big-O Complexities:
        - Access: O(1)
        - Search: O(V + E) (for BFS/DFS where V is vertices and E is edges)
        - Insertion: O(1) (for vertices), O(1) (for edges)
        - Deletion: O(V + E) (if removing a vertex and associated edges)
    */

    // HEAP -----------------------------------------------------------------------
    std::cout << "HEAP -----------------------------------------------------------------------------\n";
    Heap<int> heap;

    heap.insert(10);
    heap.insert(20);
    heap.insert(5);
    heap.insert(30);

    heap.print(); // Output: 30 20 5 10 (depends on heap structure)

    std::cout << "Max element is: " << heap.peekMax() << std::endl; // Output: 30

    heap.extractMax();
    heap.print(); // Output: 20 10 5

    std::cout << "Heap size is: " << heap.size() << std::endl; // Output: 3

    /*
    Heap:
    - A complete binary tree where each node is either greater than or equal to (max heap) or less than or equal to (min heap) its children.
    - Commonly used for priority queues and efficient sorting algorithms like heapsort.
    - Big-O Complexities:
        - Access: O(1)
        - Search: O(n)
        - Insertion: O(log n)
        - Deletion: O(log n)
    */
}

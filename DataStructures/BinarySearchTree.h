#pragma once
#include <iostream>
#include <stdexcept>

template<typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(T value) : data(value), left(nullptr), right(nullptr) {}
};

template<typename T>
class BinarySearchTree
{
public:
    BinarySearchTree() : m_root(nullptr), m_size(0) {}

    ~BinarySearchTree() 
    {
        clear(m_root);
    }

    BinarySearchTree(const BinarySearchTree&) = delete; // Prevent copying
    BinarySearchTree& operator=(const BinarySearchTree&) = delete; // Prevent assignment

    BinarySearchTree(BinarySearchTree&& other) noexcept 
        : m_root(other.m_root), m_size(other.m_size) 
    {
        other.m_root = nullptr;
        other.m_size = 0;
    }

    BinarySearchTree& operator=(BinarySearchTree&& other) noexcept 
    {
        if (this != &other) 
        {
            clear(m_root);
            
            // Transfer ownership
            m_root = other.m_root;
            m_size = other.m_size;

            other.m_root = nullptr;
            other.m_size = 0;
        }
        return *this;
    }

    void insert(T value) 
    {
        m_root = insert(m_root, value);
        ++m_size;
    }

    bool find(T value) const 
    {
        return find(m_root, value) != nullptr;
    }

    void remove(T value) 
    {
        m_root = remove(m_root, value);
    }

    bool isEmpty() const 
    {
        return m_size == 0;
    }

    size_t size() const 
    {
        return m_size;
    }

    void printInOrder() const 
    {
        printInOrder(m_root);
        std::cout << std::endl;
    }

private:
    TreeNode<T>* m_root;
    size_t m_size;

    TreeNode<T>* insert(TreeNode<T>* node, T value) 
    {
        if (!node) 
        {
            return new TreeNode<T>(value);
        }
        if (value < node->data) 
        {
            node->left = insert(node->left, value);
        } 
        else if (value > node->data) 
        {
            node->right = insert(node->right, value);
        }
        return node;
    }

    TreeNode<T>* find(TreeNode<T>* node, T value) const 
    {
        if (!node || node->data == value) 
        {
            return node;
        }
        if (value < node->data) 
        {
            return find(node->left, value);
        }
        return find(node->right, value);
    }

    TreeNode<T>* remove(TreeNode<T>* node, T value) 
    {
        if (!node) 
        {
            return node;
        }

        if (value < node->data) 
        {
            node->left = remove(node->left, value);
        } 
        else if (value > node->data) 
        {
            node->right = remove(node->right, value);
        } 
        else 
        {
            // Node with only one child or no child
            if (!node->left) 
            {
                TreeNode<T>* temp = node->right;
                delete node;
                --m_size;
                return temp;
            } 
            else if (!node->right) 
            {
                TreeNode<T>* temp = node->left;
                delete node;
                --m_size;
                return temp;
            }

            // Node with two children: Get the inorder successor (smallest in the right subtree)
            TreeNode<T>* temp = minValueNode(node->right);

            // Copy the inorder successor's content to this node
            node->data = temp->data;

            // Delete the inorder successor
            node->right = remove(node->right, temp->data);
        }
        return node;
    }

    TreeNode<T>* minValueNode(TreeNode<T>* node) const 
    {
        TreeNode<T>* current = node;
        while (current && current->left) 
        {
            current = current->left;
        }
        return current;
    }

    void printInOrder(TreeNode<T>* node) const 
    {
        if (node) 
        {
            printInOrder(node->left);
            std::cout << node->data << " ";
            printInOrder(node->right);
        }
    }

    void clear(TreeNode<T>* node) 
    {
        if (node) 
        {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }
};

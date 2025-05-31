
#ifndef NODE_HPP
#define NODE_HPP

#include "BST.hpp"

class Node {
public:
    BST bst;  
    int deger;
    Node* next;  
    Node* prev;  

    Node(); 
};

#endif

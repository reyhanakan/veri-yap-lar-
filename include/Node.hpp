/**
* @file Node.hpp
* @description düğüm tanımı
* @course 1. Öğretim B grubu
* @assignment 2. Ödev
* @date 16.12.24
* @author Didem Reyhan AKAN b231210002@sakarya.edu.tr
*/
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

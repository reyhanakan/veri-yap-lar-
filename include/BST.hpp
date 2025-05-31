/**
* @file BST.hpp
* @description ağaç tanımı
* @course 1. Öğretim B grubu
* @assignment 2. Ödev
* @date 16.12.24
* @author Didem Reyhan AKAN b231210002@sakarya.edu.tr
*/
#ifndef BST_HPP
#define BST_HPP
#include <iostream>
#include <string>
class NodeBST {
public:
    char harf; 
    NodeBST* left;
    NodeBST* right;
    NodeBST* parent; 

    NodeBST();  
    NodeBST(char deger);  
};

class BST {
public:
    NodeBST* root;
     int treeHeight;
    int width;
    int height(NodeBST* root);  
    void insert(char deger);  
    void printInOrder(NodeBST* node);  
    void printTree();  
    void printLevel(NodeBST* root, int level, int spacing);
    void printCanvas();
    void drawTree(NodeBST* root, int level, int pos, char** canvas, int spacing, int maxLevel);
    NodeBST* getRoot(); 
    int hesaplaToplamDeger(NodeBST* node, bool isLeft);
    BST();  
    void aynalama(NodeBST* node);
    void freeCanvas(char** canvas, int rows);
    void silAltAgac(NodeBST* node);
};

#endif

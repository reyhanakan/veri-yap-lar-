
#include "BST.hpp"
#include <cmath>
#include <cstring>  
#include <string>
using namespace std;

NodeBST::NodeBST() {
    left = nullptr;
    right = nullptr;
}

NodeBST::NodeBST(char deger) {
    harf = deger;
    left = nullptr;
    right = nullptr;
}

NodeBST* BST::getRoot() {
    return root;  
}

BST::BST() {
    root = nullptr;
}

void BST::insert(char deger) {
    if (root == nullptr) {
        root = new NodeBST(deger);
    } else {
        NodeBST* current = root;
        NodeBST* parent = nullptr;

        while (current != nullptr) {
            parent = current;
            if (deger < current->harf) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        if (deger < parent->harf) {
            parent->left = new NodeBST(deger);  
        } else {
            parent->right = new NodeBST(deger); 
        }
    }
}


void BST::silAltAgac(NodeBST* node) {
    if (node == nullptr) {
        return;
    }

    silAltAgac(node->left);
    silAltAgac(node->right);

    delete node;
}

void BST::printInOrder(NodeBST* node) {
    if (node != nullptr) {
        printInOrder(node->left);
        cout << node->harf << " ";  
        printInOrder(node->right);
    }
}

int BST::height(NodeBST* root) {
    if (!root) return 0;
        return std::max(height(root->left), height(root->right)) + 1;
}

void BST::printLevel(NodeBST* root, int level, int spacing) {
    if (root == nullptr) {
        for (int i = 0; i < spacing; i++) 
            std::cout << " ";
        return;
    }

    if (level == 1) {
        for (int i = 0; i < spacing; i++) 
            std::cout << " ";
        std::cout << root->harf;
    } else if (level > 1) {
        printLevel(root->left, level - 1, spacing / 2);
        printLevel(root->right, level - 1, spacing / 2);
    }
}

void BST::printCanvas() {
  
    int treeHeight = height(root);  
    int height = treeHeight * 2;    
    int width = (1 << (treeHeight + 1));  

    char** canvas = new(std::nothrow) char*[height];
    if (!canvas) {
        std::cerr << "Bellek tahsisi başarısız!" << std::endl;
        return;
    }

    for (int i = 0; i < height; ++i) {
        canvas[i] = new(std::nothrow) char[width];
        if (!canvas[i]) {
            std::cerr << "Bellek tahsisi başarısız!" << std::endl;
            return;
        }
    }

 
    for (int i = 0; i < height; ++i) {
        delete[] canvas[i];
    }
    delete[] canvas;
}

void BST::freeCanvas(char** canvas, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] canvas[i];
    }
    delete[] canvas;
}


void BST::drawTree(NodeBST* root, int level, int pos, char** canvas, int spacing, int maxLevel) {
    if (!root || level >= maxLevel) {
        return;  
    }

    canvas[level][pos] = root->harf;

    int leftCol = -1;
    int rightCol = -1;

    if (root->left) {
        leftCol = pos - spacing;  

        for (int i = leftCol + 1; i < pos; ++i) {
            canvas[level + 1][i] = '.';
        }

        for (int i = level + 1; i < maxLevel && canvas[i][pos - 1] == ' '; ++i) {
            canvas[i][pos - 1] = '.';  
        }

        drawTree(root->left, level + 2, leftCol, canvas, std::max(spacing / 2, 4), maxLevel);  
    }


    if (root->right) {
        rightCol = pos + spacing;  
        for (int i = pos + 1; i < rightCol; ++i) {
            canvas[level + 1][i] = '.';
        }
        for (int i = level + 1; i < maxLevel && canvas[i][pos + 1] == ' '; ++i) {
            canvas[i][pos + 1] = '.'; 
        }

        drawTree(root->right, level + 2, rightCol, canvas, std::max(spacing / 2, 4), maxLevel);  
    }

if (root->left && root->right) {
    int leftCol = pos - spacing / 2;
    int rightCol = pos + spacing / 2;
 
    canvas[level + 1][leftCol] = '.';  
    canvas[level + 1][rightCol] = '.'; 

    for (int i = leftCol + 1; i < rightCol; ++i) {
        canvas[level + 1][i] = '.'; 
    }
}


}



void BST::printTree() {
    if (root == nullptr) {
        cout << "Ağaç boş!" << endl;
        return;
    }

    int treeHeight = height(root);  
    int width = (1 << (treeHeight + 1)); 
    int maxLevel = treeHeight*2;  
    int spacing = 3*(treeHeight - 1);


    char** canvas = new(std::nothrow) char*[maxLevel + 2];  
    if (!canvas) {
        cerr << "Canvas için bellek tahsisi başarısız!" << endl;
        return;
    }

    for (int i = 0; i < maxLevel + 2; ++i) {  
        canvas[i] = new(std::nothrow) char[width + 2];  
        if (!canvas[i]) {
            cerr << "Satır için bellek tahsisi başarısız!" << endl;
            freeCanvas(canvas, i);
            return;
        }
        fill(canvas[i], canvas[i] + width + 2, ' '); 
    }

    drawTree(root, 0, width / 2, canvas, spacing, maxLevel);

    for (int i = 0; i < maxLevel + 2; ++i) {  
        for (int j = 0; j < width + 2; ++j) {  
            cout << canvas[i][j];
        }
        cout << endl;
    }

    freeCanvas(canvas, maxLevel + 2);
}


int BST::hesaplaToplamDeger(NodeBST* node, bool isLeft = false) {
    if (node == nullptr) {
        return 0;
    }

    int currentDeger = isLeft ? static_cast<int>(node->harf) * 2 : static_cast<int>(node->harf);

    int leftDeger = hesaplaToplamDeger(node->left, true);
    int rightDeger = hesaplaToplamDeger(node->right, false);

    return currentDeger + leftDeger + rightDeger;
}




void BST::aynalama(NodeBST* node) {
    if (node == nullptr) {
        return;  
    }

    NodeBST* temp = node->left;
    node->left = node->right;
    node->right = temp;

    aynalama(node->left);
    aynalama(node->right);
}

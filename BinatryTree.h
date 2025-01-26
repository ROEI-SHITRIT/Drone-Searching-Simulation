#ifndef WH03C_BINATRYTREE_H
#define WH03C_BINATRYTREE_H
#include "Node.h"
#include <iostream>

class BinatryTree {
private:
    //filed
    Node* root;
    int treeSize;
public:
    //builders
    BinatryTree();
    BinatryTree(BinatryTree &binatryTree);
    ~BinatryTree();
    //getters
    Node* getRoot()const;
    //operators
    BinatryTree& operator =(const BinatryTree &binatryTree);
    //methods
    void insert(Drone* value);
    Drone* search(Drone* value)const;
    Drone* min()const;
    Drone* max()const;
    void remove(Drone* value);
    void clear();
    void print()const;
    int  size()const;
private:
    //helping methods
    Node* insert(Drone* value,Node* root);
    Node* search(Drone* value,Node* root)const;
    Node* min(Node* root)const;
    Node* max(Node* root)const;
    Node* remove(Drone* value,Node* root);
    Node* successor(Node* root)const;
    void clear(Node* root);
    void print(Node* root)const;

};


#endif //WH03C_BINATRYTREE_H

#include "BinatryTree.h"

BinatryTree::BinatryTree():root(nullptr),treeSize(0) {
}

BinatryTree::BinatryTree(BinatryTree &binatryTree):root(binatryTree.root),treeSize(binatryTree.treeSize){
}
BinatryTree::~BinatryTree() {
    clear();
    delete this->root;
}

Node* BinatryTree::getRoot() const {
    return this->root;
}

BinatryTree &BinatryTree::operator=(const BinatryTree &binatryTree) {
    this->root=binatryTree.root;
    this->treeSize=binatryTree.treeSize;
    return *this;
}

void BinatryTree::insert(Drone *value) {
    if(value== nullptr){
        return;
    }
    this->root= insert(value, this->root);
}

Node *BinatryTree::insert(Drone *value, Node* root) {
    if(root== nullptr){
        this->treeSize++;
        return new Node(value);
    }
    if(value>root->getValue()){
        root->setRight(insert(value,root->getRight()));
    }
    if(value<root->getValue()){
        root->setLeft(insert(value,root->getLeft()));
    }
    return root;
}

Drone *BinatryTree::search(Drone *value) const {
    Node* tmp = search(value, this->root);
    if(tmp!= nullptr){
        return tmp->getValue();
    }
    return nullptr;
}

Node *BinatryTree::search(Drone *value, Node *root) const {
    if(root== nullptr){
        return nullptr;
    }
    if(value<root->getValue()){
        return search(value,root->getLeft());
    }
    if(value>root->getValue()){
        return search(value,root->getRight());
    }
    return root;
}

Drone *BinatryTree::min() const {
    Node* tmp = min(this->root);
    return tmp->getValue();
}

Node *BinatryTree::min(Node* root)const {
    if(root->getLeft()== nullptr){
        return root;
    }
    return min(root->getLeft());

}

int BinatryTree::size() const {
    return treeSize;
}

Drone *BinatryTree::max() const {
    Node* tmp = max(this->root);
    return tmp->getValue();
}

Node *BinatryTree::max(Node *root) const {
    if(root->getRight()== nullptr){
        return root;
    }
    return max(root->getRight());
}

void BinatryTree::remove(Drone *value){
    if(value== nullptr){
        return;
    }
    this->root= remove(value, this->root->getRight());
}

Node *BinatryTree::remove(Drone* value, Node *root) {
    if(root== nullptr){
        return nullptr;
    }
    else if(value>root->getValue()){
        return remove(value,root->getRight());
    }
    else if(value<root->getValue()){
        return remove(value,root->getLeft());
    }
    else{
        if(root->getLeft()== nullptr){
            Node* tmp = root->getRight();
            this->treeSize--;
            delete root;
            return tmp;
        }
        if(root->getRight()== nullptr){
            this->treeSize--;
            Node* tmp = root->getLeft();
            delete root;
            return tmp;
        }
        else{
            Node* newroot = successor(root);
            root->setDrone(newroot->getValue());
            root->setRight(remove(root->getValue(),root->getRight()));
        }
    }
    return root;
}

Node *BinatryTree::successor(Node *root) const {
    if(root->getLeft()== nullptr){
        return root;
    }
    return successor(root->getLeft());
}


void BinatryTree::clear() {
    clear(this->root);
    this->root= nullptr;
    this->treeSize=0;
}

void BinatryTree::clear(Node *root) {
    if(root!= nullptr){
        clear(root->getLeft());
        clear(root->getRight());
        delete root;
    }

}

void BinatryTree::print() const {
    print(this->root);
}

void BinatryTree::print(Node *root) const {
    if(root!= nullptr){
        print(root->getLeft());
        std::cout<<*root->getValue();
        print(root->getRight());

    }

}









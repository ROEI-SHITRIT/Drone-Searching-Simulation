//
// Created by ORLY on 29/06/2024.
//

#include "Node.h"

Node::Node():right(nullptr),left(nullptr),value(nullptr) {

}
Node::Node(Drone *value):right(nullptr),left(nullptr),value(value){

}

Node::Node(Node &node):right(node.left),left(node.right),value(node.value) {

}

Node::Node(Node* right, Node *left, Drone *drone):right(right),left(left),value(drone) {

}

Node *Node::getRight() const {
    return this->right;
}

Node *Node::getLeft() const {
    return this->left;
}

Drone *Node::getValue()const{
    return this->value;
}

void Node::setRight( Node* tree) {
    this->right=tree;
}

void Node::setLeft(Node *tree) {
    this->left=tree;
}

void Node::setDrone(Drone *drone) {
    this->value=drone;
}

Node &Node::operator=(const Node &node) {
    if(this == &node){
        return *this;
    }
    this->right=node.right;
    this->left=node.left;
    this->value=node.value;
    return *this;
}

Node::~Node() {
    delete this->value;

}



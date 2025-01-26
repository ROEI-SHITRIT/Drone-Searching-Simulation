
#ifndef WH03C_NODE_H
#define WH03C_NODE_H
#include "Drone.h"

class Node {
private:
    //fields
    Node* right;
    Node* left;
    Drone* value;
public:
    //builders
    Node();
    Node(Node &node);
    Node(Node* right,Node* left,Drone* drone);
    explicit Node(Drone* value);
    ~Node();
    //getters+setters
    Node* getRight()const;
    Node* getLeft()const;
    Drone* getValue()const;
    void setRight(Node* right);
    void setLeft( Node* left);
    void setDrone( Drone* drone);
    //operators
    Node& operator = (const Node &node);




};


#endif //WH03C_NODE_H

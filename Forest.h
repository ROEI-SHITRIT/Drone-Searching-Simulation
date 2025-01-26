#ifndef HW02CPP_FOREST_H
#define HW02CPP_FOREST_H
#include "Cell.h"
#include "Drone.h"
#include "BinatryTree.h"
class Forest {
private:
    //fields
    Cell** cells;
    BinatryTree* droneTree;
    int sizeOfDrones;
    Vector2f target;


public:
    //builders
    Forest();
    Forest(const Forest &forest);
    ~Forest();
    //get+set
    Cell** getCells()const;
    BinatryTree* getDroneTree()const;
    int getSizeOfDrones()const;
    Vector2f getTarget()const;
    void setTarget(const Vector2f &vector);
    void setSizeOfDrone(int num);
    void setLimits(int minx,int miny,int maxx,int maxy);
    void setcells();
    //operator
    Forest& operator =(const Forest &forest);
    int operator()(int x,int y);
public:
    //limits points the forest built on
    int minX,minY,maxX,maxY;

};


#endif //HW02CPP_FOREST_H

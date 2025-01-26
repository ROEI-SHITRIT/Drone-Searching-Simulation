#include "Forest.h"

Forest::Forest():cells(nullptr),droneTree(new BinatryTree()),sizeOfDrones(0),target(),minX(0),minY(0),maxX(0),maxY(0) {

}



Forest::Forest(const Forest &forest):cells(nullptr),droneTree(forest.droneTree),sizeOfDrones(forest.getSizeOfDrones()),target(forest.getTarget()) {
    this->cells=new Cell*[this->maxX];
    for(int i= this->minX;i<= this->maxX;i++){
        this->cells[i]= new Cell[this->maxY];
        for(int j = this->minY;j<= this->maxY;j++){
            Vector2f vector(i,j);
            this->cells[i][j].setCell(vector);
        }
    }

}
Forest::~Forest() {
    delete droneTree;
    for(int i= this->minX;i<= this->maxX;i++){
        delete[] this->cells[i];
    }
    delete[] this->cells;
}

Cell **Forest::getCells() const {
    return this->cells;
}


int Forest::getSizeOfDrones() const {
    return this->droneTree->size();
}

Vector2f Forest::getTarget() const {
    return this->target;
}

void Forest::setTarget(const Vector2f &vector) {
    this->target.setX(vector.getX());
    this->target.setY(vector.getY());
}

Forest &Forest::operator=(const Forest &forest) {
    if(this == &forest){
        return *this;
    }
    this->droneTree=forest.droneTree;
    delete[] this->cells;
    this->cells =new Cell*[this->maxX];
    for(int i= this->minX;i<= this->maxX;i++){
        this->cells[i]= new Cell[this->maxY];
        for(int j = this->minY;j<= this->maxY;j++){
            this->cells[i][j]=forest.getCells()[i][j];
        }
    }
    this->sizeOfDrones=forest.sizeOfDrones;
    this->target=forest.target;
    return *this;
}

int Forest::operator()(int x, int y) {
    return this->cells[x][y].getNumOfDrones();
}

void Forest::setSizeOfDrone(int num) {
    this->sizeOfDrones=num;
}


void Forest::setLimits(int minx, int miny, int maxx, int maxy) {
    this->minX=minx;
    this->minY=miny;
    this->maxX=maxx;
    this->maxY=maxy;
    setcells();
}

BinatryTree* Forest::getDroneTree()const {
    return this->droneTree;
}

void Forest::setcells() {
    delete[] this->cells;
    this->cells =new Cell*[this->maxX+1];
    for(int i= this->minX;i<= this->maxX;i++){
        this->cells[i]= new Cell[this->maxY+1];
        for(int j = this->minY;j<= this->maxY;j++){
            Vector2f vector(i,j);
            this->cells[i][j].setCell(vector);
        }
    }
}

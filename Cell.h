#ifndef HW02CPP_CELL_H
#define HW02CPP_CELL_H
#include "Vector2f.h"

class Cell {
private:
    //fields
    Vector2f cell;
    int numOfDrone;
    bool target;

public:
    //builders
    Cell();
     Cell(Cell &cell1);
    ~Cell()=default;
    //get+set
    Vector2f getcell()const;
    int getNumOfDrones()const;
    void setNumOfDrones(int num);
    void setCell(Vector2f &vector);
    //operators
   Cell& operator++();
   const Cell  operator++( int num);
    Cell& operator--();
    const Cell operator--(int num);
    Cell& operator=(const Cell &cell);

};


#endif //HW02CPP_CELL_H

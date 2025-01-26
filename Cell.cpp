
#include "Cell.h"

Cell::Cell():cell(),numOfDrone(0),target(false) {
}


Cell::Cell(Cell &cell1):cell(cell1.cell),numOfDrone(cell1.numOfDrone),target(cell1.target) {

}


Vector2f Cell::getcell() const {
    return this->cell;
}

int Cell::getNumOfDrones() const {
    return this->numOfDrone;
}


void Cell::setNumOfDrones(int num) {
    this->numOfDrone=num;
}

Cell &Cell::operator++() {
    this->numOfDrone++;
    return *this;
}

const Cell Cell::operator++( int num) {
    Cell tmp=*this;
    this->numOfDrone++;
    return tmp;
}

Cell &Cell::operator--() {
    this->numOfDrone--;
    return *this;
}

const Cell Cell::operator--(int num) {
    Cell tmp = *this;
    this->numOfDrone--;
    return tmp;
}

Cell &Cell::operator=(const Cell &cell) {
    this->cell=cell.getcell();
    setNumOfDrones(cell.getNumOfDrones());
    return *this;
}

void Cell::setCell(Vector2f &vector) {
    this->cell.setX(vector.getX());
    this->cell.setY(vector.getY());
}




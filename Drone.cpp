
#include "Drone.h"
    unsigned int Drone::ID=1;

    Vector2f Drone::GlobalBest;


Drone::Drone(): id(Drone::ID++),position(Vector2f()),vel(Vector2f()),personalBest(Vector2f()),type(' '),MINX(0),MINY(0),MAXX(0),MAXY(0){
}

Drone::Drone(double x, double y, double velx, double vely,Vector2f vector,char t):id(Drone::ID++),position(x,y),vel(velx,vely),personalBest(vector),type(t),MINX(0),MINY(0),MAXX(0),MAXY(0) {

}

Drone::Drone(Drone &drone):id(drone.getid()),position(drone.getPosition().getX(),drone.getPosition().getY()),vel(drone.getVelositi().getX(),drone.getVelositi().getY()),personalBest(drone.getPersonalBest()),type(drone.type),MINX(0),MINY(0),MAXX(0),MAXY(0) {

}


unsigned int Drone::getid()const {
    return this->id;
}

Vector2f Drone::getPosition() const {
    return this->position;
}

Vector2f Drone::getVelositi() const {
    return this->vel;
}

Vector2f Drone::getPersonalBest() const {
    return this->personalBest;
}

Vector2f Drone::getGlobalbest() {
    return Drone::GlobalBest;
}

void Drone::setPosition(const Vector2f &vector) {
    this->position.setX(vector.getX());
    this->position.setY(vector.getY());
}

void Drone::setVel(const Vector2f &vector) {
    this->vel.setX(vector.getX());
    this->vel.setY(vector.getY());
}

void Drone::setPersonalBest(const Vector2f &vector) {
    this->personalBest.setX(vector.getX());
    this->personalBest.setY(vector.getY());
}

void Drone::setGlobalBest(const Vector2f &vector) {
    Drone::GlobalBest.setX(vector.getX());
    Drone::GlobalBest.setY(vector.getY());
}

Drone& Drone::operator=(const Drone &drone) {
    if(&drone== this){
        return *this;
    }
    this->setPosition(drone.getPosition());
    this->setVel(drone.getVelositi());
    this->setPersonalBest(drone.getPersonalBest());
    return *this;
}


//keeps drone in limits when needed.
void Drone::limits(Vector2f &vector) {
    if(vector.getX()>MAXX){
        vector.setX(MAXX);
    }
    if(vector.getY()>MAXY){
        vector.setY(MAXY);
    }
    if (vector.getX()<MINX){
        vector.setX(MINX);
    }
    if(vector.getY()<MINY){
        vector.setY(MINY);
    }
}

bool Drone::operator<(const Drone &drone) const {
    if(this->id<drone.id){
        return true;
    }
    return false;
}

bool Drone::operator>(const Drone &drone) const {
    return !(*this<drone);
}

char Drone::getType() const {
    return type;
}

std::ostream &operator<<(std::ostream &out,const Drone &drone) {
    return drone.print(out);
}

void Drone::setlimits(int minx, int miny, int maxx, int maxy) {
    this->MINX=minx;
    this->MINY=miny;
    this->MAXX=maxx;
    this->MAXY=maxy;
}





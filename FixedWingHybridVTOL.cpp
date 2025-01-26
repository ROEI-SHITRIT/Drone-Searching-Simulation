#include <iomanip>
#include "FixedWingHybridVTOL.h"

FixedWingHybridVTOL::FixedWingHybridVTOL():Drone(),random(0) {

}

FixedWingHybridVTOL::FixedWingHybridVTOL(FixedWingHybridVTOL &drone):Drone(drone),random(drone.random) {

}

FixedWingHybridVTOL::FixedWingHybridVTOL(double x, double y, double velx, double vely, Vector2f vector, char t,int rand) : Drone(x,y,velx,vely,vector,t),random(rand) {

}

void FixedWingHybridVTOL::update() {
    SingleRotorDrone::update();
}

std::ostream &FixedWingHybridVTOL::print(std::ostream &out) const {
    out<<getType()<<" ";
    if(std::fmod(this->position.getX()*100,100)!=0){
            if(std::fmod(this->position.getX()*100,10)!=0){
                out<<std::fixed<<std::setprecision(2)<<this->position.getX()<<" ";
            }
            else{
                out<<std::fixed<<std::setprecision(1)<<this->position.getX()<<" ";
            }

        }
        else{
        out<<(int)this->position.getX()<<" ";
        }
    if(std::fmod(this->position.getY()*100,100)!=0){
        if(std::fmod(this->position.getY()*100,10)!=0){
            out<<std::fixed<<std::setprecision(2)<<this->position.getY();
        }
        else{
            out<<std::fixed<<std::setprecision(1)<<this->position.getY();
        }

    }
    else{
        out<<(int)this->position.getY();
    }
    out<<std::endl;


    return out;
}

FixedWingHybridVTOL &FixedWingHybridVTOL::operator=(const FixedWingHybridVTOL &drone) {
    if(this==&drone){
        return *this;
    }
    Drone::operator=(drone);
    this->random=drone.random;
    return *this;
}

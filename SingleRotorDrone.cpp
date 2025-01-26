#include <iomanip>
#include "SingleRotorDrone.h"

SingleRotorDrone::SingleRotorDrone():Drone() {

}

SingleRotorDrone::SingleRotorDrone(SingleRotorDrone &drone):Drone(drone.getPosition().getX(),drone.getPosition().getY(),drone.getVelositi().getX(),drone.getVelositi().getY(),drone.getPersonalBest(),drone.getType()),random(0)
 {

}

SingleRotorDrone::SingleRotorDrone(double x, double y, double velx, double vely, Vector2f vector, char t,int rand) : Drone(x, y,velx,vely,vector,t),random(rand){

}

void SingleRotorDrone::update() {
    if(random==0){
        std::srand(time(nullptr));
    }
    else{
        std::srand(random);
    }
    double rand1=((double)rand()/((double)RAND_MAX));
    double rand2=((double)rand()/((double)RAND_MAX));
    this->setPosition(this->getPosition()+ this->getVelositi());
    limits(this->position);
    setVel(((getVelositi()*a)+((getPersonalBest()-getPosition())*(rand1*b))+((getGlobalbest()-getPosition())*(y*rand2))));
}

std::ostream& SingleRotorDrone::print(std::ostream &out) const {
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

SingleRotorDrone &SingleRotorDrone::operator=(const SingleRotorDrone &drone) {
    if(this == &drone){
        return *this;
    }
    Drone::operator=(drone);
    this->random=drone.random;
    return *this;
}



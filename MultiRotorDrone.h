#ifndef WH03C___MULTIROTORDRONE_H
#define WH03C___MULTIROTORDRONE_H
#include "Drone.h"
//extend Drone
class MultiRotorDrone: public Drone {
private:
    //parameters
    const double a=0.05;
    const double b=0.1;
    const double y=0;
    //fields
    int random;

public:
    //builders
    MultiRotorDrone();
    MultiRotorDrone(MultiRotorDrone &drone);
    MultiRotorDrone(double x, double y, double velx, double vely, Vector2f vector, char t,int rand);
   ~MultiRotorDrone() override =default;
    //methods
    void  update()override;
    std::ostream& print(std::ostream &out)const override;
    //operator
    MultiRotorDrone& operator=(const MultiRotorDrone &drone);


};


#endif //WH03C___MULTIROTORDRONE_H

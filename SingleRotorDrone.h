#ifndef WH03C___SINGLEROTORDRONE_H
#define WH03C___SINGLEROTORDRONE_H
#include "Drone.h"
//extend Drone
class SingleRotorDrone:virtual public Drone {
private:
    //parameters
    const double a =0.01;
    const double b=-0.1;
    const double y=-0.25;
    //fields
    double random;
public:
    //builders
    SingleRotorDrone();
    SingleRotorDrone(SingleRotorDrone &drone);
    SingleRotorDrone(double x,double y,double velx,double vely,Vector2f vector,char t,int rand);
    ~SingleRotorDrone() override =default;
    //methods
    void  update()override;
    std::ostream& print(std::ostream &out)const override;
    //operator
    SingleRotorDrone& operator=(const SingleRotorDrone &drone);
};


#endif //WH03C___SINGLEROTORDRONE_H

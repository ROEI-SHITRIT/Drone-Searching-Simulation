#ifndef WH03C___FIXEDWINGDRONE_H
#define WH03C___FIXEDWINGDRONE_H
#include "Drone.h"
//extends Drone
class FixedWingDrone:virtual public Drone{
private:
    //parameters for velocity
    const double a=0.25;
    const double b=1;
    const double y=1;
    //fields
    int random;
public:
    //builders
    FixedWingDrone();
    FixedWingDrone(FixedWingDrone &drone);
    FixedWingDrone(double x, double y, double velx, double vely, Vector2f vector, char t,int rand);
    ~FixedWingDrone() override =default;
    //methods
    void  update()override;
    std::ostream& print(std::ostream &out)const override;
    //operator
    FixedWingDrone& operator=(const FixedWingDrone &drone);

};


#endif //WH03C___FIXEDWINGDRONE_H

#ifndef WH03C___FIXEDWINGHYBRIDVTOL_H
#define WH03C___FIXEDWINGHYBRIDVTOL_H
#include "SingleRotorDrone.h"
#include "FixedWingDrone.h"

//extends Drone+SingleRotorDrone+FixedWingDrone
class FixedWingHybridVTOL: public SingleRotorDrone ,public FixedWingDrone{
private:
    //parameters
    const double a =0.01;
    const double b=-0.1;
    const double y=-0.25;
    //fields
    double random;
public:
    //builders
    FixedWingHybridVTOL();
    FixedWingHybridVTOL(FixedWingHybridVTOL &drone);
    FixedWingHybridVTOL(double x, double y, double velx, double vely, Vector2f vector, char t,int rand);
   ~FixedWingHybridVTOL() override =default;
    //methods
    void  update()override;
    std::ostream& print(std::ostream &out)const override;
    //operator
    FixedWingHybridVTOL& operator=(const FixedWingHybridVTOL &drone);

};


#endif //WH03C___FIXEDWINGHYBRIDVTOL_H

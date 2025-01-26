#ifndef HW02CPP_DRONE_H
#define HW02CPP_DRONE_H
#include "Vector2f.h"
#include <cstdlib>
class Drone {
private:
    //fields
protected:
    static unsigned int ID;
    unsigned int id;
    Vector2f position;
    Vector2f vel;
    Vector2f personalBest;
    static Vector2f GlobalBest;
    char type;
public:
    //builders
    explicit Drone();
    explicit Drone(double x,double y,double velx,double vely,Vector2f vector,char t);
    Drone(Drone &drone);
    virtual ~Drone()=default;
    //get+set
    unsigned int getid()const;
    Vector2f getPosition()const;
    Vector2f getVelositi()const;
    Vector2f getPersonalBest()const;
    char getType()const;
    static Vector2f getGlobalbest();
    void setPosition(const Vector2f &vector);
    void setVel(const Vector2f &vector);
    void setPersonalBest(const Vector2f &vector);
    static void setGlobalBest(const Vector2f &vector);
    void setlimits(int minx,int miny,int maxx,int maxy);
    //operators
    Drone& operator=(const Drone &drone);
    bool operator <(const Drone &drone)const;
    bool operator >(const Drone &drone)const;
    friend std::ostream& operator<<(std::ostream &out, const Drone &drone);
    //met
    virtual void update()=0;//update every step of drone (position + velocity).
    void limits(Vector2f &vector);//keep in limits by D function.
    virtual std::ostream& print(std::ostream &out)const=0;
    //limits to stay in cells
    int MINX;
    int MINY;
    int MAXX;
    int MAXY;


};


#endif //HW02CPP_DRONE_H

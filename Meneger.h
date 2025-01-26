#ifndef HW02CPP_MENEGER_H
#define HW02CPP_MENEGER_H
#include "Forest.h"
#include "FixedWingHybridVTOL.h"
#include "MultiRotorDrone.h"
/*
 * this class creating the forest that I do simulate on.
 * and running checks on files + inputs in files.
 * get an int rand num to use in srand()
 * starting simulation.
 */
class Meneger {
private:
    /*forest of simulation.
     * iter the number of iteration from the file.
     *
     */
    Forest* forest;
    int iter;
    int rand;

public:
    //defaults builder
    Meneger();
    ~Meneger();
    // read file and creat forest + check file.
    void creatfromFile1(std::string &name);
    void creatfromFile2(std::string &name);
    //checks input
    static int numofspace(std::string &line);
    static bool checkstr(const std::string &str);
    //promotes drones+Checks if the drone has reached the target point
    void nextstep(Node* root);
    void treenextstep(Node* root);
    bool droneisthere()const;
    void cellcurrentstat(Cell &curent,Cell &tobe);
    void setingglobal(const Vector2f &global);
    void creatdrones(char type,Vector2f &pos,Vector2f &vel);
    //manger the simulation
    void start(std::string &name,std::string &name2,std::string &name3,int randnum);
    //writing to the output file
    void printtofile(std::string &name,int iter);
    //print error when needed.
    void printeror();
private:
    //helpers methods
    //check if drone is in the target point
    Node* droneisthere(Node* root,bool &flag)const;
    //print from the tree
    void printvalue(Node* root,std::ofstream &name)const;
};



#endif //HW02CPP_MENEGER_H

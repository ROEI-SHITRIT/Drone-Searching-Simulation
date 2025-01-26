#include <sstream>
#include <fstream>
#include "Meneger.h"


//default builder
Meneger::Meneger():forest(new Forest()),iter(0),rand(0){

}

//checking number of space in every line in the file
int Meneger::numofspace(std::string &line) {
    int counter=0;
    for (char c : line){
        if(c ==' '){
            counter++;
        }
    }
    return counter;
}
//checks every line that contains only numbers+space+ '.' or a minos.
bool Meneger::checkstr(const std::string &str) {
    for(unsigned int i=0;i<str.size()-1;i++){
        if(str[i]==' '){
            if(str[i+1]!='-' && !isdigit(str[i+1])){
                return false;
            }
        }
        if(isdigit(str[i])){
            if(!isdigit(str[i+1]) && str[i+1]!= ' ' && str[i+1]!='.'){
                return false;
            }
        }
        if(str[i]=='-'&& !isdigit(str[i+1])){
            return false;
        }

    }

    return true;
}
// Promotes each drone to the next position and changes a personal best and a global best
//In addition, you send to the function that updates each cell how many drones are in it at the same time.
void Meneger::nextstep(Node* root) {
    Vector2f prevpos=root->getValue()->getPosition();
    root->getValue()->update();
    cellcurrentstat(this->forest->getCells()[(int)floor(prevpos.getX())][(int)floor(prevpos.getY())],this->forest->getCells()[(int)floor(root->getValue()->getPosition().getX())][(int)floor(root->getValue()->getPosition().getY())]);
    if(root->getValue()->getPosition().distance(this->forest->getTarget())<root->getValue()->getPersonalBest().distance(this->forest->getTarget())){
        root->getValue()->setPersonalBest(root->getValue()->getPosition());
    }
    if(root->getValue()->getPosition().distance(this->forest->getTarget())<root->getValue()->getGlobalbest().distance(this->forest->getTarget())){
        setingglobal(root->getValue()->getPosition());
    }
}
void Meneger::treenextstep(Node* root) {
    if(root != nullptr){
        nextstep(root);
        treenextstep(root->getLeft());
        treenextstep(root->getRight());
    }

}
//printing format error.
void Meneger::printeror() {
    std::cerr <<"Error; invalid input"<<std::endl;
}
/*
 * read + check file.
 * getting the target point and iter and update in the fields.
 * converting from str to double before updating.
 */
void Meneger::creatfromFile1(std::string &name) {
    int counter=0,minX,minY,maxX,maxY;
    double num;
    Vector2f tmp;
    std::ifstream file(name);
    if(!file.is_open()){
        printeror();
        exit(-1);
    }
    std::string line;
    while(std::getline(file,line)){
        if(!checkstr(line)){
            printeror();
            exit(-1);
        }
        if(counter==0 && numofspace(line)==3){
            std::stringstream ss(line);
            ss>>minX;
            ss>>minY;
            ss>>maxX;
            ss>>maxY;
            if(minX>maxX||minY>maxY){
                printeror();
                exit(-1);
            }
            this->forest->setLimits(minX,minY,maxX,maxY);
            counter++;
            continue;
        }
        if(counter==1&& numofspace(line)==1){
            std::stringstream ss(line);
            ss>>num;
            tmp.setX(num);
            ss>>num;
            tmp.setY(num);
            this->forest->setTarget(tmp);
            counter++;
            continue;
        }

        if(counter==2&& numofspace(line)==0){
            std::stringstream ss(line);
            ss>> this->iter;
            counter++;
        }
        else{
            printeror();
            exit(-1);
        }

    }
}
/*
 * read from file + check
 * creating in forest num of drone and drones + update every drone with his starting point and velocity.
 * converting from input to double.
 */
void Meneger::creatfromFile2(std::string &name) {
    int counter=0;
    double xLocation = 0, yLocation = 0, xSpeed = 0, ySpeed = 0;
    Vector2f pos,vel;
    std::ifstream file(name);
    if(!file.is_open()){
        printeror();
        exit(-1);
    }
    std::string line,extra;
    while (getline(file,line)){
        if(counter==0&&!checkstr(line)){
            printeror();
            exit(-1);
        }
        if(counter==0 && numofspace(line)==0){
            std::stringstream ss(line);
            int num;
            ss>>num;
            this->forest->setSizeOfDrone(num);
            counter++;
            continue;
        }
        if(counter>0 && numofspace(line)==4){
            char type;
            std::stringstream ss(line);
            if(!(ss>>type)|| !(ss>>xLocation)|| !(ss>>yLocation) || !(ss>>xSpeed)|| !(ss>>ySpeed)){
                printeror();
                exit(-1);
            }
            if(ss>>extra){
                printeror();
                exit(-1);
            }
            pos.setX(xLocation);
            pos.setY(yLocation);
            vel.setX(xSpeed);
            vel.setY(ySpeed);
            creatdrones(type,pos,vel);
            this->forest->getCells()[(int)floor(pos.getX())][(int)floor(pos.getY())]++;
            setingglobal(pos);
        }
        else{
            printeror();
            exit(-1);
        }

    }
    
}
/*
 * start calls to all function that builds the fields.
 * and start the simulation with a for loop
 * in the loop ther is a call to next step and check if on of drones is in the target point.
 */
void Meneger::start(std::string &name, std::string &name2,std::string &name3,int randnum) {
    this->rand=randnum;
    creatfromFile1(name);
    creatfromFile2(name2);
    for(int i=1;i<= this->iter;i++){
        if(droneisthere()){
            printtofile(name3, i);
            break;
        }
        treenextstep(this->forest->getDroneTree()->getRoot());
    }
    printtofile(name3, this->iter);
}

// checks if one of the drone is in te the target point.
bool Meneger::droneisthere()const {
    bool flag = false;
    droneisthere(this->forest->getDroneTree()->getRoot(),flag);
    return flag;
}

Node *Meneger::droneisthere(Node *root,bool &flag)const {
    if(root!= nullptr){
        if(root->getValue()->getPosition().distance(this->forest->getTarget())==0){
            flag= true;
        }
        droneisthere(root->getLeft(), flag);
        droneisthere(root->getRight(),flag);
    }
    return root;
}
// update cells when drone is leave there area or join.
void Meneger::cellcurrentstat(Cell &curent, Cell &tobe) {
    this->forest->getCells()[(int)floor(curent.getcell().getX())][(int)floor(curent.getcell().getY())]--;
    this->forest->getCells()[(int)floor(tobe.getcell().getX())][(int)floor(tobe.getcell().getY())]++;
}
//print to the file we got in the input by format.
void Meneger::printtofile(std::string &name, int iterTmp) {
    std::ofstream file(name,std::ofstream::trunc);
    if(!file.is_open()){
        Meneger::printeror();
        exit(-1);
    }
    file<<iterTmp<<std::endl;
    printvalue(this->forest->getDroneTree()->getRoot(),file);
    file.close();
}
//recursive method to print every value
void Meneger::printvalue(Node *root, std::ofstream &name) const {
    if(root!= nullptr){
        name<<*root->getValue();
        printvalue(root->getLeft(),name);
        printvalue(root->getRight(),name);
    }
}

//set new global in the creat from file time.
void Meneger::setingglobal(const Vector2f &global) {
    Drone::setGlobalBest(global);

}

void Meneger::creatdrones(char type, Vector2f &pos, Vector2f &vel) {
    Drone* drone;
    switch(type){
        case 'S':
            drone = new SingleRotorDrone(pos.getX(),pos.getY(),vel.getX(),vel.getY(),pos,type, this->rand);
            drone->setlimits(this->forest->minX, this->forest->minY,this->forest->maxX,this->forest->maxY);
            this->forest->getDroneTree()->insert(drone);
            break;
            
        case 'M':
             drone = new MultiRotorDrone(pos.getX(),pos.getY(),vel.getX(),vel.getY(),pos,type, this->rand);
            this->forest->getDroneTree()->insert(drone);
            drone->setlimits(this->forest->minX, this->forest->minY,this->forest->maxX,this->forest->maxY);
            break;
        case 'W':
            drone = new FixedWingDrone(pos.getX(),pos.getY(),vel.getX(),vel.getY(),pos,type, this->rand);
            this->forest->getDroneTree()->insert(drone);
            drone->setlimits(this->forest->minX, this->forest->minY,this->forest->maxX,this->forest->maxY);
            break;
        case 'H':
            drone = new FixedWingHybridVTOL(pos.getX(),pos.getY(),vel.getX(),vel.getY(),pos,type, this->rand);
            this->forest->getDroneTree()->insert(drone);
            drone->setlimits(this->forest->minX, this->forest->minY,this->forest->maxX,this->forest->maxY);
            break;
        default:
            printeror();
            exit(-1);
    }

}

Meneger::~Meneger() {
    delete this->forest;
}






#include <iostream>
#include "Meneger.h"
using namespace std;
/*
 * the main of the project get the names of the files + can also get num and passing to the manager
 * that using all the data.
 * the main also check that there is 4 input in the commandline.
 *
 */
int main(int argc,char* argv[]) {
    Meneger meneger;
    int randnum=0;
    if(argc!=4&&argc!=5){
        meneger.printeror();
        exit(-1);
    }
    //in case there is another field (number)
    if(argc==5){
        std::string num(argv[4]);
        //checking that the number is valid
        for(unsigned int i=0;i<num.size();i++){
            if(num[0]=='-'){
                continue;
            }
            if(!isdigit(num[i])){
                meneger.printeror();
                exit(-1);
            }
        }
        //change from str to int
         randnum = stoi(num);
    }
    std::string name(argv[1]);
    std::string name1(argv[2]);
    std::string name2(argv[3]);
    meneger.start(name,name1,name2,randnum);
    return 0;
}

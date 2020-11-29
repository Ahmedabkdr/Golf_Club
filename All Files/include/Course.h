#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Course
{
    public:
        //constructors
        Course();
        Course(string);
        Course(string,int indexes[18],int pars[18]);

        //destructors
        virtual ~Course();

        //accessors
        string getName(){return name;}
        int getIndex(int h){return index[h-1];}
        int getPar(int h){return par[h-1];}
        int getHoles(){return TOTALHOLES;}

        //Index & Par Check
        void checkHoles();
        void checkIndex();
        void checkPar();

        //setters
        void setIndex(int h,int in){index[h-1]=in;} // same as below
        void setPar(int h,int npar){par[h-1]=npar;} // No error detection as it's used only for reading in data from a file
        void rename();
        void changePar();
        void resetIndexes();
        void resetPars();
        //display
        void display();

    protected:

    private:
        string name;
        const static int TOTALHOLES = 18;
        int index[18]={15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,18,17,16};
        int par[18]={3,4,3,4,3,4,5,3,4,3,5,5,4,5,4,3,5,4};
};

#endif // COURSE_H

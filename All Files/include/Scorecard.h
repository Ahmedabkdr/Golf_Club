#ifndef SCORECARD_H
#define SCORECARD_H
#include <iostream>
#include <string>
#include "Course.h"
#include "Player.h"
#include <iomanip>

using namespace std;

class Scorecard
{
    public:
        Scorecard(Player a,Course course);
        Scorecard(Player a,Course course, int strokesIn[18]);
        virtual ~Scorecard();

        int getHoles() { return TOTALHOLES; }

        string getCourseName(){return courseName;}
        string setCourseName(string name){courseName=name;}

        int getIndex(int h){return index[h-1];}
        void setIndex(int h,int in){index[h-1]=in;}

        int getPar(int h){return par[h-1];}
        void setPar(int h,int npar){par[h-1]=npar;}

        int getFreeStrokes(int x) { return freeStrokes [x-1]; }
        void setFreeStrokes(int h,int fs){freeStrokes[h-1]=fs;}

        int getStrokes(int h){return strokes[h-1];}
        void setStrokes(int h, int z) { strokes [h] = z; }

        int getNetStrokes(int h){return netStrokes[h-1];}
        void setNetStrokes(int h, int z) { netStrokes [h] = z; }

        int getPoints(int h){return points[h-1];}
        void setPoints(int h, int z) { points [h] = z; }

        void display();

    protected:

    private:
        string courseName;
        string playerName;
        int playerAge;
        int playerHandicap;
        const static int TOTALHOLES = 18;
        int index [18] = {0};
        int par [18] = {0};
        int freeStrokes [18] = {0};
        int strokes [18] = {0};
        int netStrokes [18] = {0};
        int points [18] = {0};
};

#endif // SCORECARD_H

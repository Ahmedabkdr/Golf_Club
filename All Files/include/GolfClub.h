#ifndef GOLFCLUB_H
#define GOLFCLUB_H
#include "Scorecard.h"
#include "Store.h"


class GolfClub
{
    public:
        GolfClub();
        virtual ~GolfClub();

        void add();
        void addR(string,int indexes[18],int pars[18]);
        void addPlayer();
        void addPlayerAuto(string,string,string,int,int);
        void deletePlayer();

        void login();

        void menu();

        //displays
        void displayCourse(int);
        void displayCourses();

        friend fstream& operator<< (fstream& out, const GolfClub& gc);
        friend fstream & operator>> (fstream& in,  GolfClub& obj);

    protected:

    private:
        vector<Course*> courses;
        vector<Player*> players;
        vector<string*> usernames;
        vector<string*> passwords;
        int ID = -1;
};

#endif // GOLFCLUB_H

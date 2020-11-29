#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include <vector>
#include "Course.h"

using namespace std;

//forward declaration
class Scorecard;

class Player
{

    public:
        Player();
        Player(string,string,string,int,int);
        virtual ~Player();

        string getName() { return name; }
        void setName(string val) { name = val; }

        int getAge() { return age; }
        void setAge(int val) { age = val;}

        int getHandicap() { return handicap; }
        void setHandicap(int val) { handicap = val; }

        string getUsername() {return username;}
        void setUsername(string val){username = val;}

        string getPassword() {return password;}
        void setPassword(string val){password = val;}

        void addScorecard(Course);
        void addScorecardAuto(Course,int strokesIn[18]);
        void deleteScorecard(int);
        void displayScorecard(int);
        void displayScorecards();
        int getScorecardsSize();
        string getCourseName(int);
        int getStrokes(int,int);

        void display();

        friend fstream& operator<< (fstream& out, const Player& p);
        friend fstream & operator>> (fstream& in,  Player& p);

    protected:

    private:
        string username;
        string password;
        string name;
        int age;
        int handicap;
        vector<Scorecard*> scorecards;
};

#endif // PLAYER_H

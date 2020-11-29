#include "GolfClub.h"
#include "Scorecard.h"
#include "Store.h"
#include "Product.h"
//#include <windows.h>
//#include <mmsystem.h>
#include <ctype.h>

fstream& operator<< (fstream& out, const GolfClub& gc){
    out << gc.courses.size() << "\n";
    for(int i=0;i<gc.courses.size();i++){
        out << gc.courses[i]->getName() << "\n";
        for(int j=1; j<=gc.courses[i]->getHoles();j++)
            out << gc.courses[i]->getIndex(j) << "\n" << gc.courses[i]->getPar(j) << "\n";
    }
    cout<<"\n";

    Player *currentPlayer;
    for(int i=0;i<gc.players.size();i++){
        currentPlayer = gc.players[i];
        out << currentPlayer->getUsername() << "\n" << currentPlayer->getPassword() << "\n" << currentPlayer->getName() << "\n";
        out << currentPlayer->getAge() << "\n" << currentPlayer->getHandicap() <<"\n";
        out << currentPlayer->getScorecardsSize() << "\n";
        for (int scorecard=1;scorecard<=currentPlayer->getScorecardsSize();scorecard++){
            out << currentPlayer->getCourseName(scorecard) << "\n";
            for (int hole=1;hole<=18;hole++){
                out << currentPlayer->getStrokes(scorecard,hole) << " ";
            }
            out << "\n";
        }
    }

    return out;
}

// this puts info from the file into the GolfClub c's courses
fstream& operator>> (fstream& in,  GolfClub& gc){
    //get courses info

    //get number of courses
    int coursesSize=0;
    in >> coursesSize;
    for(int currentCourse=0;currentCourse<coursesSize;currentCourse++){
        string name;
        int currentIndexes[18]={0};
        int currentPars[18]={0};
        in>>ws;
        getline(in,name);
        for(int j=1;j<=18;j++){
            in >> currentIndexes[j-1];
            in >> currentPars[j-1];
        }
        gc.addR(name,currentIndexes,currentPars);
    }

    //get players info
    int playerCount = 0;
    in>>ws;
    while(!in.eof()){
        string user,pass,name;
        int age,handi,scorecardsSize;
        in>>user;
        in>>pass;
        in>>name;
        in>>age;
        in>>handi;
        gc.players.push_back(new Player(user,pass,name,age,handi));
        gc.usernames.push_back(new string(user));
        gc.passwords.push_back(new string(pass));
        in>>scorecardsSize;
        for (int currentCard=0;currentCard<scorecardsSize;currentCard++){
            string currentName;
            in >> currentName;
            int currentStrokes[18]={0};
            for (int j=0;j<18;j++){
                in>>currentStrokes[j];
            }
            int courseID = 0;
            for (int i = 0; i<gc.courses.size();i++){
                if (gc.courses[i]->getName()==currentName){
                    courseID = i;
                }
            }
            gc.players[playerCount]->addScorecardAuto(*gc.courses[courseID],currentStrokes);
        }
        playerCount++;
        in>>ws;
    }
	return in;
}

fstream& operator<< (fstream& out, const Store& c){
    for(int i=0;i<c.products.size();i++)
    out <<c.products[i]->Getname() << "\n" << c.products[i]->Getstock() << "\n" << c.products[i]->Getprice() << "\n" << c.products[i]->Getrental() <<endl;
    if (c.rented.size()>0){
    out <<"Rented"<<endl;
    for(int i=0;i<c.rented.size();i++)
    out <<c.rented[i]->Getname() << "\n" << c.rented[i]->Getstock() << "\n" << c.rented[i]->Getprice() << "\n" << c.rented[i]->Getrental() <<endl;
    }
    return out;
}

fstream & operator>> (fstream& in,  Store& obj){
    string a;
    int b,c,d;
    in >> ws;
    while(!in.eof()){
        getline(in,a);
        if(a=="Rented"){
            while(!in.eof()){
            getline(in,a);
            in >> b;
            in >> c;
            in >> d;
            in >> ws;
            obj.rented.push_back(new Product(a,b,c,d));
            }
            return in;
        }
        in >> b;
        in >> c;
        in >> d;
        in >> ws;
        obj.products.push_back(new Product(a,b,c,d));
    }
	return in;
}

using namespace std;

int main()
{
    GolfClub gc;
    fstream gcinfo("gcinfo.txt", ios::in);
    if (gcinfo.is_open()){
           gcinfo >> gc;
           gcinfo.close();
    }

    gc.menu();

    gcinfo.open("gcinfo.txt", ios::out);
    gcinfo << gc;
    gcinfo.close();
	return 0;
}

//Test Code:

/*
GolfClub c;
    fstream cinfo("cinfo.txt", ios::in);
    if (cinfo.is_open()){

           cinfo >> c;
           cinfo.close();
    }

    c.displayCourse(0);
    c.displayCourse(1);
    c.displayCourse(2);

    cinfo.open("cinfo.txt", ios::out);
    cinfo << c;
    cinfo.close();
    */

    /*gc.addPlayerAuto("Lakeen","12345678","Harlem",33,22);
    gc.addPlayerAuto("Hashee","whyeight","Hirra",12,2);
    int chocIndexes[18]={15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,18,17,16};
    int chocPars[18]={3,5,4,3,5,4,3,5,4,5,3,4,5,4,3,5,5,4};
    int bocIndexes[18]={9,8,7,6,5,4,3,2,1,18,17,16,15,14,13,12,11,10};
    int bocPars[18]={3,5,4,3,5,3,4,5,3,4,5,4,3,5,5,3,4,5};
    gc.addR("Chocolate",chocIndexes,chocPars);
    gc.addR("Bocolate",bocIndexes,bocPars);*/

#include "Scorecard.h"


Scorecard::Scorecard(Player a, Course course)
{
    courseName = course.getName();
    playerName = a.getName();
    playerAge = a.getAge();
    playerHandicap = a.getHandicap();

    for(int i = 1;i<=18;i++){
        setIndex(i,course.getIndex(i));
        setPar(i,course.getPar(i));
    }

    int fs1 = playerHandicap/TOTALHOLES;
    int fs2 = playerHandicap%TOTALHOLES;

    for(int i=0; freeStrokes[17]<fs1 ;i++){
        freeStrokes[i] = fs1;
        }

    for(int i=0; i<TOTALHOLES; i++){
        if(index[i]<=fs2){
            freeStrokes[i]++;
        }
    }

    cout << endl << "Please enter your strokes" << endl;
    for (int i = 0; i<18; i++){
        cout << "Hole #" << i+1 << ":" ;
        cin >> strokes [i] ;
    }

    //calculation of netstrokes
    for (int i = 0; i<18; i++){
        netStrokes[i]=strokes[i] - freeStrokes[i];
    }

    //calculation of points
    for (int i=0; i<18; i++){
        if (netStrokes[i] - (par[i])> 2)
            points[i]=0;
        else
            points[i]=2-(netStrokes[i] - (par[i]));
    }

}

//need to test this
Scorecard::Scorecard(Player a, Course course,int strokesIn[18])
{
    courseName = course.getName();
    playerName = a.getName();
    playerAge = a.getAge();
    playerHandicap = a.getHandicap();

    for(int i = 1;i<=18;i++){
        setIndex(i,course.getIndex(i));
        setPar(i,course.getPar(i));
    }

    int fs1 = playerHandicap/TOTALHOLES;
    int fs2 = playerHandicap%TOTALHOLES;

    for(int i=0; freeStrokes[17]<fs1 ;i++){
        freeStrokes[i] = fs1;
        }

    for(int i=0; i<TOTALHOLES; i++){
        if(index[i]<=fs2){
            freeStrokes[i]++;
        }
    }

    for (int i = 0; i<18; i++){
        strokes[i]=strokesIn[i];
    }

    //calculation of netstrokes
    for (int i = 0; i<18; i++){
        netStrokes[i]=strokes[i] - freeStrokes[i];
    }

    //calculation of points
    for (int i=0; i<18; i++){
        if (netStrokes[i] - (par[i])> 2)
            points[i]=0;
        else
            points[i]=2-(netStrokes[i] - (par[i]));
    }

}

void Scorecard::display()
{
    string line = "-------------------------------------------------------------------------------";
    cout << line << endl << right << setw(35) << " " << "SCORECARD" << endl;
    cout << line;

    cout << endl << "NAME: " << playerName << endl;
    cout << "AGE: " << playerAge << endl;
    cout << "HANDICAP: " << playerHandicap << endl;
    cout << "COURSE: " << courseName << endl;

    cout << line
    << endl << left << setw(7) << "Hole";

    for (int i=1; i<19; i++){
            cout << right << setw(4) << i;
    }

    cout << endl << line << endl << left << setw(7) << "Par";

    for (int i=0; i<18; i++){
            cout << right << setw(4) << par[i];
    }

    cout << endl << line << endl << left << setw(7) << "Index";

    for (int i=0; i<18; i++){
            cout << right << setw(4) << index[i];
    }

    cout << endl << line << endl << left << setw(7) << "Strokes";

    for (int i=0; i<18; i++){
            cout << right << setw(4) << strokes[i];
    }

    cout << endl << line << endl << left << setw(7) << "Free";

    for (int i=0; i<18; i++){
            cout << right << setw(4) << freeStrokes[i];
    }

    cout << endl << line << endl << left << setw(7) << "Net";

    for (int i=0; i<18; i++){
            cout << right << setw(4) << netStrokes[i];
    }

    cout << endl << line << endl << left << setw(7) << "Points";

    for (int i=0; i<18; i++){
            cout << right << setw(4) << points[i];
    }

    cout << endl << line << endl << endl;
}


Scorecard::~Scorecard()
{
    //dtor
}

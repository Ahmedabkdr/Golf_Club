#include "GolfClub.h"

GolfClub::GolfClub()
{
    //ctor
}

void GolfClub::add(){
    courses.push_back(new Course);
}

//add a course with the name n and with h holes
void GolfClub::addR(string n,int indexes[18],int pars[18]){
    courses.push_back(new Course(n,indexes,pars));
}

void GolfClub::addPlayer(){
    players.push_back(new Player);
    ID = players.size()-1;
    string userIn = players[ID]->getUsername();
    string passIn = players[ID]->getPassword();
    usernames.push_back(new string(userIn));
    passwords.push_back(new string(passIn));
}

void GolfClub::addPlayerAuto(string userIn, string passIn, string nameIn, int ageIn, int handiIn){
    players.push_back(new Player(userIn,passIn,nameIn,ageIn,handiIn));
    ID = players.size()-1;
    usernames.push_back(new string(userIn));
    passwords.push_back(new string(passIn));
}

void GolfClub::deletePlayer(){
    delete players[ID];
    players.erase(players.begin()+ID);
}

void GolfClub::login(){
    ID=-1;
    string userIn;
    string passIn;
    int choice = 0;
    do{
        cout << "Username: ";
        cin >> userIn;
        for (int i = 0; i<usernames.size();i++){
            if (*usernames[i]==userIn){
                ID = i;
                choice = 0;
            }
        }
        if (ID==-1){
            cout << "\nThe username you entered does not exist."
            "\nDo you want to try again?\n\n(1) Yes     (2) No\n\n";
            cin>>choice;
            cout<<"\n";
        }
    }while(choice==1);
    choice=1;
    while (ID!=-1 && choice==1){
        cout << "Password: ";
            cin >> passIn;
            cout << "\n\n";
            if (passIn==*passwords[ID]){
                cout << "Welcome " << players[ID]->getName() << "!\n\n";
                choice = 2;
            }
            else {
                cout<<"Wrong password. Do you want to try again?\n\n(1) Yes     (2) No\n\n";
                cin>>choice;
                cout<<"\n\n";
                if (choice!=1){
                    ID=-1;
                }
            }
    }
}

void GolfClub::menu(){
    int option = -1;
    while (option != 0){
        cout << "Hi there, Welcome to the Club!" << endl;
        cout << endl << "Please choose one of the following options." << endl << endl;
        cout << "(1)Login     (2)Sign Up     (3)Club Store     (4)Manage Courses     (0)Exit\n\n";

        //PlaySound(TEXT("apsolutions1.wav"), NULL, SND_SYNC);
        //PlaySound(TEXT("apsolutions4.wav"), NULL, SND_SYNC);

        cin >> option;
        cout << "\n";
        if (option==1){
            login();
            if (ID!=-1){
                int uOption = -1;
                while (uOption!=0){
                    players[ID]->display();
                    cout << "(1) Scorecards     (2)Club Store     (3)Manage Account     (0)Exit\n\n";
                    cin >> uOption;
                    cout << "\n";

                    if (uOption==1){
                            int sOption = -1;
                            while (sOption != 0){
                                players[ID]->displayScorecards();
                                cout << "(1) Create New Scorecard     (2) Delete Scorecard     (0) Exit\n\n";
                                cin >> sOption;
                                cout <<"\n";
                                if (sOption==1){
                                    int cOption=-1;
                                    Course* course;
                                    do{
                                        cout<<"Pick a course: ";
                                        for(int i = 0;i<courses.size();i++){
                                            cout<<"("<<i+1<<")"<<courses[i]->getName()<<"     ";
                                        }
                                        cout<<"(0) Exit\n\n";
                                        cin >> cOption;
                                        cout << "\n";
                                        if (cOption>0 && cOption<=courses.size()){
                                            course = courses[cOption-1];
                                            players[ID]->addScorecard(*course);
                                            players[ID]->displayScorecard(players[ID]->getScorecardsSize());
                                        }
                                        else if (cOption==0){
                                            uOption=0;
                                        }
                                        else{
                                            cout<<"Invalid choice.\n\n";
                                        }
                                    }while (cOption != 0);
                                }
                                else if (sOption==2){
                                    cout<<"Enter the number of the scorecard you wish to delete: ";
                                    int nDelete = -1;
                                    cin>> nDelete;
                                    cout<<"\n";
                                    players[ID]->displayScorecard(nDelete);
                                    cout<<"\nAre you sure you want to delete this scorecard?\n\n(1)Yes     (2)No\n\n";
                                    int confirm = -1;
                                    cin>>confirm;
                                    cout<<"\n";
                                    if (confirm == 1){
                                        players[ID]->deleteScorecard(nDelete);
                                    }
                                }
                                else if (sOption!=0){
                                    cout<<"Invalid choice\n\n";
                                }
                            }
                        }
                    else if (uOption==2){

                        Store GolfStore;
                        fstream sinfo("sinfo.txt", ios::in);
                        if(sinfo.is_open()){
                            sinfo>>ws;
                            sinfo>>GolfStore;
                            sinfo.close();
                        }
                        else {
                            sinfo.open("sinfo.txt",ios::out);
                            sinfo.close();
                        }

                        cout<<endl;

                        GolfStore.menu();

                        sinfo.open("sinfo.txt",ios::out);
                        sinfo << GolfStore;
                        sinfo.close();

                    }
                    else if (uOption==3){
                        int mOption=-1;
                        while (mOption!=0){
                            players[ID]->display();
                            cout<<"(1)Change Username     (2)Change Password     (3)Change Name     (4)Change Age     "
                            "(5)Change Handicap     \n(6)Delete Account     (0)Exit\n\n";
                            cin>>mOption;
                            cout<<"\n";
                            if (mOption==1){
                                cout<<"New Username: ";
                                cin>>*usernames[ID];
                                cout<<"\n\n";
                                players[ID]->setUsername(*usernames[ID]);
                            }
                            else if (mOption==2){
                                cout<<"Your new password should be at least 8 characters long.\n\n";
                                bool confirmed = false;
                                while (confirmed==false){
                                    string passCompare1;
                                    string passCompare2;
                                    cout<<"New Password: ";
                                    cin>>passCompare1;
                                    if(passCompare1.length()>=8){
                                        cout<<"Confirm Password: ";
                                        cin>>passCompare2;
                                        if (passCompare1==passCompare2){
                                            *passwords[ID]=passCompare2;
                                            players[ID]->setPassword(*passwords[ID]);
                                            confirmed=true;
                                            cout<<"\n\n";
                                        }
                                        else{
                                            cout<<"\nYour passwords did not match.\n\n";
                                        }
                                    }
                                    else{
                                        cout<<"\nYour new password should be at least 8 characters long.\n\n";
                                    }
                                }
                            }
                            else if (mOption==3){
                                string newName;
                                cout<<"New Name: ";
                                cin>>newName;
                                cout<<"\n\n";
                                players[ID]->setName(newName);
                            }
                            else if (mOption==4){
                                int newAge;
                                cout<<"New Age: ";
                                cin>>newAge;
                                cout<<"\n\n";
                                players[ID]->setAge(newAge);
                            }
                            else if (mOption==5){
                                int newHandicap;
                                cout<<"New Handicap: ";
                                cin>>newHandicap;
                                cout<<"\n\n";
                                players[ID]->setHandicap(newHandicap);
                            }
                            else if (mOption==6){
                                cout<<"Are you sure you want to delete this account?\nYou cannot"
                                " undo this action.\n\n(1)Yes     (2)No\n\n";
                                int confirm = 2;
                                cin>>confirm;
                                cout<<"\n";
                                if (confirm==1){
                                    deletePlayer();
                                    ID=-1;
                                    mOption=0;
                                    uOption=0;
                                    cout<<"Account Deleted.\n\n\n\n";
                                }

                            }
                            else if (mOption!=0){
                                cout<<"\nInvalid choice\n\n";
                            }
                        }

                    }
                    else if (uOption!=0){
                        cout<<"Invalid choice.\n\n";
                    }
                }

            }
        }
        else if (option==2){
            players.push_back(new Player);
            usernames.push_back(new string(players[players.size()-1]->getUsername()));
            passwords.push_back(new string(players[players.size()-1]->getPassword()));
        }

        else if (option==3){
            Store GolfStore;
            fstream sinfo("sinfo.txt", ios::in);
            if(sinfo.is_open()){
                sinfo>>ws;
                sinfo>>GolfStore;
                sinfo.close();
            }
            else {
                sinfo.open("sinfo.txt",ios::out);
                sinfo.close();
            }

            cout<<endl;

            GolfStore.menu();

            sinfo.open("sinfo.txt",ios::out);
            sinfo << GolfStore;
            sinfo.close();
        }

        else if (option==4){
            cout<<"Please enter the admin password (admin): ";
            string pass = "";
            cin>>pass;
            cout<<"\n";
            if (pass=="admin"){
                int cOption=-1;
                while (cOption!=0){
                    for(int i = 0;i<courses.size();i++){
                        cout<<"("<<i+1<<")"<<courses[i]->getName()<<"\n";
                    }
                    cout<<"("<<courses.size()+1<<")New Course";
                    cout<<"\n\n(#)Select     (0)Exit\n\n";
                    cin>>cOption;
                    cout<<"\n";
                    if(cOption>0 && cOption<=courses.size()){
                        int mOption=-1;
                        while (mOption!=0){
                            displayCourse(cOption-1);
                            cout<<"(1)Rename   (2)Set New Indexes     (3)Set New Pars     (4) Edit Par     (0) Exit\n\n";
                            cin>>mOption;
                            cout<<"\n";
                            if (mOption==1){
                                courses[cOption-1]->rename();
                            }
                            else if (mOption==2){
                                courses[cOption-1]->resetIndexes();
                            }
                            else if(mOption==3){
                                courses[cOption-1]->resetPars();
                            }
                            else if(mOption==4){
                                courses[cOption-1]->changePar();
                            }
                            else if(mOption!=0){
                                cout<<"Invalid choice.\n\n";
                            }
                        }
                    }
                    else if(cOption==courses.size()+1){
                        courses.push_back(new Course);
                    }
                    else if(cOption!=0){
                        cout<<"Invalid choice.\n\n";
                    }
                }

            }
            else{
                cout<<"Wrong password.\n\n";
            }
        }

        else if (option!=0){
            cout<<"Invalid choice.\n\n";
        }
    }

}

void GolfClub::displayCourse(int i){
    courses[i]->display();
}

void GolfClub::displayCourses(){
    for (int i=0;i<courses.size();i++){
        cout<<"Course #"<<i+1<<":\n\n";
        displayCourse(i);
        if (i<courses.size()-1){
        cout<<"\n";
    }
    }
}

GolfClub::~GolfClub()
{
    //dtor
    for(int i=0;i<courses.size();i++){
        delete courses[i];
    }
    for(int i=0;i<players.size();i++){
        delete players[i];
    }
    for(int i=0;i<usernames.size();i++){
        delete usernames[i];
    }
    for(int i=0;i<passwords.size();i++){
        delete passwords[i];
    }

    courses.clear();
    players.clear();
    usernames.clear();
    passwords.clear();
}


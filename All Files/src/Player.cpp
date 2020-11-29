#include "Player.h"
#include "Scorecard.h"

Player::Player()
{
    cout << "Welcome to the club! Please enter your desired username: ";
    cin >> username;

    do{
    cout << "Please enter a password that is at least 8 letters long: ";
    cin >> password;
    }while(password.length()<8);

    string confirmPass;

    do{
    cout << "Please confirm your password: ";
    cin >> confirmPass;
    }while(confirmPass!=password);

    cout << "Enter player name: ";
    cin.ignore();
    getline(cin,name);

    cout << "Enter player age: ";
    cin >> age;

    cout << "Enter player handicap: ";
    cin >> handicap;
    cout << "\n\n";
}

Player::Player(string userIn, string passIn, string nameIn, int ageIn, int handiIn){
    username = userIn;
    password = passIn;
    name = nameIn;
    age = ageIn;
    handicap = handiIn;
}

void Player::addScorecard(Course course){
    scorecards.push_back(new Scorecard(*this,course));
}

void Player::addScorecardAuto(Course course,int strokesIn[18]){
    scorecards.push_back(new Scorecard(*this,course,strokesIn));
}

void Player::deleteScorecard(int nDelete){
    delete scorecards[nDelete-1];
    scorecards.erase(scorecards.begin()+(nDelete-1));
}

int Player::getScorecardsSize(){
    return scorecards.size();
}

string Player::getCourseName(int scorecard){
    return scorecards[scorecard-1]->getCourseName();
}

int Player::getStrokes(int scorecard,int hole){
    return scorecards[scorecard-1]->getStrokes(hole);
}

void Player::displayScorecard(int i){
    scorecards[i-1]->display();
}

void Player::displayScorecards(){
    for (int i = 1;i<=scorecards.size();i++){
        cout<<"SCORECARD #"<<i<<"\n\n";
        displayScorecard(i);
        if (i<scorecards.size()){
            cout<<"\n";
        }
    }
}

void Player::display()
{
    cout << "------------------" << endl << "  Player Details" << endl << "------------------" << endl;
    cout << endl << "Name: " << name << endl;
    cout << "Username: " << username << endl;
    cout << "Age: " << age << endl;
    cout << "Handicap: " << handicap << endl << endl;
}

Player::~Player()
{
    //dtor
    for (int i=0;i<scorecards.size();i++){
        delete scorecards[i];
    }
    scorecards.clear();
}

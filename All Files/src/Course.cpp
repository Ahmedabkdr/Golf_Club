#include "Course.h"

Course::Course(string n)
{
    name = n;
}

Course::Course(string n,int indexes[18],int pars[18])
{
    name = n;
    for(int i=0;i<TOTALHOLES;i++){
        index[i]=indexes[i];
        par[i]=pars[i];
    }
}

Course::Course()
{
    cout<<"Course Name: ";
    cin>>name;
    cout<<endl<<endl<<"Please enter the indexes and pars of the holes.\n\n";
    for(int i=0, k=1;i<TOTALHOLES;i++){

        cout<<"Hole #"<<i+1<<endl<<endl;
        cout<<"Index: ";
        cin>>index[i];
        do{
                    k=1;
            for(int j=0;j<i;j++){
                if (index[i]==index[j]){
                    cout<<"\n\nYou have already assigned this index to Hole "<<j+1<<". Please enter another index.\n\n";
                    cout<<"Hole #"<<i+1<<endl<<endl;
                    cout<<"Index: ";
                    cin>>index[i];
                    k=0;
                }
            }
            while (index[i]<1 || index[i]>TOTALHOLES){
                cout<<"\n\nThe index can only be an integer between 1 and "<<TOTALHOLES<<". Please enter another index.\n\n";
                cout<<"Hole #"<<i+1<<endl<<endl;
                cout<<"Index: ";
                cin>>index[i];
                k=0;
            }
        }while(k==0);

        cout<<"Par: ";
        cin>>par[i];
        while (par[i]<3 || par[i]>5){
            cout<<"\n\nThe par can only be an integer between 3 and 5. Please enter another par.\n\n";
            cout<<"Hole #"<<i+1<<endl<<endl;
            cout<<"Index: "<<index[i];
            cout<<"\nPar: ";
            cin>>par[i];
            }
            cout<<endl<<endl;
        }
        cout<<endl;
        cout<<"The indexes and pars of the holes in "<<name<<" have now been set."<<endl<<endl;
}

void Course::display(){
    int l=0;
    for(int i=0;name[l]!=NULL;i++){
        l++;
    }
    cout << "-------------------------------------------------------------------------------" << endl << right << setw(26+l) << " " << name << endl;


    cout << "-------------------------------------------------------------------------------" << endl << left << setw(7) << "Hole";
    for (int i=1; i<=TOTALHOLES; i++){
            cout << right << setw(4) << i;
    }
    cout << endl << "-------------------------------------------------------------------------------" << endl << left << setw(7) << "Par";
    for (int i=0; i<TOTALHOLES; i++){
            cout << right << setw(4) << par[i];
    }
    cout << endl << "-------------------------------------------------------------------------------" << endl << left << setw(7) << "Index";
    for (int i=0; i<TOTALHOLES; i++){
            cout << right << setw(4) << index[i];
    }

    cout << endl << "-------------------------------------------------------------------------------" << endl << endl;
}

Course::~Course()
{
    //dtor, consider virtual dtor
}

void Course::rename(){
    cout<<"New Name: ";
    string newName;
    cin>>newName;
    cout<<"\n";
    name=newName;
}

void Course::checkHoles(){
    cout<<"\n\nThe course has "<< TOTALHOLES << " holes.\n\n";
}


void Course::checkIndex(){
    int h;
    cout<<"\n\nPlease enter the number of the hole: ";
    cin>>h;
    cout<<"\n\nThe index of Hole "<<h<<" is "<<index[h-1]<<"."<<endl<<endl;
}

void Course::checkPar(){
    int h;
    cout<<"\n\nPlease enter the number of the hole: ";
    cin>>h;
    cout<<"\n\nThe par of Hole "<<h<<" is "<<par[h-1]<<".\n\n";
}

void Course::changePar(){
    int h;
    cout<<"Please enter the hole mumber: ";
    cin>>h;
    while (h<1 || h>TOTALHOLES){
                cout<<"\n\nThe hole number can only be an integer between 1 and "<<TOTALHOLES<<". Please enter another number: ";
                // change the above to its own method (e.g. holeCheck)
                cin>>h;
    }
    cout<<"\n\nHole #"<<h<<endl<<endl;
    cout<<"Index: "<<index[h-1];
    cout<<"\nPar: ";
        cin>>par[h-1];
        while (par[h]<3 || par[h]>5){
        cout<<"\n\nThe par can only be an integer between 3 and 5. Please enter another par.\n\n";
        cout<<"Hole #"<<h<<endl<<endl;
        cout<<"Index: "<<index[h-1];
        cout<<"\nPar: ";
        cin>>par[h-1];
        }

    cout<<"\n\nThe par for Hole "<<h<<" is now "<<par[h-1]<<".\n\n";
}

void Course::resetIndexes(){
    cout<<endl<<endl<<"Please enter the new indexes of the holes.\n\n";
    for(int i=0, k=1;i<TOTALHOLES;i++){

        cout<<"Hole #"<<i+1<<endl<<endl;
        cout<<"Index: ";
        cin>>index[i];
        do{
                    k=1;
            for(int j=0;j<i;j++){
                if (index[i]==index[j]){
                    cout<<"\n\nYou have already assigned this index to Hole "<<j+1<<". Please enter another index.\n\n";
                    cout<<"Hole #"<<i+1<<endl<<endl;
                    cout<<"Index: ";
                    cin>>index[i];
                    k=0;
                }
            }
            while (index[i]<1 || index[i]>TOTALHOLES){
                cout<<"\n\nThe index can only be an integer between 1 and "<<TOTALHOLES<<". Please enter another index.\n\n";
                cout<<"Hole #"<<i+1<<endl<<endl;
                cout<<"Index: ";
                cin>>index[i];
                k=0;
            }
        }while(k==0);
    }
}

void Course::resetPars(){
    for(int i=0, k=1;i<TOTALHOLES;i++){

        cout<<"Hole #"<<i+1<<endl<<endl;
        cout<<"Par: ";
        cin>>par[i];
        while (par[i]<3 || par[i]>5){
            cout<<"\n\nThe par can only be an integer between 3 and 5. Please enter another par.\n\n";
            cout<<"Hole #"<<i+1<<endl<<endl;
            cout<<"Index: "<<index[i];
            cout<<"\nPar: ";
            cin>>par[i];
            }
            cout<<endl<<endl;
    }
}

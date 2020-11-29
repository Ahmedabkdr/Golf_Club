#include "Store.h"
//#include <windows.h>
//#include <mmsystem.h>

Store::Store()
{
    //ctor
}

void Store::add(){
    products.push_back(new Product);
}

void Store::menu(){

    string c;
    int d=0;
    do{
        if(products.size()>0){
                display();
            }
            else{
                cout<<"No items or services have been added to the store yet."<<endl<<endl;
            }
        cout<<"(#)Select Item     (A)Add Item or Service     (R)Rented Items     (X)Exit"<<endl<<endl;
        //PlaySound(TEXT("apsolutions6.wav"), NULL, SND_SYNC);
        cin>>c;
        istringstream s(c);
        s>>d;
        if(d>0 && (d-1)<products.size()){
            do{
            int i = d;
            details(i);
            cout<<endl<<endl<<"(1)Purchase     (2)Rent     (3)Modify     (R)Return to Main Menu"<<endl<<endl;
            cin>>c;
            istringstream s(c);
            s>>d;
            cout<<endl;
            if(d==1){
                sell(i);
                c="R";
            }
            else if(d==2){
                rent(i);
                c="R";
            }
            else if(d==3){
                do{
                details(i);
                cout<<endl<<endl<<"(1)Name     (2)Stock     (3)Price     (4)Rental     (D)Delete"<<endl;
                cout<<"(R)Return to Main Menu"<<endl<<endl;
                cin>>c;
                istringstream s(c);
                s>>d;
                cout<<endl<<endl;
                if(d==1){
                    products[i-1]->Setname();
                    c="R";
                }
                else if(d==2){
                    products[i-1]->Setstock();
                    c="R";
                }
                else if(d==3){
                    products[i-1]->Setprice();
                    c="R";
                }
                else if(d==4){
                    products[i-1]->Setrental();
                    c="R";
                }
                else if(c=="D"||c=="d"){
                    del(i);
                    c="R";
                }
                else if(c!="R" && c!="r"){
                cout<<endl<<"Invalid Choice"<<endl<<endl;
                d=i;
                }
                }while(c!="R" && c!="r");
            }
            else if(c!="R" && c!="r"){
                cout<<endl<<"Invalid Choice"<<endl<<endl;
                d=i;
            }
            }while(c!="R" && c!="r");
        }
        else if(c=="A" || c=="a")
        {
            add();
        }
        else if(c=="R"||c=="r"){
            do{
                displayR();
                cout<<"(#)Return Item     (R)Return to Main Menu"<<endl<<endl;
                cin>>c;
                istringstream s(c);
                s>>d;
                int i = d;
                if(d>0 && (d-1)<rented.size()){
                    ret(d);
                    c="R";
                }
                else if(c!="R" && c!="r"){
                cout<<endl<<"Invalid Choice"<<endl<<endl;
                d=i;
            }
            }while(c!="R" && c!="r");
            cout<<endl<<endl;
        }
        else if(c!="X" && c!="x"){
            cout<<endl<<endl<<"Invalid Choice"<<endl<<endl;
        }
    }while(c!="X" && c!="x");

}

void Store::display(){
    for(int i=0;i<=45;i++){
            cout<<"-";
    }
    cout<< endl << right << setw(28) << "Club Store"<<endl;
    for(int i=0;i<=45;i++){
            cout<<"-";
    }
    cout<< endl << left << setw(7) << " " << setw(12) << "Product" << setw(10) << "Stock" << setw(10) << "Price" << setw(10) << "Rental"<<endl<<endl;
    for(int i=0,j,k=0;i<products.size();i++){
        for(j=i+1,k=0; j!=0; j/=10,k++);
        cout<< left << setw(k) << (i+1) << left << setw(7-k) << ".";
        cout<< left << setw(12) << products[i]->Getname() << right << setw(5) << products[i]->Getstock();
        cout<< right << setw(10) << products[i]->Getprice() << setw(11) << products[i]->Getrental() << endl << endl;
    }
}

void Store::displayR(){
    cout<<endl<<endl;
    for(int i=0;i<=45;i++){
            cout<<"-";
    }
    cout<< endl << right << setw(29) << "Rented Items"<<endl;
    for(int i=0;i<=45;i++){
            cout<<"-";
    }
    cout<< endl << left << setw(7) << " " << setw(12) << "Product" << setw(10) << "Amount" << setw(10) << "Price" << setw(10) << "Rental"<<endl<<endl;
    for(int i=0,j,k=0;i<rented.size();i++){
        for(j=i+1,k=0; j!=0; j/=10,k++);
        cout<< left << setw(k) << (i+1) << left << setw(7-k) << ".";
        cout<< left << setw(12) << rented[i]->Getname() << right << setw(6) << rented[i]->Getstock();
        cout<< right << setw(9) << rented[i]->Getprice() << setw(11) << rented[i]->Getrental() << endl << endl;
    }
}

void Store::details(int i){
    cout<<endl<<endl;
    //individual product display
    products[i-1]->display();
}

void Store::detailsR(int i){
    cout<<endl<<endl;
    //individual product display
    rented[i-1]->displayR();
}

void Store::sell(int i){
    int q;
    cout<<"Quantity: ";
    cin>>q;
    products[i-1]->Changestock(-q);
    cout<<endl<<endl<<"Purchase complete.";
    cout<<endl<<endl;
}

void Store::rent(int p){
    int q;
    details(p);
    cout<<"Quantity: ";
    cin>>q;
    products[p-1]->Changestock(-q);
    cout<<endl<<endl;
    for(int k=0,i=0;i<=rented.size() && k==0;i++){
            if(rented.size()==0){
                rented.push_back(new Product(products[p-1]->Getname(),q,products[p-1]->Getprice(),products[p-1]->Getrental()));
                k=1;
            }
            else if(rented[i]->Getname()==products[p-1]->Getname()){
                rented[i]->Changestock(q);
                k=1;
            }
            else if(i==rented.size()){
                rented.push_back(new Product(products[p-1]->Getname(),q,products[p-1]->Getprice(),products[p-1]->Getrental()));
                k=1;
    }
    }
    cout<<endl<<endl<<"Rental complete.";
    cout<<endl<<endl;
}

void Store::ret(int p){
    int q;
    detailsR(p);
    cout<<"Quantity: ";
    cin>>q;
    rented[p-1]->Changestock(-q);
    for(int k=0,i=0;i<=rented.size() && k==0;i++){
            if(rented[p-1]->Getname()==products[i]->Getname()){
                products[i]->Changestock(q);
                k=1;
            }
    }
    if (rented[p-1]->Getstock()==0){
                    rented.erase(rented.begin()+(p-1));
                }
    cout<<endl<<endl<<"Item returned.";
    cout<<endl<<endl;
}

void Store::del(int i){
    int j;
    cout<<"Are you sure you want to delete '"<<products[i-1]->Getname()<<"'?";
    cout<<endl<<"(1)Yes     (2)No"<<endl<<endl;
    cin>>j;
    if(j==1){
    products.erase(products.begin()+(i-1));
    cout<<endl<<endl<<"The product has been removed from the store."<<endl<<endl;
    }
}

Store::~Store()
{
    //dtor
    for(int i=0;i<products.size();i++){
        delete products[i];
    }
    for(int i=0;i<rented.size();i++){
        delete rented[i];
    }
    products.clear();
    rented.clear();
}

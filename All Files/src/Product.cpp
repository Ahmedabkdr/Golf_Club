#include "Product.h"

Product::Product()
{
    //ctor
    cin.ignore();
    cout<<"Product name: ";
    getline(cin,name);
    cout<<"Stock: ";
    cin>>stock;
    cout<<"Purchase: ";
    cin>>price;
    cout<<"Rental: ";
    cin>>rental;
    cout<<endl<<endl;
}

Product::Product(string n, int s, int p, int r){
    name = n;
    stock = s;
    price = p;
    rental = r;
}

void Product::display(){
    cout<<name<<endl<<endl;
    cout<<"Stock: "<<stock<<endl;
    cout<<"Purchase: "<<price<<endl;
    cout<<"Rental: "<<rental<<endl<<endl;
}

void Product::displayR(){
    cout<<name<<endl<<endl;
    cout<<"Amount: "<<stock<<endl;
    cout<<"Purchase: "<<price<<endl;
    cout<<"Rental: "<<rental<<endl<<endl;
}

void Product::Setname(){
    string n;
    cout<<"Enter the new name: ";
    cin>>n;
    name=n;
    cout<<endl<<endl;
}

void Product::Setstock(){
    int n;
    cout<<"Enter the stock: ";
    cin>>n;
    stock=n;
    cout<<endl<<endl;
}

void Product::Setprice(){
    int n;
    cout<<"Enter the new price: ";
    cin>>n;
    price=n;
    cout<<endl<<endl;
}

void Product::Setrental(){
    int n;
    cout<<"Enter the new rental: ";
    cin>>n;
    rental=n;
    cout<<endl<<endl;
}

Product::~Product()
{
    //dtor
}

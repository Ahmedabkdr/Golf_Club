#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

class Product
{
    public:
        Product();
        Product(string n, int s, int p, int r);
        virtual ~Product();
        string Getname() { return name; }
        void Setname();
        int Getprice() { return price; }
        void Setprice();
        int Getrental() { return rental; }
        void Setrental();
        int Getstock() { return stock; }
        void Setstock();
        void Changestock(int val){stock+=val;}

        void display();
        void displayR();

    protected:
    private:
        string name;
        int price;
        int rental;
        int stock;
};

#endif // PRODUCT_H

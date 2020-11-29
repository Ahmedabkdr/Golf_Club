#ifndef STORE_H
#define STORE_H
#include "Product.h"
#include <vector>

class Store
{
    public:
        Store();
        void add();
        void display();
        void displayR();
        void menu();
        void sell(int);
        void rent(int);
        void ret(int);
        void details(int);
        void detailsR(int);
        int sizeCheck(){return products.size();}
        void del(int);

        void cleanUp();
        virtual ~Store();

        friend fstream& operator<< (fstream& out, const Store& c);
        friend fstream& operator>> (fstream& in,  Store&);

    protected:
    private:
        vector<Product*> products;
        vector<Product*> rented;
};

#endif

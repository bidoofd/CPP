#include <iostream>
using namespace std;

double division(int a, int b)
{
    if(b == 0)
    {
        throw runtime_error("Error: Attempted to divide by zero\n");
    }

    return (a/b);
}

int main()
{
    int x = 4;
    int y = 2;
    double z;
    try
    {
        z = division(x,y);
        cout << " the result of the division is " << z << endl;
    }
    catch (runtime_error& e)
    {
        cerr << "Exception occured" << endl << e.what();
    }
}

/*

#ifndef AGENT_H
#define AGENT_H
#include "Seller.h"
#include "Buyer.h"
#include <string>
#include <list>

// passing two args through contactSeller
//  -contactedSeller to send information to and store
//  -templist details for info to store to seller
//      -not finished fully because going to work on seller

using namespace std;

struct listingDetails{
    Property* ownedProperty;
    double sellingPrice = 3;
    string date;
    bool soldStatus;
};

class Agent{
    private:
        Seller* contactedSeller;
        Buyer* contactedBuyer;
        listingDetails tempList;

        double sellingPrice;
        string date;
        bool soldStatus;
    public:
        void recordOffer(listingDetails tempList);
        void contactSeller(Seller *contactedSeller, listingDetails tempList);
        void modifyListing(listingDetails tempList);
        double getSellingPrice();
};

#endif

*/

/*

#ifndef AGENT_H
#define AGENT_H
#include "Seller.h"
#include "Buyer.h"
#include <string>
#include <list>

using namespace std;

struct listingDetails{
    Property* ownedProperty;
    double sellingPrice = 3;
    string date;
    bool soldStatus;
};

class Agent{
    private:
        Seller* contactedSeller;
        Buyer* contactedBuyer;
        list<listingDetails*> *listing = new list<listingDetails*>;
    public:
        void recordOffer(listingDetails tempList);
        void contactSeller();
        void modifyListing(listingDetails tempList);
        double getSellingPrice();
        //passed listing through function

        //created getSellingPrice function()
};

#endif

*/
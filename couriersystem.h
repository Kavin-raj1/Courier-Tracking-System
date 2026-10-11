


#include <iostream>
#include <string>
#include "Package.h"
#include <cctype>  // header for isalpha 
using namespace std;

const int MAX_PACKAGE = 50;

class courierSystem {

private:
    Package packages[MAX_PACKAGE];
    int packagecount = 0;//default pakage start with 0 

public:

void addPackage() {

    string id, sName, sAddress, rName, rAddress;
    bool valid;

    if (packagecount >= MAX_PACKAGE) {
        cout << "Sorry. System Full!" << endl;
        return;
    }

    cin.ignore();

    // Package ID
    do {
        cout << "Enter Package ID: ";
        getline(cin, id);

        if (id.length() == 0)
            cout << "ID cannot be empty!\n";

    } while (id.length() == 0);

    // Sender Name
    do {
        valid = true;

        cout << "Enter Sender Name: ";
        getline(cin, sName);

        if (sName.length() == 0)
            valid = false;

        for (int i = 0; i < sName.length(); i++) {
            if (!isalpha(sName[i]) && sName[i] != ' ')
                valid = false;
        }

        if (!valid)
            cout << "Wrong! Name only letters.\n";

    } while (!valid);

    // Sender Address
    do {
        cout << "Enter Sender Address: ";
        getline(cin, sAddress);

        if (sAddress.length() == 0)
            cout << "Address cannot be empty!\n";

    } while (sAddress.length() == 0);

    // Receiver Name
    do {
        valid = true;

        cout << "Enter Receiver Name: ";
        getline(cin, rName);

        if (rName.length() == 0)
            valid = false;

        for (int i = 0; i < rName.length(); i++) {
            if (!isalpha(rName[i]) && rName[i] != ' ')
                valid = false;
        }

        if (!valid)
            cout << "Wrong! Name only letters.\n";

    } while (!valid);

    // Receiver Address
    do {
        cout << "Enter Receiver Address: ";
        getline(cin, rAddress);

        if (rAddress.length() == 0)
            cout << "Address cannot be empty!\n";

    } while (rAddress.length() == 0);

    Package *packagePtr = &packages[packagecount];   // pointer to current empty slot
    packagePtr->setDetails(id, sName, sAddress, rName, rAddress);

    packagecount++;

    cout << "Package added successfully!" << endl;
}

void viewPackage() {

    if (packagecount == 0) {
        cout << "No packages found.\n";
        return;
    }

    for (int i = 0; i < packagecount; i++) {

        Package *packagePtr = &packages[i];   
        packagePtr->showDetails();
    }
}

void trackPackage() {

    string id;

    while (true) {

        cout << "\nEnter Package ID (0 to back): ";
        cin >> id;

        if (id == "0")
            return;

        for (int i = 0; i < packagecount; i++) {

            if (packages[i].getPackage_ID() == id) {

                Package *packagePtr = &packages[i];   
                packagePtr->showDetails();

                return;
            }
        }

        cout << "ID not found.\n";
    }
}

void updateStatus() {

    string id;

    while (true) {

        cout << "\nEnter Package ID (0 cancel): ";
        cin >> id;

        if (id == "0")
            return;

        for (int i = 0; i < packagecount; i++) {

            if (packages[i].getPackage_ID() == id) {

                Package *packagePtr = &packages[i];   
                int choice;

                cout << "1. Order Placed\n";
                cout << "2. Parcel In Transit\n";
                cout << "3. Out for Delivery\n";
                cout << "4. Delivered\n";
                cout << "Enter choice: ";
                cin >> choice;

                if (choice == 1)
                    packagePtr->setStatus("Order Placed");

                else if (choice == 2)
                    packagePtr->setStatus("Parcel In Transit");

                else if (choice == 3)
                    packagePtr->setStatus("Out for Delivery");

                else if (choice == 4)
                    packagePtr->setStatus("Delivered");

                else {
                    cout << "Invalid choice.\n";
                    continue;
                }

                cout << "Status Updated Successfully!\n";
                return;
            }
        }

        cout << "ID not found.\n";
    }
}

};

#include <iostream>
#include <string>
#include "couriersystem.h"
using namespace std;

int main()
{
    courierSystem courier;
    int choice = 0;

    while (choice != 5)
    {
        cout << "\n=================================================\n";
        cout << "         COURIER TRACKING SYSTEM\n";
        cout << "=================================================\n";
        cout << "  1. Add Package\n";
        cout << "  2. View All Packages\n";
        cout << "  3. Track Package\n";
        cout << "  4. Update Package Status\n";
        cout << "  5. Exit System\n";
        cout << "-------------------------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cout << endl;

        switch (choice)
        {
        case 1:
            courier.addPackage();
            break;

        case 2:
            courier.viewPackage();
            break;

        case 3:
            courier.trackPackage();
            break;

        case 4:
            courier.updateStatus();
            break;

        case 5:
            cout << "=====================================\n";
            cout << " Thank you for using our system.\n";
            cout << " Have a great day!\n";
            cout << "=====================================\n";
            break;

        default:
            cout << " Invalid option. Please try again.\n";
        }
    }

    return 0;
}
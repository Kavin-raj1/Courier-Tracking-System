
#include <iostream>
#include <string>
using namespace std;
//class
class Package{

private:
string PackageID;
string senderName;
string senderAddress;
string receiverName;
string receiverAddress;
string status;


public:
void setDetails(string id,string sName,string sAddress,string rName,string rAddress){
    PackageID = id;
    senderName = sName;
    senderAddress = sAddress;
    receiverName = rName;
    receiverAddress = rAddress;
    status = "Order Placed";

}


void showDetails(){
    

    cout << "\n=====================================\n";
    cout << "           PACKAGE DETAILS\n";
    cout << "=====================================\n";
    cout << " Package ID        : " << PackageID << endl;
    cout << " Sender Name       : " << senderName << endl;
    cout << " Sender Address    : " << senderAddress << endl;
    cout << " Receiver Name     : " << receiverName << endl;
    cout << " Receiver Address  : " << receiverAddress << endl;
    cout << " Current Status    : " << status << endl;
    cout << "=====================================\n";
}


string getPackage_ID(){
    return PackageID;


}

void setStatus(string newStatus){
    status = newStatus;

}



};

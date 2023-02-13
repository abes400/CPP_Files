#include<iostream>
using namespace std;
class Car{
    public:
    string manufacturer, model;
    int year, doors, seats;
    bool autoTransmission;
    
    Car (string tm, string modl, int yr, bool automtc = false, int drs = 4, int sts = 5){
        manufacturer = tm;
        model = modl;
        year = yr;
        autoTransmission = automtc;
        doors = drs;
        seats = sts;
    }
    
    void showInfo(){
        cout << "Manufacturer: " << manufacturer << endl;
        cout << "Model: " << model << " (" << year << ')' << endl;
        cout << "Door count: " << doors << endl;
        cout << "Seat count: " << seats << endl;
        if (autoTransmission){
            cout << "Transmission: Automatic\n\n";
        } else {
            cout << "Transmission: Manual\n\n";
        }
    }
};

int main(){
    Car ibiz("Seat", "Ibiza", 2021, true);
    Car vectra("Opel", "Vectra", 2006, true);
    Car ferrari("Ferrari", "296 GTB", 2022, true, 2, 2);
    
    ibiz.showInfo();
    vectra.showInfo();
    ferrari.showInfo();
    
    string name, model;
    int year, door, seat;
    bool transmission;
    char choice;
    
    cout << "New car model\nEnter Manufacturer: ";
    cin >> name;
    cout << "Enter Model: ";
    cin >> model;
    cout << "Enter Year: ";
    cin >> year;
    cout << "Enter Door Count: ";
    cin >> door;
    cout << "Enter Seat Count: ";
    cin >> seat;
    cout << "Is it automatic? (y/n): ";
    cin >> choice;
    if(choice == 'y' || choice == 'Y') transmission = true;
    else if(choice == 'n' || choice == 'F') transmission = false;
    Car newc (name, model, year, transmission, door, seat);
    cout << endl;
    newc.showInfo();
}
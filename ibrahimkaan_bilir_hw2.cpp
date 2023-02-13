#include<iostream>
using namespace std;

class Hours {
    public:
        int hour, minutes;

        friend ostream & operator << (ostream & a, Hours & hr) {
            a << hr.hour << ':' << hr.minutes;
            return a;
        }

        friend istream & operator >> (istream & a, Hours & hr) {
            a >> hr.hour >> hr.minutes;
            return a;
        }
};

class Animals {
    protected:
        string id, animalName, ownerName, ownerSurname;
        Hours totalHours;
        int totalMins;
    
    public:
        Animals(string a, string b, string c, string d) : id(a), animalName(b), ownerName(c), ownerSurname(d) {}
    
        int calculateMinutes(Hours in, Hours out) {
            if((out.hour > in.hour) && (out.minutes > in.minutes)) {
                totalMins = (out.hour - in.hour) * 60 + (out.minutes - in.minutes);
                cout << "The total time animal stays in the clinic is " << totalMins << " minutes. !\n";
            } else if ((out.hour >= in.hour) && (out.minutes < in.minutes)) {
                totalMins = (out.minutes + 60 - in.minutes) + (out.hour - 1 - in.hour);
                cout << "The total time animal stays in the clinic is " << totalMins << " minutes. !\n";
            } else {
                totalMins = 0;
                cout << "Please enter appropriate time. \n";
            }

            return totalMins;
        }
};

class Cat : public Animals {
    protected:
        string type;

    public:
        Cat(string a, string b, string c, string d, string e) : Animals(a, b, c, d), type(e) {}

        void printInfo() {
            cout << "Id of the animal is " << id << endl;
            cout << "Name of the animal is " << animalName << endl;
            cout << "Name of the animal's owner is " << ownerName << endl;
            cout << "Surname of the animal's owner is " << ownerSurname << endl;
            cout << "Type of the animal is " << type << endl;  
        }
    };

int main() {
    Cat goof("123456", "Goofy", "Kobe", "Bryant", "Cat");
    Hours checkin, checkout;
    
    goof.printInfo();

    cout << "Enter the check in time of the animal:\n";
    cin >> checkin;
    cout << "Enter the check out time of the animal:\n";
    cin >> checkout;

    cout << "Check in and check out times are " << checkin << '/' << checkout << endl;

    goof.calculateMinutes(checkin, checkout);

    return 0;
}
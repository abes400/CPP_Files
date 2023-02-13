#include<iostream>

class DigitalBookArchive {
    private:
    std::string name;
    std::string type;
    int digitalBookCount;

    public:
    DigitalBookArchive(std::string);
    DigitalBookArchive(std::string , std::string);
    void addBook();
    void readBook();
    std::string getName();
    void print();
};

DigitalBookArchive::DigitalBookArchive(std::string newname) : digitalBookCount(20), name(newname), type("") {
    std::cout << "Digital Book Archive name set to " << name << std::endl;
}

DigitalBookArchive::DigitalBookArchive(std::string newname, std::string newtype) : digitalBookCount(20), name(newname), type(newtype) {
    std::cout << "Digital Book Archive name set to " << name << std::endl;
    std::cout << "Digital Book type is: " << type << std::endl;
}

void DigitalBookArchive::addBook() {
    digitalBookCount++;
    std::cout << "A new digital book is added. \n";
}

void DigitalBookArchive::readBook() {
    digitalBookCount--;
    std::cout << "You've read a digital book. \n";
}

std::string DigitalBookArchive::getName() {
    return name;
}

void DigitalBookArchive::print() {
    std::cout << "The number of remaining digital book is " << digitalBookCount << std::endl;
}

int main() {
    using namespace std;

    string newname;
    string newtype;
    char choice;

    cout << "\nEnter the name of the Digital Book Archive:\n";
    cin >> newname;
    cout << "Enter the type of the digital book:\n";
    cin >> newtype;

    DigitalBookArchive books(newname, newtype);

    do{
        cout << "Do you want to add or read a digital book (a/r), \n";
        cout << "or enter (C) for exit the system:";
        cin >> choice;

        switch(choice) {
            case 'a':
            books.addBook();
            break;

            case 'r':
            books.readBook();
            break;

            case 'C':
            books.print();
            break;
        }
    } while (choice != 'C');
    
    cout << endl;

    return 0;
}
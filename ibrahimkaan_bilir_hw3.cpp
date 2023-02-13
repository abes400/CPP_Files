//Homework III, İbrahim Kaan Bilir 21243510083
#include<iostream>
#include<fstream>
using namespace std;
class Date{
    public:
        int day, year;
        string month;
        Date(int d, string m, int y) : day(d), month(m), year(y) {}
};

class Player{
    private:
        string first, last;
        Date birthdate;
    public:
        Player(string f, string l, int d, string m, int y) : first(f), last(l), birthdate(d, m, y) {}
        void setMonth(string m) {
            birthdate.month = m;
        }
        void printInfo(ostream &a) {
            a << first << " " << last << " -- " << birthdate.month << " " << birthdate.day << ", " << birthdate.year << endl;
        }
        int getDay() {
            return birthdate.day;
        }
        int getYear() {
            return birthdate.year;
        }
};

int main(){
    ifstream inpfile("input.txt");
    string first, last, month;
    int day, year;
    bool correctSuccess;
    if(!inpfile.is_open()) {
        cout << "File not found.\n";
    }
    else {
        ofstream outfile("output.txt", ios::trunc);
        while(!inpfile.eof()) {
            try {
                inpfile >> first >> last >> day >> month >> year;

                if(month != "January" && month != "February" && month != "March" && month != "April" && month != "May" && month != "June" && month != "July" && month != "August" && month != "September" && month != "October" && month != "November" && month != "December") {
                    cout << "Incorrectly inputted month: " << month << " is corrected to ";
                    throw month;
                }

                outfile << first << " " << last << " " << day << " " << month << " " << year << endl;
            }

            catch (string mo) {
                Player a(first, last, day, month, year);
                correctSuccess = true;
                if(mo.substr(0, 3) == "Jan") 
                    month = "January";
                else if(mo.substr(0, 3) == "Feb") 
                    month = "February";
                else if(mo.substr(0, 3) == "Mar") 
                    month = "March";
                else if(mo.substr(0, 3) == "Apr") 
                    month = "April";
                else if(mo.substr(0, 3) == "May") 
                    month = "May";
                else if(mo.substr(0, 3) == "Jun") 
                    month = "June";
                else if(mo.substr(0, 3) == "Jul") 
                    month = "July";
                else if(mo.substr(0, 3) == "Aug") 
                    month = "August";
                else if(mo.substr(0, 3) == "Sep") 
                    month = "September";
                else if(mo.substr(0, 3) == "Oct") 
                    month = "October";
                else if(mo.substr(0, 3) == "Nov") 
                    month = "November";
                else if(mo.substr(0, 3) == "Dec") 
                    month = "December";
                else
                    correctSuccess = false;

                if (correctSuccess){
                    a.setMonth(month);
                    cout << month << endl; 
                    a.printInfo(outfile);
                }
            }
        }
        outfile.close();
    }
    inpfile.close();
    return 0;
}
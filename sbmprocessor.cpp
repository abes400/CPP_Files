#include<iostream>
#include<fstream>
using namespace std;
void view(string filename){
    cout << endl << endl;
    int width, repeat, pixel = 1; // 0: white, 1: black;
    ifstream inpfile(filename);
    inpfile >> width;
    int x = 0;
    while(!inpfile.eof()){
        inpfile >> repeat;
        for(int i = 1; i <= repeat; i++ ){
            if(x == width){
                cout << endl;
                x = 0;
            } 
            if(pixel == -1) cout << " "; else cout << "■";
            x++;
        }
        pixel *= -1;
    }
    inpfile.close();
    cout << endl << endl;
}

int main(){
    view("mail.sbm");
}

//    a
#include <iostream>
std::string fancy[] = {"Manufacturer: ", "Model: ", "Year: ", "CPU: ", "GPU: ", "RAM(GB): ", "Storage(GB): "};
class Computer{
    /*
    Infostr: 
    0: manufacturer 
    1: model     
    2: year 
    3: cpu 
    4: gpu   
    5: ram
    6: storage
    */
    public:
        std::string infostr[7];
    
        void newcmp(std::string instr[]){
            for(int i = 0; i < 7; i++){
                infostr[i] = instr[i];
            }
        }
    
        void showInfo(){
            std::cout << std::endl;
            for(int i = 0; i < 7; i++){
                std::cout << fancy[i] << infostr[i] << std::endl;
            }
            std::cout << std::endl;
        }
};

int main(){
    using namespace std;
    int size = 0, choice;
    Computer arr[10];
    
    while(true){
        cout << "1: New computer\n";
        cout << "2: Show computers\n";
        cout << "3: Show ALL computers\n";
        cout << "Your command: ";
        
        cin >> choice;
        
        if(choice == 0) break;
        
        if(choice == 1){
            cout << endl;
            for(int i = 0; i < 7; i++){
                cout << fancy[i];
                cin >> arr[size].infostr[i];
            }
            size++;
            cout << endl;
        } else if (choice == 2){
            cout << "Enter num: ";
            cin >> choice;
            arr[choice].showInfo();
        } else if(choice == 3){
            for(int i = 0; i < size; i++){
                arr[i].showInfo();
            }
        }
    }
    cout << "\nProgram ended.\n";
    return 0;
}
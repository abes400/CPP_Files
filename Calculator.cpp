#include<iostream>

int calc(){
    double num1, num2;
    char opr;
    
    std::cout << "Enter your operation: ";
    std::cin >> num1 >> opr >> num2;
    
    switch(opr){
        case '+': case 'a': case 'A': case '1':
        opr = '1';
        num1 += num2;
        break;
        
        case '-': case 's': case 'S': case '2':
        opr = '2';
        num1 -= num2;
        break;
        
        case '*': case 'm': case 'M': case '3':
        opr = '3';
        num1 *= num2;
        break;
        
        case '/': case 'd': case 'D': case '4':
        opr = '4';
        if(num2 == 0.0){
            std::cout << "Cannot divide by zero." << std::endl;
        } else {
            num1 /= num2;
        }
        break;
        
        case '0':
        return 0;
        
        default:
        std::cout << "Invalid operation." << std::endl;
        break;
    }
    
    if (!(opr == '4' && num2 == 0.0)){
        std::cout << "= " << num1 << std::endl;
    }
    
    return 1;
    
}

int main(){
    int check;
    
    using namespace std;
    
    cout << "SIGN \t LTR \t # \t OPERATION \n" << endl;
    cout << "+ \t A \t 1 \t Addition" << endl;
    cout << "+ \t A \t 1 \t Addition" << endl;
    cout << "- \t S \t 2 \t Subtraction" << endl;
    cout << "* \t M \t 3 \t Multiplication" << endl;
    cout << "/ \t D \t 4 \t Division \n" << endl;
    
    do{
        check = calc();
    } while (check != 0);
    
    return 0;
}

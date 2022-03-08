
//
//      This program is not made to be pratical or efficient, I'm learning C++ with my best :)
//

using namespace std; 
#include <iostream>
#include <cstring>
#include <string>

bool valid;
float value2;
float value1;
float outputValue;

string inputString = "";

// Operations: functions
float multiply(float value, float value2);
float divide(float value, float value2);
float add(float value, float value2);
float subtract(float value, float value2);

// function: check the first character is lower-case, fix it otherwise;
//           must have a value equal to one of the operations;
string validateOperation();


int main(){

    std::cout << "Welcome to my Calculator App: " << endl;
    std::cout << "What kind of operation would you like to do?: " << endl;
    std::cout << "multiply" << endl << "divide" << endl << "add" << endl << "subtract" << endl << endl;

    inputString = validateOperation();

    std::cout << "You have selected: " << inputString << endl << endl;
    std::cout << "Enter your first value: ";
    std::cin >> value1;
    std::cout << "Enter your second value: ";
    std::cin >> value2;


    switch(inputString[0]){
        case 'm':
            outputValue = multiply(value1, value2);
            break;
        case 'd':
            outputValue = divide(value1, value2);
            break;
        case 'a':
            outputValue = add(value1, value2);
            break;
        case 's':
            outputValue = subtract(value1, value2);
            break;
    }
    
    std::cout << endl << "Result: " << outputValue << endl;
}

string processedString;
int asciiValue;

string validateOperation(){

    valid = false;

    while (!valid)
    {
        std::cin >> inputString;
        asciiValue = int(inputString[0]);

        // decapitlizing it this string, ignore if not capital
        if(asciiValue >= 65 && asciiValue <= 90){
            asciiValue += 32;
            inputString = char(asciiValue) + inputString.substr(1);
        }

        valid = true;
        // This method doesn't work if I want to have more than one operator, such as Mod conflicts Multiply
        switch (inputString[0])
        {
        case 's':
            processedString = "subtract";
            break;
        case 'a':
            processedString = "add";
            break;
        case 'd':
            processedString = "divide";
            break;
        case 'm':
            processedString = "multiply";
            break;
        default:
            valid = false;
            break;
        }
        
    }

    return processedString;
}

float multiply(float value, float value2){

    return value * value2;

}
float divide(float value, float value2){

    return value / value2;

}
float add(float value, float value2){

    return value + value2;

}
float subtract(float value, float value2){

    return value - value2;

}
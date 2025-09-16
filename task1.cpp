#include <iostream>
#include <limits>
#include <cmath>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    double x;
    bool input = false;
    string inputStr;
    char symb = '.';
    while (!input) {
        cout << "Введите число x: " << endl;
        cin >> inputStr;
        
        replace(inputStr.begin(), inputStr.end(), ',', '.');
        
        try {
            size_t pos;
            x = stod(inputStr, &pos);

            if(*inputStr.begin() == symb){
                cerr << "Ошибка! Нельзя начинать ввод числа с точки или запятой" << endl;
            }
            else if (pos == inputStr.length()) {
                input = true;
            } else{
                cerr << "Ошибка! Вводите только число без дополнительных символов" << endl;
            }
            
        } catch (const exception& e) {
            cerr << "Ошибка! Введите корректное число" << endl;
        }
        
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    int y;
    bool input_second;
    string choice_function;
    double function;
    double answer;
    cout << "Выберите функцию:\nвведите 1 для x^2\nвведите 2 для e^x \nвведите 3 для sin x\n";

    while (!input_second) {
        cin >> choice_function;
        replace(choice_function.begin(), choice_function.end(), ',', '.');
        try{
        size_t pos_for_second;
        y = stod(choice_function, &pos_for_second);
        
        if(*choice_function.begin() == symb){
                cerr << "Ошибка! Нельзя начинать ввод числа с точки или запятой" << endl;
            }
        else if(pos_for_second == choice_function.length() &&  y == 1 || y == 2 || y == 3){
            input_second = true;
        }
        else{
            cout << "Ошибка! Вы ввели не число 1,2 или 3"<< endl;
        }
        }
        catch(const exception& e){
        cerr << "Ошибка! Введите корректное число"<< endl;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    switch (y) {
        case 1:
            function = pow(x, 2);
            break;
        case 2:
            function = exp(x); 
            break;
        case 3:
            function = sin(x);
            break;
    }
    
    if (x > 0) {
        answer = sin(x) * pow(1 + abs(pow(function, 4)), -1);
        cout << fixed << setprecision(6) << "Answer = " << answer;
    } else {
        cout << fixed << setprecision(6) << "Answer = " << pow(cos(x), 2.0/3.0);
    }
  
    return 0;
}
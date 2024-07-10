#include <iostream>
using namespace std;

int main() {
    double num1, num2, result;
    int op;

    do {
        cout << "Enter first number: ";
        cin >> num1;

        cout << "Enter second number: ";
        cin >> num2;

        cout << "Choose an operation:\n";
        cout << "1. ADD (+)\n";
        cout << "2. SUB (-)\n";
        cout << "3. MUL (*)\n";
        cout << "4. DIV (/)\n";
        cout << "5. EXIT....\n";
        cin >> op;

        switch (op) {
            case 1:
                result = num1 + num2;
                cout << "Result: " << num1 << " + " << num2 << " = " << result<<"\n" << endl;
                break;
            case 2:
                result = num1 - num2;
                cout << "Result: " << num1 << " - " << num2 << " = " << result<<"\n" << endl;
                break;
            case 3:
                result = num1 * num2;
                cout << "Result: " << num1 << " * " << num2 << " = " << result<<"\n" << endl;
                break;
            case 4:
                if (num2 == 0) {
                    cout << "Error! Division by zero is not allowed." << endl;
                } else {
                    result = num1 / num2;
                    cout << "Result: " << num1 << " / " << num2 << " = " << result<<"\n" << endl;
                }
                break;
       }
    } while (op != 5);

    cout << "Thank you for using the calculator." << endl;

    return 0;
}


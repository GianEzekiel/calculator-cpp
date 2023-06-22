#include <iostream>
#include <string>
#include <conio.h>
#include <limits> // Include the <limits> header for numeric_limits

using namespace std;
float ans;

struct logs {
    int n1;
    int n2;
    char op;
    float result;
};

bool isAnInteger(int x, int y);
void solve(int x, int y, char operation, string* equation, int size, float& ans);
void handleInvalidInput();
void handleInvalidIntegerInput();

int main() {
    int num1, num2, size = 0;
    char operation, choice, choice1;
    string* equation = new string[100];
    logs l[4];

    do {
        system("cls");
        cout << "\n\t+++CALCULATOR+++" << endl << endl;
        cout << "Enter the equation: ";

        // Validate num1 input
        while (!(cin >> num1)) {
            handleInvalidIntegerInput();
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cin >> operation;

        // Validate num2 input
        while (!(cin >> num2)) {
            handleInvalidIntegerInput();
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (isAnInteger(num1, num2)) {
            solve(num1, num2, operation, equation + size, size, ans);
            l[size].n1 = num1;
            l[size].n2 = num2;
            l[size].op = operation;
            l[size].result = ans;
            size++;
        } else {
            handleInvalidInput();
            continue;
        }

        cout << endl;
        cout << "\nCONTINUE?[Y/N]: ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    cout << endl;
    cout << "Check Logs?[Y/N]: ";
    cin >> choice1;
    if (choice1 == 'Y' || choice1 == 'y') {
        cout << "\nLogs: " << endl;
        for (int i = 0; i < size; i++) {
            cout << i + 1 << ": " << l[i].n1 << " " << l[i].op << " " << l[i].n2 << " = " << l[i].result << "   [ " << &equation[i] << " ]" << endl;
        }
    }

    delete[] equation; // Free the dynamically allocated memory

    getch();
    return 0;
}

bool isAnInteger(int x, int y) {
    return (cin.good() && cin.peek() == '\n');
}

void solve(int x, int y, char operation, string* equation, int size, float& ans) {
    switch (operation) {
        case '+':
            ans = x + y;
            cout << "Result: " << x << " " << operation << " " << y << " = " << ans;
            *equation = to_string(x) + " + " + to_string(y) + " = " + to_string(ans);
            break;
        case '-':
            ans = x - y;
            cout << "Result: " << x << " " << operation << " " << y << " = " << ans;
            *equation = to_string(x) + " - " + to_string(y) + " = " + to_string(ans);
            break;
        case '*':
            ans = x * y;
            cout << "Result: " << x << " " << operation << " " << y << " = " << ans;
            *equation = to_string(x) + " * " + to_string(y) + " = " + to_string(ans);
            break;
        case '/':
            ans = x / y;
            if (y != 0) {
                cout << "Result: " << x << " " << operation << " " << y << " = " << ans;
                *equation = to_string(x) + " / " + to_string(y) + " = " + to_string(ans);
            } else {
                cout << "Undefined! Please Try again";
            }
            break;
        default:
            cout << "Invalid";
            break;
    }
}

void handleInvalidInput() {
    cout << "Invalid input! Please enter a valid equation." << endl;
    cin.clear();               // Clear the error state
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore the invalid input
}

void handleInvalidIntegerInput() {
    cout << "Invalid input! Please enter an integer." << endl;
}

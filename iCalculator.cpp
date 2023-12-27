#include <iostream>
#include <cmath>
#include <typeinfo>
using namespace std;

bool input(int &variable) {
    cin >> variable;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Недопустимое действие" << endl;
        return false;
    }
    return true;
}

bool input(float &variable) {
    cin >> variable;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Недопустимое действие" << endl;
        return false;
    }
    return true;
}
bool input(char &variable) {
    cin >> variable;
    if (variable=='+' or variable=='-' or variable=='*' or variable=='/' or variable=='^') {
        return true;
    }else{
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Недопустимое действие" << endl;
        return false;
    }

}
bool input(short &variable) {
    cin >> variable;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Недопустимое действие" << endl;
        return false;
    }
    return true;
}

int main() {
    while (true) {
        short regim;
        cout << "Выберите режим работы (0 - работа с числами; 1 - работа с матрицами)" << endl;
        if(!input(regim)) continue;

        if (regim == 0) {
            float a, b;
            char mathematical_operation;
            cout << "Введите первое число" << endl;
            if(!input(a)) continue;

            cout << "Введите действие" << endl;
            if(!input(mathematical_operation)) continue;

            cout << "Введите второе число" << endl;
            if(!input(b)) continue;

            if (mathematical_operation == '+')
                cout << "a + b = " << a + b << endl;
            else if (mathematical_operation == '-')
                cout << "a - b = " << a - b << endl;
            else if (mathematical_operation == '*')
                cout << "a * b = " << a * b << endl;
            else if (mathematical_operation == '/')
                cout << "a / b = " << a / b << endl;
            else if (mathematical_operation == '^')
                cout << "a^b = " << pow(a, b) << endl;


        } else if (regim == 1) {
            int i, j, n, m, a[10][10], b[10][10], c[10][10];
            int flag = 0;
            char matrix_operation;
            cout << "Введите размер матрицы" << endl;
            input(m);
            input(n);
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    flag++;
                    cout << "Введите значение номер " << flag << endl;
                    cin >> a[i][j];
                }
            }

            cout << "Введите действие" << endl;
            input( matrix_operation);
            flag = 0;
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    flag++;
                    cout << "Введите значение номер " << flag << endl;
                    cin >> b[i][j];
                }
            }

            if (matrix_operation == '+') {
                for (i = 0; i < n; i++) {
                    for (j = 0; j < m; j++) {
                        c[i][j] = a[i][j] + b[i][j];
                    }
                }
            } else if (matrix_operation == '-') {
                for (i = 0; i < n; i++) {
                    for (j = 0; j < m; j++) {
                        c[i][j] = a[i][j] - b[i][j];
                    }
                }
            }else {
                cout << "Недопустимое действие" << endl << endl;
            }
            cout << endl;
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    //flag++;
                    cout << c[i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
    }

    return 0;

}

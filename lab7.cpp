#include <iostream>
using namespace std;

void inputMatrix(double matrix[][100], int M, int N) {
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }
}

void outputMatrix(double matrix[][100], int M, int N) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }
}

void calculate(double matrix[][100], int M, int N) {
    cout << "Average of odd-numbered rows:\n";
    
    for (int i = 0; i < M; i += 2) {
        double sum = 0;
        for (int j = 0; j < N; j++) {
            sum += matrix[i][j];
        }
        cout << "Row " << i + 1 << ": " << sum / N << endl;
    }
}

void swapHalves(double matrix[][100], int M, int N) {
    for (int i = 0; i < M / 2; i++) {
        for (int j = 0; j < N; j++) {
            double temp = matrix[i][j];
            matrix[i][j] = matrix[i + M / 2][j];
            matrix[i + M / 2][j] = temp;
        }
    }
}

void task1() {
    int M, N;
    double matrix[100][100];

    cout << "Enter number of rows (M): ";
    cin >> M;
    cout << "Enter number of columns (N): ";
    cin >> N;

    inputMatrix(matrix, M, N);
    calculate(matrix, M, N);
}

void task2() {
    int M, N;
    double matrix[100][100];

    cout << "Enter number of rows (M): ";
    cin >> M;

    if (M % 2 != 0) {
        cout << "Error! M must be even number.\n";
        return;
    }

    cout << "Enter number of columns (N): ";
    cin >> N;

    inputMatrix(matrix, M, N);
    swapHalves(matrix, M, N);

    cout << "\nMatrix after swapping halves:\n";
    outputMatrix(matrix, M, N);
}

int menu() {
    int choice;
    cout << "\nMENU\n";
    cout << "1 - Task 1 (Matrix21)\n";
    cout << "2 - Task 2 (Matrix55)\n";
    cout << "0 - Exit\n";

    cin >> choice;
    return choice;
}

void runProgram() {
    while (true) {
        int choice = menu();

        if (!cin) {
            cout << "Input error! Program terminated.\n";
            break;
        }

        switch (choice) {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 0:
                cout << "Program finished\n";
                return;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
int main() {
    runProgram();
    return 0;
}
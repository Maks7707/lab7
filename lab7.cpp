#include <iostream>
using namespace std;

int main() {
    int choice;
    while(true) {
        cout << "MENU\n";
        cout << "1 - Task 1(Matrix21)\n";
        cout << "2 - Task 2(Matrix55)\n";
        cout << "0 - Exit\n";
        
         if (!(cin >> choice)) {
            cout << "Input error! Program terminated.\n";
            break;
        }
        
        if (choice == 0) {
            cout << "Program finished\n";
            break;
        }
        
        if (choice == 1) {
            
            int M, N;
            
            cout << "Enter numbers of rows (M):\n";
            cin >> M;
            
            cout << "Enter numbers of columns (N):\n";
            cin >> N;
            
            double matrix[100][100];
            
            cout << "Enter matrix elements:\n";
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {
                    cin >> matrix[i][j];
                }
            }
            
            cout << "Average of odd-numbered rows:\n";
            
            for(int i = 0; i < M; i += 2) {
                double sum = 0;
                
                for (int j = 0; j < N; j++) {
                    sum += matrix[i][j];
                }
                
                cout << "Row" << i + 1 << ":" << sum / N << endl;
            }
        }
        
        else if (choice == 2) {
            
            int M, N;
            
            cout << "Enter numbers of rows (M):";
            cin >> M;
            
            cout << "Enter numbers of columns (N):";
            cin >> N;
            
            if (M % 2 != 0) {
                cout << "Error!(M must be even number)\n";
                continue;
            }
            
            double matrix [100][100];
            
            cout << "Enter matrix elements:\n";
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {
                    cin >> matrix[i][j];
                }
            }
            
            for (int i = 0; i < M / 2; i++) {
                for (int j = 0; j < N; j++) {

                    double temp = matrix[i][j];
                    matrix[i][j] = matrix[i + M / 2][j];
                    matrix[i + M / 2][j] = temp;
                }
            }

            cout << "\nMatrix after swapping halves:\n";

            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {
                    cout << matrix[i][j] << "\t";
                }
                cout << endl;
            }
        }

        else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
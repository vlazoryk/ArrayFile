#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Enter the size of the array: ";
    cin >> N;

    if (N <= 0) {
        cout << "Invalid array size!" << endl;
        return 1;
    }

    int* A = new int[N];  // Динамічне виділення пам'яті для масиву

    cout << "Enter " << N << " elements: ";
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int zeroCount = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] == 0) {
            zeroCount++;
        }

        cout<<" Num element 0"<<zeroCount<<endl;
        if(A!=nullptr) delete [] A;

        main1();
    }



#include <iostream>
//#include <limits>
    using namespace std;

    int main1() {
        int N, T;
        cout << "Enter the size of the array: ";
        cin >> N;
// ???
        int* A = new int[N];  // Dynamic memory allocation for the array

        cout << "Enter " << N << " elements: ";
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        cout << "Enter the value of T: ";
        cin >> T;

        int indexT = -1;
        for (int i = 0; i < N; i++) {
            if (A[i] == T) {
                indexT = i;
                break;
            }
        }

        if (indexT == -1) {
            cout << "Element T not found in the array." << endl;
        }
        else {
            int maxNeg = numeric_limits<int>::min();
            int lastMaxIndex = -1;

            for (int i = indexT + 1; i < N; i++) {
                if (A[i] < 0 && A[i] >= maxNeg) {
                    maxNeg = A[i];
                    lastMaxIndex = i;
                }
            }

            if (lastMaxIndex == -1) {
                cout << "No negative elements found after T." << endl;
            }
            else {
                cout << "Index of last maximum negative element after T: " << lastMaxIndex << endl;
            }
        }

        delete[] A;  // Free allocated memory
        return 0;
    }

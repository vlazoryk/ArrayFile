// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

// ArrayFile.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <ios>
#include <vector>

#include <time.h>

using namespace std;

typedef double* pDouble;

const int MAX_SIZE = 560;

/*
*   ConsoleInputArrayDouble
*
*/
int ConsoleInputSizeArray(const int sizeMax)
{
    int size = 0;
    do {
        cout << " Input size Array ( 0< 1 < " << sizeMax << " ) ";
        cin >> size;
    } while (size <= 0 || size >= sizeMax);
    return size;
}
/*
*   ConsoleInputArrayDouble
*
*/
int ConsoleInputArray(int sizeMax, double A[])
{
    int size = ConsoleInputSizeArray(sizeMax);
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> A[i];
    }
    return size;
}

/*
*   RndInputArrayDouble
*
*/
int RndInputArray(int sizeMax, double A[])
{
    int size = ConsoleInputSizeArray(sizeMax);
    int r1 = 0, r2 = 0;
    srand(size);

    for (int i = 0; i < size; i++) {
<<<<<<< Updated upstream
        if (i < size/2) A[i] = rand() % 100;
=======
        if (i < size / 2) A[i] = rand() % 100;
>>>>>>> Stashed changes
        else {
            r1 = rand() % 100;
            r2 = rand() % 100;
            A[i] = r1 - r2;

        }
<<<<<<< Updated upstream
      /* r1 = rand();
        r2 = rand();
        A[i] = 100.0 * r1;
        A[i] = A[i] / (1.0 + r2);
        cout << A[i] << "   ";*/
=======
        /* r1 = rand();
          r2 = rand();
          A[i] = 100.0 * r1;
          A[i] = A[i] / (1.0 + r2);
          cout << A[i] << "   ";*/
>>>>>>> Stashed changes
    }
    return size;
}

int ConsoleInputDynamicArrayNew(int sizeMax, pDouble& pA)
{
    int size = ConsoleInputSizeArray(sizeMax);
    pA = new double[size];
    if (pA == nullptr) { return 0; }
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> pA[i];
    }
    return size;
}

int ConsoleInputDynamicArray_calloc(int sizeMax, pDouble& pA)
{
    int size = ConsoleInputSizeArray(sizeMax);
    pA = (double*)calloc(size, sizeof(double));      // pA = (double*)malloc(size * sizeof(double)); 
    if (pA == nullptr) { return 0; }
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> pA[i];
    }
    return size;
}

void ConsoleInputVector(int sizeMax, vector<double>& A)
{
    int size = ConsoleInputSizeArray(sizeMax);
    double d;
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> d; A.push_back(d);
    }
    return;
}


/*
*  WriteArrayTextFile
*
*/

void WriteArrayTextFile(int n, double* arr, const char* fileName)
{
    ofstream fout(fileName);
    if (fout.fail()) return;
    fout << n << endl;
    for (int i = 0; i < n; i++)
        fout << arr[i] << "   ";
    fout.close(); //
}
/*
*  ReadArrayTextFile
*
*/


int ReadArrayTextFile(int n, double* arr, const char* fileName)
{
    int size;
    ifstream fin(fileName);
    if (fin.fail()) return 0;
    fin >> size;
    if (size <= 0) return 0;
    if (size > n) size = n;
    for (int i = 0; i < n; i++)
<<<<<<< Updated upstream
       fin >> arr[i];
=======
        fin >> arr[i];
>>>>>>> Stashed changes
    fin.close();
    return size;

}



void WriteArrayBinFile(int n, double* arr, const char* fileName)
{
    //ios_base
    ofstream bfout(fileName, ios_base::binary);
    if (bfout.fail()) return;
    bfout.write((const char*)&n, sizeof(int));
    std::streamsize  cn = static_cast<std::streamsize>(n) * sizeof(double);
    bfout.write((const char*)arr, cn);
    bfout.close();
}

int ReadArrayBinFile(int n, double* arr, const char* fileName)
{
    int size = 0;
    ifstream bfin(fileName, ios_base::binary);
    if (bfin.fail()) return 0;
    bfin.read((char*)&size, sizeof(int));
    if (size <= 0) return 0;
    if (size > n) size = n;
    bfin.read((char*)arr, static_cast<std::streamsize>(size) * sizeof(double));
    bfin.close();
    // ssdhs
    return size;
}

void ShowMainMenu()
{
    cout << "    Main Menu  \n";
    cout << "    1.  Завдання 1 \n";
    cout << "    2.  Завдання 2 \n";
    cout << "    3.  Завдання 3 \n";
    cout << "    4.  cls (очищення екрану) \n";
    cout << "    5.  Зчитування в контейнер \n";
    cout << "    0.  Вихiд \n";
<<<<<<< Updated upstream
  }
=======
}
>>>>>>> Stashed changes

void MenuTask()
{
    cout << "    Генерацiя масиву \n";
    cout << "    1.  a (Створення масиву з консолi) \n";
    cout << "    2.  b (Створення масиву рандомно) \n";
    cout << "    0.  Вихiд \n";
    getchar();
}

void MenuInput()
{
    cout << "     Menu Input \n";
    cout << "    1.  Console all \n";
    cout << "    2.  Console - size, array - random \n";
    cout << "    3.  File 1.txt \n";
    cout << "    4.  bb    \n";
    cout << "    5.  Exit \n";
    getchar();
}


/*
* Задано одновимірний масив А розміру 2N.
* Побудувати два масиви В і С розміру N,
* включивши  у масив В елементи масиву А з парними індексами,
* а у С - з непарними.
*****************
*  A - in
*  B, C - out
*/
void  TestVariant(int N, double* A, double* B, double* C) {
    for (int i = 0; i < N; i++) {
        B[i] = A[2 * i];
        C[i] = A[2 * i + 1];
    }
}
/*
*  Task  Var
*
*
*/
void TaskV()
{
    char ch = '5';
    do {
        system("cls");
        MenuTask();
        ch = getchar();
        getchar();
        switch (ch) {
        case '1': cout << " 1 "; break;
        case '2': cout << " 2 "; break;
            //
        case '5': return;
        }
        cout << " Press any key and enter\n";
        ch = getchar();
    } while (ch != 27);

}

void ArrayLocal()
{
    double A[1000], B[500], C[500];
    int n;
    char ch = '5';
    do {
        system("cls");
        MenuTask();
        ch = getchar();
        getchar();
        switch (ch) {
        case '1': cout << " 1 "; break;
        case '2': cout << " 2 "; break;
            //
        case '5': return;
        }
        cout << " Press any key and enter\n";
        ch = getchar();
    } while (ch != 27);

}

void ArthurTask1() {
<<<<<<< Updated upstream
    pDouble B; 
    int m;
    double sm=0, sp=0, smp=0;
    B = new double[MAX_SIZE];
    if (B == nullptr) { return; }
    m = ReadArrayTextFile(MAX_SIZE, B, "task.txt");
    cout << " \n m= " << m << endl;
    for (int i = 0; i < m; i++) {
        cout << B[i] << "   ";
        if (B[i] < 0) sm += B[i];
        else sp += B[i];
        smp = sp - sm;
    }
    cout << "\n рiзниця = " << smp << "\n\n";
    
    ofstream fout("task1out.txt");
    if (fout.fail()) return;
    fout << smp << endl;
    fout.close();
    

}

void ArthurTask2() {
    pDouble B;
    int m, i;
    int k1 = 0, max = 0;
    cout << "\n Введiть число кратностi: ";
    cin >> k1;
    B = new double[MAX_SIZE];
    if (B == nullptr) { return; }
    m = ReadArrayTextFile(MAX_SIZE, B, "task.txt");
    cout << " \n m= " << m << endl;
    for (i = 0; i < m; i++) {
        cout << B[i] << "   ";
    }
    i = 0;
    do {
        if ((int)B[i] % (int)k1 == 0){
            if(max < B[i]) max = B[i];
        }
        i++;
    } while (B[i] >= 0 && i<m);
    cout << "\nmax= " << max << endl;

    ofstream fout("task2out.txt");
    if (fout.fail()) return;
    fout << max << endl;
    fout.close();


}

void ArthurTask3() {
    pDouble B;
    int C[400];
    int m, n, i, j, l = 0, y;
    B = new double[MAX_SIZE];
    if (B == nullptr) { return; }
    m = ReadArrayTextFile(MAX_SIZE, B, "task.txt");
    cout << " \n m= " << m << endl;
    for (i = 0; i < m; i++) {
        cout << B[i] << "   ";
    }
    cout << "\n\n";
    for (i = 0; i < m; i++) {
        for (j = i+1; j < m; j++) {
            if (B[i] == B[j]) {
                y = 0;
                for (n = 0; n < l; n++) {
                    if (C[n] == B[j]) y = 1;

                }
                if (y == 0) {
                    C[l] = B[i];
                    l += 1; break;
                }
            }
            else;
        }
    }
    for (i = 0; i < l; i++) {
        cout << C[i] << "   ";
        if ((i+1) % 7 == 0) {
            cout << endl;
        }
    }
    cout << endl << endl;
    ofstream fout("task3out.txt");
    if (fout.fail()) return;
    for (i = 0; i < l; i++) {
        fout << C[i] << "   ";
        if ((i + 1) % 7 == 0) {
            fout << endl;
        }
    }
    fout.close();

}




int main(){
    int size;
    double d;
    vector <double> A;
    ifstream fin;
    int m, t, s;
    double B[MAX_SIZE];
    setlocale(LC_ALL, "RU");
    
    do {
        ShowMainMenu();
        cin >> m;
        if (m != 4 && m != 0 && m != 5) {
            MenuTask();
            cin >> t;
            if (t == 1) {
                s = ConsoleInputArray(MAX_SIZE, B);
                WriteArrayTextFile(s, B, "task.txt");
            }
            if (t == 2) {
                s = RndInputArray(MAX_SIZE, B);
                // WriteArrayBinFile(s, B, "task.txt");
                WriteArrayTextFile(s, B, "task.txt");
            }
        }
        switch (m)
        {
        case 1:
            ArthurTask1();
            break;
        case 2:
            ArthurTask2();
            break;
        case 3:
            ArthurTask3();
            break;
        case 4:
            system("cls");
            break;
        case 5:
            
            fin.open("task.txt");
            if (fin.fail()) break;
            fin >> size;
            if (size <= 0) break;
            for (int i = 0; i < size; i++) {
                fin >> d;
                A.push_back(d);
            }
            fin.close();

            for (int i = 0; i < A.size(); i++) {
                cout << " " << A[i] << " ";
            }
            cout << "\n\n";
            break;
        default:
            break;

        }
    } while (m!=0);


/*
    double A[MAX_SIZE], B[MAX_SIZE],C[MAX_SIZE];
    int n,m;
    n = RndInputArray(MAX_SIZE, A);
    WriteArrayTextFile(n, A, "1.txt");
    m = ReadArrayTextFile(MAX_SIZE, B, "1.txt");
=======
    pDouble B;
    int m;
    double sm = 0, sp = 0, smp = 0;
    B = new double[MAX_SIZE];
    if (B == nullptr) { return; }
    m = ReadArrayTextFile(MAX_SIZE, B, "task.txt");
>>>>>>> Stashed changes
    cout << " \n m= " << m << endl;
    for (int i = 0; i < m; i++) {
        cout << B[i] << "   ";
        if (B[i] < 0) sm += B[i];
        else sp += B[i];
        smp = sp - sm;
    }
<<<<<<< Updated upstream
    */
   // TaskV();
=======
    cout << "\n рiзниця = " << smp << "\n\n";

    ofstream fout("task1out.txt");
    if (fout.fail()) return;
    fout << smp << endl;
    fout.close();


}

void ArthurTask2() {
    pDouble B;
    int m, i;
    int k1 = 0, max = 0;
    cout << "\n Введiть число кратностi: ";
    cin >> k1;
    B = new double[MAX_SIZE];
    if (B == nullptr) { return; }
    m = ReadArrayTextFile(MAX_SIZE, B, "task.txt");
    cout << " \n m= " << m << endl;
    for (i = 0; i < m; i++) {
        cout << B[i] << "   ";
    }
    i = 0;
    do {
        if ((int)B[i] % (int)k1 == 0) {
            if (max < B[i]) max = B[i];
        }
        i++;
    } while (B[i] >= 0 && i < m);
    cout << "\nmax= " << max << endl;

    ofstream fout("task2out.txt");
    if (fout.fail()) return;
    fout << max << endl;
    fout.close();


}

void ArthurTask3() {
    pDouble B;
    int C[400];
    int m, n, i, j, l = 0, y;
    B = new double[MAX_SIZE];
    if (B == nullptr) { return; }
    m = ReadArrayTextFile(MAX_SIZE, B, "task.txt");
    cout << " \n m= " << m << endl;
    for (i = 0; i < m; i++) {
        cout << B[i] << "   ";
    }
    cout << "\n\n";
    for (i = 0; i < m; i++) {
        for (j = i + 1; j < m; j++) {
            if (B[i] == B[j]) {
                y = 0;
                for (n = 0; n < l; n++) {
                    if (C[n] == B[j]) y = 1;

                }
                if (y == 0) {
                    C[l] = B[i];
                    l += 1; break;
                }
            }
            else;
        }
    }
    for (i = 0; i < l; i++) {
        cout << C[i] << "   ";
        if ((i + 1) % 7 == 0) {
            cout << endl;
        }
    }
    cout << endl << endl;
    ofstream fout("task3out.txt");
    if (fout.fail()) return;
    for (i = 0; i < l; i++) {
        fout << C[i] << "   ";
        if ((i + 1) % 7 == 0) {
            fout << endl;
        }
    }
    fout.close();

}




int main() {
    int size;
    double d;
    vector <double> A;
    ifstream fin;
    int m, t, s;
    double B[MAX_SIZE];
    setlocale(LC_ALL, "RU");

    do {
        ShowMainMenu();
        cin >> m;
        if (m != 4 && m != 0 && m != 5) {
            MenuTask();
            cin >> t;
            if (t == 1) {
                s = ConsoleInputArray(MAX_SIZE, B);
                WriteArrayTextFile(s, B, "task.txt");
            }
            if (t == 2) {
                s = RndInputArray(MAX_SIZE, B);
                // WriteArrayBinFile(s, B, "task.txt");
                WriteArrayTextFile(s, B, "task.txt");
            }
        }
        switch (m)
        {
        case 1:
            ArthurTask1();
            break;
        case 2:
            ArthurTask2();
            break;
        case 3:
            ArthurTask3();
            break;
        case 4:
            system("cls");
            break;
        case 5:

            fin.open("task.txt");
            if (fin.fail()) break;
            fin >> size;
            if (size <= 0) break;
            for (int i = 0; i < size; i++) {
                fin >> d;
                A.push_back(d);
            }
            fin.close();

            for (int i = 0; i < A.size(); i++) {
                cout << " " << A[i] << " ";
            }
            cout << "\n\n";
            break;
        default:
            break;

        }
    } while (m != 0);


    /*
        double A[MAX_SIZE], B[MAX_SIZE],C[MAX_SIZE];
        int n,m;
        n = RndInputArray(MAX_SIZE, A);
        WriteArrayTextFile(n, A, "1.txt");
        m = ReadArrayTextFile(MAX_SIZE, B, "1.txt");
        cout << " \n m= " << m << endl;
        for (int i = 0; i < m; i++)
            cout << B[i] << "   ";
        WriteArrayBinFile(n, A, "1.bin");
        m = ReadArrayBinFile(MAX_SIZE, C, "1.bin");
        cout << " \n m= " << m << endl;
        for (int i = 0; i < m; i++)
            cout << C[i] << "   ";
        cout << "\n  Vector \n";
        vector<double> vA;
        ConsoleInputVector(MAX_SIZE, vA);
        for (auto v : vA) {
            cout << v << "   ";
        }
        */
        // TaskV();
>>>>>>> Stashed changes
    return 1;

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

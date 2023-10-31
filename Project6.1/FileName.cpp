#include <iostream>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
using namespace std;



const int ARRAY_SIZE = 23;
const int LOWER_BOUND = 4;
const int UPPER_BOUND = 68;

// Функція для створення та заповнення масиву випадковими числами
void createArray(int array[], int size, int lower, int upper) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % (upper - lower + 1) + lower;
    }
}

// Функція для обчислення кількості та суми елементів, які відповідають критерію
void SumArray(int array[], int size, int& count, int& sum) {
    count = 0;
    sum = 0;

    for (int i = 0; i < size; i++) {
        if (array[i] % 2 != 0 && array[i] % 13 != 0) {
            count++;
            sum += array[i];
        }
    }
}

// Функція для заміни елементів, які відповідають критерію, нулями
void ZeroFun(int array[], int size) {
    for (int i = 0; i < size; i++) {
        if (array[i] % 2 != 0 && array[i] % 13 != 0) {
            array[i] = 0;
        }
    }
}

// Функція для виведення масиву на екран
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << ' ';
    }
    cout << std::endl;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    srand(time(nullptr));

    int r[ARRAY_SIZE];

    createArray(r, ARRAY_SIZE, LOWER_BOUND, UPPER_BOUND);
    cout << "Згенерований масив: ";
    printArray(r, ARRAY_SIZE);

    int count, sum;
    SumArray(r, ARRAY_SIZE, count, sum);
    cout << "Кількість елементів, що задовольняють критерію: " << count << endl;
    cout << "Сума таких елементів: " << sum << endl;

    ZeroFun(r, ARRAY_SIZE);
    cout << "Модифікований масив: ";
    printArray(r, ARRAY_SIZE);

    return 0;
}


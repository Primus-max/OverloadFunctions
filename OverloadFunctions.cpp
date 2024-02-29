// Написать перегруженные функции и протестировать их в основной программе:
// Нахождения максимального значения в одномерном массиве;
// Нахождения максимального значения в двумерном массиве;
// Нахождения максимального значения двух целых;
// Нахождения максимального значения трёх целых;

#include <iostream>
#include <windows.h>
#include <random>
using namespace std;


/// <summary>
/// Заполнение массива рандомными значениями
/// </summary>
/// <param name="arr"></param>
/// <param name="size"></param>
void FillArray(int arr[], int size);

/// <summary>
/// Перегруженный метод заполнения двумерного массива
/// </summary>
/// <param name="arr"></param>
/// <param name="rows"></param>
/// <param name="cols"></param>
void FillArray(int arr[][20], int rows, int cols);

/// <summary>
/// Вывод массива на экран
/// </summary>
/// <param name="arr"></param>
/// <param name="size"></param>
void PrintArray(int arr[], int size);

/// <summary>
/// Перегруженный метод печати двумерного массива
/// </summary>
/// <param name="arr"></param>
/// <param name="rows"></param>
/// <param name="cols"></param>
void PrintArray(int arr[][20], int rows, int cols);

/// <summary>
/// Нахождение максимального значения в массиве
/// </summary>
/// <param name="arr"></param>
/// <param name="size"></param>
/// <returns></returns>
int FindMax(int arr[], int size);

/// <summary>
/// Нахождение максимального в двумерном массиве
/// </summary>
/// <param name="arr"></param>
/// <param name="rows"></param>
/// <param name="cols"></param>
/// <returns></returns>
int FindMax(int arr[][20], int rows, int cols);

/// <summary>
/// Нахождение максимального значения из двух целых
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
/// <returns></returns>
int FindMaxDigit(int, int);

/// <summary>
/// Нахождение максимального значения из трёх целых
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
/// <returns></returns>
int FindMaxDigit(int, int, int);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int size = 20;
    const int rows = 20;
    const int cols = 20;
    int A=0, B=0, C= 0;
    int Array[size];
    int TwoDimensionalArray[rows][cols];
    
    FillArray(Array, size);
    cout << "Заполненный одномерный массив : " << endl;
    PrintArray(Array, size);
    cout << "Максимальное значение в массиве : " << FindMax(Array, size) << endl;
    cout << "Заполненный двумерный массив : " << endl;
    FillArray(TwoDimensionalArray, rows, cols);
    PrintArray(TwoDimensionalArray, rows, cols);    
    cout << "Максимальное значение в двумерном в массиве : " << FindMax(TwoDimensionalArray, rows, cols) << endl;
    cout << endl;
    cout << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
    cout << "Для нахождения максимального из двух целых введите A и B :";
    cin >> A >> B;
    cout << endl;
    cout << "Максимально значение : " << FindMaxDigit(A, B) << endl;
    cout << endl;
    cout << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
    cout << "Для нахождения максимального из трёх целых введите A и B и С:";
    cin >> A >> B >> C;
    cout << "Максимально значение : " << FindMaxDigit(A, B, C) << endl;
}


void FillArray(int arr[], int size) {
    random_device random;
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = random() % (100 + 50) - 50;
    }
}


void FillArray(int arr[][20], int rows, int cols) {
    random_device random;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr[i][j] = random() % (100 + 50) - 50;
        }
    }
}


void PrintArray(int arr[], int size) {
    for (size_t i = 0; i < size; i++)
    {
        cout <<"[" << arr[i] << "]" << " ";
    }

    cout << endl;
}

void PrintArray(int arr[][20], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "[" << arr[i][j] << "] ";
        }
        cout << std::endl;
    }
}

int FindMax(int arr[], int size) {
    int maxVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int FindMax(int arr[][20], int rows, int cols) {
    int maxVal = arr[0][0];
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (arr[i][j] > maxVal) {
                maxVal = arr[i][j];
            }
        }
    }
    return maxVal;
}

int FindMaxDigit(int a, int b) {
    return (a > b) ? a : b;
}

int FindMaxDigit(int a, int b, int c) {
    return FindMaxDigit(FindMaxDigit(a, b), c);
}
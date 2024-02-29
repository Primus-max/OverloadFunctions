// OverloadFunctions.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

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

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int size = 20;
    const int rows = 20;
    const int cols = 20;
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
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
/// Вывод массива на экран
/// </summary>
/// <param name="arr"></param>
/// <param name="size"></param>
void PrintArray(int arr[], int size);

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
int FindMax(const int arr[][3], int rows, int cols);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int size = 20;
    int Array[size];
    
    FillArray(Array, size);
    cout << "Заполненный массив : " << endl;
    PrintArray(Array, size);
    cout << "Максимальное значение в массиве : " << FindMax(Array, size) << endl;
}


void FillArray(int arr[], int size) {
    random_device random;
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = random() % (100 + 50) - 50;
    }
}

void PrintArray(int arr[], int size) {
    for (size_t i = 0; i < size; i++)
    {
        cout <<"[" << arr[i] << "]" << " ";
    }

    cout << endl;
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
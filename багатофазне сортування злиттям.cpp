#include<iostream>  
#include<math.h>  
#include<stdlib.h>  
using namespace std;

void соеденить_массив(int a[], int first, int mid, int last, int temp[])
{
    int i = first, j = mid + 1;
    int m = mid, n = last;
    int k = 0;

    while (i <= m && j <= n)
    {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= m)
        temp[k++] = a[i++];

    while (j <= n)
        temp[k++] = a[j++];

    for (i = 0; i < k; i++)
        a[first + i] = temp[i];
}
void рекурсия(int a[], int first, int last, int temp[])
{
    if (first < last)
    {
        int mid = (first + last) / 2; // считаем индекс элемента посередине массива
        рекурсия(a, first, mid, temp);   // рекурсивно вызываем функцию  с ПЕРВОГО до ПОЛОВИНЫ
        рекурсия(a, mid + 1, last, temp); // рекурсивно вызываем функцию с ПОЛОВИНЫ до ПОСЛЕДНЕГО 
        соеденить_массив(a, first, mid, last, temp); // соединяем отсортированные половинки
    }
}
bool Основная_Функция(int a[], int n)
{
    int* p = new int[n]; // выделяем память под динамический массив
    if (p == NULL) // проверка удалось ли выделить память (n != 0)
        return false;
    рекурсия(a, 0, n - 1, p); // вызов рекурсивной функции
    delete[] p;  // удалем память
    return true;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    int i = 0, temp = 0; 
    const int ROW = 10;
    const int COL = 10;
    int a[ROW][COL] = {0}; // первоначальная матрица
    cout << "Первоначальная матрица" << endl; 
    for (i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++) {
            a[i][j] = rand() % 11; // заполняем ее случайными числами от 0 до 10
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n\n_______________\n\n";
    // решение
    for (i = 0; i < ROW; i++)// для каждого рядка матрицы
    {
        Основная_Функция(a[i], COL); // сортируем текущий рядок
    }

    cout << "Отсортированная матрица" << endl;
    for (i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
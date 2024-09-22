# Задание 1

___

Все сделано :ok_hand:
___

# Задание 2
___

![image](https://github.com/user-attachments/assets/dfb47084-2606-4b58-96d6-ea7ac04bcf04)


## Первая реализация

```C++
#include <fstream>

int main()
{
    //  чтение данных из файла
    int size1, size2, size3;
    std::ifstream fin("input.txt");
    fin >> size1;
    fin >> size2;
    fin >> size3;
    fin.close();
    
    //  конструирование непрерывного трехмерного массива с мультииндексами
    int*** p1 = new int** [size3];
    int** p2 = new int* [size3 * size2];
    int* p3 = new int [size3 * size2 * size1];
    
    for (int k = 0; k < size3; ++k)
    {
        p1[k] = &p2[k * size2];
        for (int j = 0; j < size2; ++j)
        {
            p1[k][j] = &p3[k * size2 * size1 + j * size1];
        }
    }
    
    //  инициализация
    for (int k = 0; k < size3; ++k)
    {
        for (int j = 0; j < size2; ++j)
        {
            for (int i = 0; i < size1; ++i)
            {
                p1[k][j][i] = 0;
            }
        }
    }
    
    //  освобождение памяти
    delete[] p1;
    delete[] p2;
    delete[] p3;
    
    return 0;
}
```

## Вторая реализация
### Ультро мега гарант того что память выделенна непрерывно

![ref](https://github.com/user-attachments/assets/1002e6f3-c876-4d1e-94ac-a694f433320f)


```C++
#include <fstream>

int main()
{
    //  проверка на то что указатель в два раза больше int
    if (sizeof(int*) != 2 * sizeof(int))
    {
        return 1;
    }
    
    //  чтение данных из файла
    int size1, size2, size3;
    std::ifstream fin("input.txt");
    fin >> size1;
    fin >> size2;
    fin >> size3;
    fin.close();
    
    
    //  конструирование непрерывного трехмерного массива с мультииндексами
    int* p = new int[size3 * 2 + size3 * size2 * 2 + size3 * size2 * size1];
    
    int*** p1 = new int** [size3];
    delete[] p1;
    
    p1 = (int***)p;
    
    for (int k = 0; k < size3; ++k)
    {
        int** p2 = new int* [size2];
        delete[] p2;
    
        p2 = (int**)&p[size3 * 2 + k * size2 * 2];
        p1[k] = p2;
    
        for (int j = 0; j < size2; ++j)
        {
            int* p3 = new int[size1];
            delete[] p3;
    
            p3 = (int*)&p[size3 * 2 + size3 * size2 * 2 + k * size2 * size1 + j * size1];
            p1[k][j] = p3;
        }
    }
    
    //  инициализация
    for (int k = 0; k < size3; ++k)
    {
        for (int j = 0; j < size2; ++j)
        {
            for (int i = 0; i < size1; ++i)
            {
                p1[k][j][i] = 0;
            }
        }
    }
    
    //  очистка памяти
    delete[] p;
    
    return 0;
}
```

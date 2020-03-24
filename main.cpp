#include <iostream>
#include <cmath>
#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>


using namespace std;
int menu();  //меню
float machine_zero(float e, int &k);  //машинный ноль в формате float
double machine_zero1(double e, int &k);  //машинный ноль в формате double
float comp_float();   //вычесление функции с помощью стандартных библиотек в формате float
double comp_double();     //вычесление функции с помощью стандартных библиотек в формате double
float teylor_float(float e);  //разложение ряда тейлора в формате float
double teylor_double(double e);   //разложение ряда тейлора в формате double
int main()
{
    setlocale(LC_ALL, "rus");
    float e;
    int k = 0;
    int variant;
    do{                                                     //вызов меню
    variant = menu();
    switch (variant) {
        case 1:
            cout << "Ряд тейлора в формате float..." << endl;
           machine_zero(e, k);
           comp_float();
           teylor_float(e);


            break;
        case 2:
            cout <<"Ряд тейлора в формате double..."<< endl;
            machine_zero1(e, k);
            comp_double();
            teylor_double(e);

            break;
        case 3:
            cout << "Выход из программы..." << endl;
            exit(EXIT_SUCCESS);
            break;
    }
    if (variant !=4)
            system("pause"); // задерживаем выполнение, чтобы пользователь мог увидеть результат выполнения выбранного пункта
    } while (variant !=4);



}
int menu()                                      //навигация по меню
{
    int variant;
    do{
        cout << "Выберите вариант\n" << endl;
        cout << "1. Ряд тейлора в формате float\n"
             << "2. Ряд тейлора в формате double\n"
             << "3. Выйти\n" << endl;
        cout << ">>> ";

        while (!(cin >>variant) || (cin.peek() != '\n'))
        {
        cin.clear();
        while (cin.get() != '\n');
        cout<<"Введите число от 1 до 3: "<<endl;
        }
    } while(variant < 0);
            return variant;
}


float comp_float()
{
    cout<< "Результат с помощью стандартных библиотек" <<endl;
    float x = 1;
    float f1;
    for(int i = 0; i < 10; i++)
    {
        f1 = log(1 + x) + 2*x;

        cout<< x << " - Значение аргумента" <<endl;
        cout<< f1 <<endl;
        x += 0.05;
    }
}


double comp_double()
{
    cout<< "Результат с помощью стандартных библиотек" <<endl;
    double x = 1;
    double f2;
    for(int i = 0; i < 10; i++)
    {
        f2 = log(1 + x) + 2*x;
        cout<< x << " - Значение аргумента" <<endl;
        cout<< f2 <<endl;
        x += 0.05;
    }
}


float machine_zero(float e, int k) //Машинный ноль float
{
    float e1;
    k = 0;
    do{
        e /= 2.0;
        e1 = e + 1.0;
        k++;
    } while(e1 > 1.0);

    return e;
}

float teylor_float(float e)
{
    cout<< endl << "Разложение ряда тейлора в формате float " <<endl;
    float y, s1;
    int k;  // кол-во иттераций, степень, знаменатель
    float z;    // знак
    float x = 1;

    for(int i = 0; i < 10; i++)
    {
        y = 0;
        s1 = 5; //присваеваем какое-то число
        z = 1;  //знак перед дробью

        for(k = 1; abs(s1) > e; k++)     //цикл выполняется пока член ряда тейлора больше машинного нуля
        {
            s1 = z*(pow(x, k) / k);   //вместо числа присваеваим член ряда тейлора
            y += s1;

        }

        cout<< k << " - Количество итераций" <<endl;
        cout<< x << " - Значение аргумента" <<endl;
        cout<< y + z*2*x << " - F2(x)" <<endl;
        cout<< abs(log(1 + x) + 2*x - (y + z*2*x))  << " - Точность вычислений\n"<<endl;
        x += 0.05;
        z = -z;
    }
}


double machine_zero1(double e, int &k)
{
    double e1;
    k = 0;
    do {
        e /= 2.0;
        e1 = e + 1.0;
        k++;
    } while(e1 > 1.0);

    return e;
}

double teylor_double(double e)
{
    double y, s1;
    double p1 = 0;  //знаменатель
    int k;  // кол-во иттераций,
    int z;   // знак
    double x = 1;
    for(int i = 0; i < 10; i++)
    {
        y = 0;
        s1 = 5; //присваеваем какое-то число
        z = 1;  //знак перед дробью

        for(k = 1; abs(s1) > e; k++)     //цикл выполняется пока член ряда тейлора больше машинного нуля
        {
            s1 = z*(pow(x, k) / k);   //вместо числа присваеваим член ряда тейлора
            y = y + s1;

        }

        cout<< k << " - Количество итераций" <<endl;
        cout<< x << " - Значение аргумента" <<endl;
        cout<< y + z*2*x << " - F2(x)" <<endl;
        cout<< (log(1 + x) + 2*x)  << " - Точность вычислений\n"<<endl;
        x += 0.05;
        z = -z;
    }
}

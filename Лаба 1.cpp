#include <iostream>

using namespace std;

int MAX(int* ptr_array) {
    int max = ptr_array[0];

    for (int i = 0; i < 5; i++) {
        if (max <= *(ptr_array + i)) {
            max = *(ptr_array + i);
        }
    }

    return max;
}
int MIN(int* ptr_array) {
    int min = ptr_array[0];

    for (int i = 0; i < 5; i++) {
        if (min >= *(ptr_array + i)) {
            min = *(ptr_array + i);
        }
    }

    return min;
}
int sum_array(int* ptr_array) {
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum = sum + *(ptr_array + i);
    }
    return sum;
}

//task 10
bool isSymmetric(int* ptr_matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (*(ptr_matrix + i * size + j) != *(ptr_matrix + j * size + i)) {
                return false;
            }
        }
    }
    return true;
}
void print_maxtrix(int* ptr_matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << *(ptr_matrix + i * size + j) << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void transpon(int* ptr_matrix, int size) {
    int temp_matrix[3][3];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            temp_matrix[j][i] = *(ptr_matrix + i * size + j);
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            *(ptr_matrix + i * size + j) = temp_matrix[i][j];
        }
    }
    return;
}


//task 11
int look_norm(int* ptr_matrix, int size) {
    int norm = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            norm += abs(*(ptr_matrix + i * size + j));
        }
    }
    return norm;
}
void input(int* ptr_matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << "ptr_matrix[" << i << "][" << j << "] = ";
            cin >> *(ptr_matrix + i * size + j);
        }
    }
    return;
}

void task1() {
    float var_d = 0;
    cout << "var_d = " << var_d << endl;

    float* ptr_var_d = &var_d;

    *ptr_var_d = -54.38;

    cout << "var_d = " << var_d << endl;
    return;
}

void task2() {
    int k = 100;
    cout << "k = " << k << endl;

    int* ptr_k = &k;
    *ptr_k = *ptr_k + 10;

    cout << "ptr_k = " << *ptr_k << "\nk = " << k << endl;
    return;
}

void task3() {
    int b = 10;
    cout << "b = " << b << endl;

    int a = NULL;
    int* ptr_a = &a;
    *ptr_a = b;

    cout << "ptr_a = " << *ptr_a << "\na = " << a << endl;
    return;
}

void task4() {
    int a = 1, b = 0;
    int* ptr_a = &a, * ptr_b = &b;
    cout << "a = " << *ptr_a << " b = " << *ptr_b << endl;

    *ptr_a = *ptr_a + *ptr_b;  // a = a + b
    *ptr_b = *ptr_a - *ptr_b;  // b = a - b (теперь b = исходное a)
    *ptr_a = *ptr_a - *ptr_b;  // a = a - b (теперь a = исходное b)

    cout << "a = " << a << " b = " << b << endl;
    return;
}

void task5() {
    int a = 10, b = 5;
    int* ptr_a = &a, * ptr_b = &b;
    cout << "a = " << *ptr_a << " b = " << *ptr_b << endl;

    int res = *ptr_a * *ptr_b;
    cout << "res = " << res << endl;
    return;
}

void task6() {
    int array[5] = { 1, 2, 3, 4, 5 };
    int* ptr_array = array;

    cout << "До изменения:\n";
    for (int i = 0; i < 5; i++) {
        cout << "ptr_array[" << i << "] = " << *(ptr_array + i) << endl;
    }

    for (int i = 0; i < 5; i++) {
        *(ptr_array + i) = *(ptr_array + i) * 2;
    }

    cout << "После изменения:\n";
    for (int i = 0; i < 5; i++) {
        cout << "ptr_array[" << i << "] = " << *(ptr_array + i) << endl;
    }
    return;
}

void task7() {
    int array[5] = { 3, 1, 8, 4, 5 };
    int* ptr_array = array;

    for (int i = 0; i < 5; i++) {
        cout << "ptr_array[" << i << "] = " << *(ptr_array + i) << endl;
    }

    int first_min = MIN(ptr_array);
    cout << "Первый MIN элемент = " << first_min << endl;

    //ищем индекс первого MIN
    int first_min_index = 0;
    for (int i = 0; i < 5; i++) {
        if (first_min == *(ptr_array + i)) {
            first_min_index = i;
        }
    }
    cout << "Первый MIN индекс = " << first_min_index << endl;

    // Ищем первый элемент, который не равен первому MIN
    int second_min = ptr_array[0];
    int second_min_index = -1;
    for (int i = 0; i < first_min_index; i++) {
        if (first_min < *(ptr_array + i)) {
            second_min = *(ptr_array + i);
            second_min_index = i;
            break;
        }
    }

    // Если нашли элемент, отличный от первого MIN, ищем среди оставшихся
    if (second_min_index != -1) {
        for (int i = second_min_index; i < 5; i++) {
            if (*(ptr_array + i) != first_min && *(ptr_array + i) < second_min) {
                second_min = *(ptr_array + i);
                second_min_index = i;
            }
        }
        cout << "MIN без учета первого MIN: " << second_min << " (индекс: " << second_min_index << ")" << endl;
    }

    return;
}

void task8() {
    int array[5] = { 6, 5, 3, 2, 1 };
    int* ptr_array = array;
    for (int i = 0; i < 5; i++) {
        cout << "ptr_array[" << i << "] = " << *(ptr_array + i) << endl;
    }

    int min = MIN(ptr_array);
    int max = MAX(ptr_array);
    cout << "MIN = " << min << endl
        << "MAX = " << max << endl;

    // Находим индексы MIN и MAX элементов
    int min_index = -1, max_index = -1;

    for (int i = 0; i < 5; i++) {
        if (*(ptr_array + i) == min && min_index == -1) {
            min_index = i;
        }
        if (*(ptr_array + i) == max && max_index == -1) {
            max_index = i;
        }
    }

    cout << "Индекс MIN: " << min_index << endl;
    cout << "Индекс MAX: " << max_index << endl;

    // Находим сумму элементов между MIN и MAX
    int sum = 0;

    if (min_index != -1 && max_index != -1) {
        int start, end;

        // Определяем начальный и конечный индексы
        if (min_index < max_index) {
            start = min_index + 1;
            end = max_index - 1;
        }
        else {
            start = max_index + 1;
            end = min_index - 1;
        }

        // Суммируем элементы между ними
        for (int i = start; i <= end; i++) {
            sum += *(ptr_array + i);
        }

        cout << "Сумма элементов между MIN и MAX: " << sum << endl;
    }

    return;
}

void task9() {
    int array[5] = { 1, 2, 3, 4, 5 };
    int* ptr_array = array;
    for (int i = 0; i < 5; i++) {
        cout << "ptr_array[" << i << "] = " << *(ptr_array + i) << endl;
    }

    cout << "Сумма элементов = " << sum_array(ptr_array) << endl;
    return;
}

void task10() {
    //симметричная
    int a_matrix[3][3] = {
        {1, 2, 3},
        {2, 4, 5},
        {3, 5, 6}
    };
    //не симметричная
    int b_matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    //симметричная
    int c_matrix[3][3] = {
        {2, 0, 0},
        {0, 2, 0},
        {0, 0, 2}
    };

    int* ptr_a_matrix = &a_matrix[0][0];
    int* ptr_b_matrix = &b_matrix[0][0];
    int* ptr_c_matrix = &c_matrix[0][0];

    bool a_symmetric = isSymmetric(ptr_a_matrix, 3);
    bool b_symmetric = isSymmetric(ptr_b_matrix, 3);
    bool c_symmetric = isSymmetric(ptr_c_matrix, 3);

    cout << "Матрица А:" << endl;
    print_maxtrix(ptr_a_matrix, 3);
    cout << "Матрица B:" << endl;
    print_maxtrix(ptr_b_matrix, 3);
    cout << "Матрица C:" << endl;
    print_maxtrix(ptr_c_matrix, 3);

    cout << "Проверка на симметричность" << endl
        << "Матрица А = " << a_symmetric << endl
        << "Матрица B = " << b_symmetric << endl
        << "Матрица C = " << c_symmetric << endl;

    cout << endl;
    transpon(ptr_a_matrix, 3);
    cout << "Транспонированная матрица А:" << endl;
    print_maxtrix(ptr_a_matrix, 3);
    transpon(ptr_b_matrix, 3);
    cout << "Транспонированная матрица B:" << endl;
    print_maxtrix(ptr_b_matrix, 3);
    transpon(ptr_c_matrix, 3);
    cout << "Транспонированная матрица C:" << endl;
    print_maxtrix(ptr_c_matrix, 3);

    cout << "Проверка на симметричность" << endl
        << "Матрица А = " << a_symmetric << endl
        << "Матрица B = " << b_symmetric << endl
        << "Матрица C = " << c_symmetric << endl;
    return;
}

void task11() {

    //уже заполненные матрицы A, B, C
    int a_matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 1},
        {2, 3, 4}
    };
    int b_matrix[3][3] = {
        {1, -2, 3},
        {2, -1, 0},
        {-3, 2, 1}
    };
    int c_matrix[3][3] = {
        {8, 1, 2},
        {3, 4, 5},
        {6, 7, 1}
    };


    /*
    int a_matrix[3][3];
    int b_matrix[3][3];
    int c_matrix[3][3];


    //Ввод вручную
    cout << "Введи элементы матрицы А" << endl;
    input(ptr_a_matrix, 3);
    cout << "Введи элементы матрицы B" << endl;
    input(ptr_b_matrix, 3);
    cout << "Введи элементы матрицы C" << endl;
    input(ptr_c_matrix, 3);
    //---------------------------------------------
    */

    int* ptr_a_matrix = &a_matrix[0][0];
    int* ptr_b_matrix = &b_matrix[0][0];
    int* ptr_c_matrix = &c_matrix[0][0];

    int a_norm = look_norm(ptr_a_matrix, 3);
    int b_norm = look_norm(ptr_b_matrix, 3);
    int c_norm = look_norm(ptr_c_matrix, 3);

    cout << "Матрица А:" << endl;
    print_maxtrix(ptr_a_matrix, 3);
    cout << "Матрица B:" << endl;
    print_maxtrix(ptr_b_matrix, 3);
    cout << "Матрица C:" << endl;
    print_maxtrix(ptr_c_matrix, 3);

    cout << "Норма матрицы" << endl
        << "A = " << a_norm << endl
        << "B = " << b_norm << endl
        << "C = " << c_norm << endl;

    cout << endl;
    if (a_norm <= b_norm && a_norm <= c_norm) {
        cout << "Матрица с наименьшей нормой: A" << endl;
        print_maxtrix(ptr_a_matrix, 3);
    }
    else if (b_norm <= a_norm && b_norm <= c_norm) {
        cout << "Матрица с наименьшей нормой: B" << endl;
        print_maxtrix(ptr_b_matrix, 3);
    }
    else {
        cout << "Матрица с наименьшей нормой: C" << endl;
        print_maxtrix(ptr_c_matrix, 3);
    }

    return;
}

int main()
{
    setlocale(LC_ALL, "RU");

    while (true) {
        system("cls");
        cout << "Лабораторная №1\n"
            << "\nЗадание 1.\nУказатель ptr_var_d -> var_d = 0.\nЧерез указатель ptr_var d изменить значение переменной var_d на -54.38. Вывести var_d.\n"
            << "\nЗадание 2.\nДано int k. Объявите ptr_k -> k.\nУвеличьте значение переменной k на 10, используя указатель ptr_k. Вывеcти k.\n"
            << "\nЗадание 3.\nДано int b. Объявите ptr_a -> int a.\nЧерез указатель ptr_a присвойте а значение b. Вывести а.\n"
            << "\nЗадание 4.\nОбъявите ptr_a -> а и указатель ptr_b -> b.\nВыполните обмен значениями а и b через ptr_a и ptr_b.\n"
            << "\nЗадание 5.\nОбъявите ptr_a -> а и указатель ptr_b -> b.\nВычислите произведение значений а и b через ptr_a и ptr_b. Вывести в res.\n"
            << "\nЗадание 6.\nДан массив int чисел.\nУвеличить все элементы массива в два раза.\n"
            << "\nЗадание 7.\nДан массив int чисел. \nОпределить номер MIN элемента массива и элемента, являющегося MIN без учета этого элемента.\n"
            << "\nЗадание 8.\nНайти сумму элементов массива, расположенных между MAX и MIN элементами.\nНаписать функции для MIN и MAX значений.\n"
            << "\nЗадание 9.\nНаписать функцию нахождения суммы элементов одномерного массива.\n"
            << "\nЗадание 10.\nДаны квадратные матрицы А, В, С.\nОпределить, есть ли среди них симметричная матрица.\nТранспонирование матрицы оформить как функцию.\nПроверку на симметричность матрицы оформить как функцию.\n"
            << "\nЗадание 11.\nДаны три квадратные матрицы.\nВывести ту из них, норма которой наименьшая (считать, что такая матрица одна).\nВ качестве нормы матрицы взять максимум абсолютных величин ее элементов.\nОформить как функции: ввод матрицы, вывод матрицы, нахождение нормы матрицы.\n"
            << "\n12. Выход\n";

        cout << "Введите число 1-12: ";
        int num;
        cin >> num;
        switch (num) {
        case 1:
            system("cls");
            task1();
            system("pause");
            break;
        case 2:
            system("cls");
            task2();
            system("pause");
            break;
        case 3:
            system("cls");
            task3();
            system("pause");
            break;
        case 4:
            system("cls");
            task4(); 
            system("pause");
            break;
        case 5:
            system("cls");
            task5();
            system("pause");
            break;
        case 6:
            system("cls");
            task6();
            system("pause");
            break;
        case 7:
            system("cls");
            task7();
            system("pause");
            break;
        case 8:
            system("cls");
            task8();
            system("pause");
            break;
        case 9:
            system("cls");
            task9();
            system("pause");
            break;
        case 10:
            system("cls");
            task10();
            system("pause");
            break;
        case 11:
            system("cls");
            task11();
            system("pause");
            break;
        case 12:
            cout << "Exit...";
            return 0;
        default:
            system("cls");
            cout << "Enter number 1-12!";
        }
    }
    return 0;
}


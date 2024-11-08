#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;


const int ROWS = 5; // Размер двумерного массива для упражнения 4
const int COLS = 5;

// Упражнение 1: Функции для нахождения максимума
int max(int a, int b) {
    return (a > b) ? a : b;
}

double max(double a, double b) {
    return (a > b) ? a : b;
}

int max(int a, int b, int c) {
    return max(max(a, b), c);
}

void exercise1() {
    int a, b, c;
    cout << "Введите три целых числа: ";
    cin >> a >> b >> c;
    cout << "Максимальное значение: " << max(a, b, c) << endl;
}

// Упражнение 2: Периметр треугольника
double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double perimeter(double x1, double y1, double x2, double y2, double x3, double y3) {
    return distance(x1, y1, x2, y2) + distance(x2, y2, x3, y3) + distance(x3, y3, x1, y1);
}

void exercise2() {
    double x1, y1, x2, y2, x3, y3;
    cout << "Введите координаты вершин треугольника (x1 y1 x2 y2 x3 y3): ";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    cout << "Периметр треугольника: " << perimeter(x1, y1, x2, y2, x3, y3) << endl;
}

// Упражнение 3: Проверка на простое число и подсчет простых чисел
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

void exercise3() {
    int count = 0, num;
    cout << "Введите 10 целых чисел: ";
    for (int i = 0; i < 10; ++i) {
        cin >> num;
        if (isPrime(num)) count++;
    }
    cout << "Количество простых чисел: " << count << endl;
}

// Упражнение 4: Заполнение двумерного массива и нахождение строки с наибольшим средним значением
void fillArray(int arr[ROWS][COLS], int N) {
    srand(time(0));
    for (int i = 0; i < ROWS; ++i)
        for (int j = 0; j < COLS; ++j)
            arr[i][j] = rand() % (N + 1);
}

double rowAverage(int arr[COLS]) {
    int sum = 0;
    for (int i = 0; i < COLS; ++i) sum += arr[i];
    return static_cast<double>(sum) / COLS;
}

void exercise4() {
    int arr[ROWS][COLS];
    int N;
    cout << "Введите максимальное значение N: ";
    cin >> N;
    fillArray(arr, N);

    int maxRow = 0;
    double maxAvg = rowAverage(arr[0]);
    for (int i = 1; i < ROWS; ++i) {
        double avg = rowAverage(arr[i]);
        if (avg > maxAvg) {
            maxAvg = avg;
            maxRow = i;
        }
    }

    cout << "Строка с наибольшим средним значением: " << maxRow << " со средним значением " << maxAvg << endl;
}

// Упражнение 5: Функция возведения в степень
double power(double x, int n) {
    if (n == 0) return 1;
    if (n > 0) return x * power(x, n - 1);
    return 1 / power(x, -n);
}

void exercise5() {
    double x;
    int n;
    cout << "Введите вещественное число x и целое число n: ";
    cin >> x >> n;
    cout << "Результат x^n: " << power(x, n) << endl;
}

// Главная функция с меню
int main() {
    int choice;
    setlocale(LC_ALL, "RUSSIAN");
    do {
        cout << "\nВыберите упражнение для выполнения:\n";
        cout << "1. Нахождение максимального значения из двух или трех чисел\n";
        cout << "2. Вычисление периметра треугольника\n";
        cout << "3. Подсчет простых чисел в последовательности из 10 целых чисел\n";
        cout << "4. Нахождение строки с наибольшим средним значением в двумерном массиве\n";
        cout << "5. Вычисление x^n с использованием рекурсии\n";
        cout << "0. Выход\n";
        cout << "Введите ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1: exercise1(); break;
        case 2: exercise2(); break;
        case 3: exercise3(); break;
        case 4: exercise4(); break;
        case 5: exercise5(); break;
        case 0: cout << "Выход из программы.\n"; break;
        default: cout << "Некорректный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}

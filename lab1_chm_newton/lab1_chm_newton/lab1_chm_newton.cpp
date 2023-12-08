//лаб1 чм Модифікований метод Ньютона
//


#include <iostream>
#include <cmath>

using namespace std;

// Функція, яку ми шукаємо корінь рівняння
double f(double x) {
    return pow(x, 6) - 3 * pow(x, 2) + x - 1;
}

// Перша похідна функції f(x)
double df(double x) {
    return 6 * pow(x, 5) - 6 * x + 1;
}

// Друга похідна функції f(x)
double d2f(double x) {
    return 30 * pow(x, 4) - 6;
}

// Модифікований метод Ньютона
double modifiedNewtonMethod(double x0, double epsilon, int maxIterations) {
    int iterations = 0;
    double x = x0;

    cout << "Модифікований метод Ньютона:" << endl;

    while (fabs(f(x)) > epsilon && iterations < maxIterations) {
        // Виведення інформації про поточну ітерацію
        cout << "Ітерація " << iterations + 1 << ": x = " << x << ", f(x) = " << f(x) << endl;

        // Апроксимація оберненої матриці Гессіана (другої похідної)
        double hessianApproximation = d2f(x) + 1e-5;

        // Оновлення x за модифікованим методом Ньютона
        x = x - f(x) / hessianApproximation;

        iterations++;
    }

    // Виведення результату
    if (iterations == maxIterations) {
        cout << "Досягнута максимальна кількість ітерацій:" << endl;
    }
    else {
        cout << "Розв'язок x = " << x << " за " << iterations << " ітерацій." << endl;
    }

    return x;
}

int main() {
    setlocale(LC_ALL, "uk_UA.utf8");

    // Початкове наближення, точність та максимальна кількість ітерацій
    double x0 = 1.0;
    double epsilon = 1e-4;
    int maxIterations = 1000;

    // Виклик модифікованого методу Ньютона
    double modifiedNewtonResult = modifiedNewtonMethod(x0, epsilon, maxIterations);

    return 0;
}

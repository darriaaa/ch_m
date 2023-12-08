//лаб1 чм Метод простої ітерації
#include <iostream>
#include <cmath>

using namespace std;

// Функція, для якої шукаємо корінь
double f(double x) {
    return pow(x, 6) - 3 * pow(x, 2) + x - 1;
}

// Метод простої ітерації
double simpleIterationMethod(double x0, double epsilon, int maxIterations) {
    int iterations = 0;
    double x = x0;

    wcout << "Метод простої ітерації:" << endl;

    // Поки не досягли необхідної точності або не перевищили максимальну кількість ітерацій
    while (fabs(f(x)) > epsilon && iterations < maxIterations) {
        // інформаці про поточну ітерацію
        wcout << "Ітерація " << iterations + 1 << ": x = " << x << ", f(x) = " << f(x) << endl;

        // Оновлюємо значення x за допомогою ітераційної формули
        x = x - 0.1 * f(x);  // Можна варіювати параметр для забезпечення збіжності
        iterations++;
    }

    // Вивід результату
    if (iterations == maxIterations) {
        wcout << "Досягнута максимальна кількість ітерацій." << endl;
    }
    else {
        wcout << "Розв'язок x = " << x << " за " << iterations << " ітерацій." << endl;
    }

    return x; // Повертаємо знайдене значення x
}

int main() {
    setlocale(LC_ALL, "uk_UA.utf8");

    // Початкове значення x, точність та максимальна кількість ітерацій
    double x0 = 1.0;
    double epsilon = 1e-4;//10^-4
    int maxIterations = 1000;

    // Викликаємо метод простої ітерації
    double simpleIterationResult = simpleIterationMethod(x0, epsilon, maxIterations);

    return 0;
}
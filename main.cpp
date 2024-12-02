#include <iostream>


int main() {
    setlocale(LC_ALL, "Rus");
    int n;
    std::cout << "Введите размер матрицы: ";
    std::cin >> n;

    // Выделяем память для исходной матрицы
    int** matrix = new int* [n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[n];
    }

    // Генерация матрицы
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = (rand() % 100) - 37;
        }
    }

    // Вывод исходной матрицы
    std::cout << "Исходная матрица: \n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }

    // Массив для хранения максимальных значений с каждого уровня (контура)
    int* max_values = new int[(n + 1) / 2];  // Величина массива будет половиной размера матрицы (около половины, для нечетных чисел)

    // Перебор по уровням
    int layer = 0;
    while (layer < (n + 1) / 2) {
        int max_value_on_layer = matrix[layer][layer];  // Начинаем с верхнего левого угла

        // Проходим по верхней строке текущего слоя
        for (int i = layer; i < n - layer; ++i) {
            if (matrix[layer][i] > max_value_on_layer) max_value_on_layer = matrix[layer][i];
        }
        // Проходим по правой колонке текущего слоя
        for (int i = layer + 1; i < n - layer; ++i) {
            if (matrix[i][n - layer - 1] > max_value_on_layer) max_value_on_layer = matrix[i][n - layer - 1];
        }
        // Проходим по нижней строке текущего слоя
        for (int i = n - layer - 2; i >= layer; --i) {
            if (matrix[n - layer - 1][i] > max_value_on_layer) max_value_on_layer = matrix[n - layer - 1][i];
        }
        // Проходим по левой колонке текущего слоя
        for (int i = n - layer - 2; i > layer; --i) {
            if (matrix[i][layer] > max_value_on_layer) max_value_on_layer = matrix[i][layer];
        }

        // Записываем максимальное значение для этого слоя
        max_values[layer] = max_value_on_layer;

        ++layer;  // Переходим к следующему слою
    }

    // Вывод максимальных значений
    std::cout << "Максимальные значения на каждом уровне (контуре): \n";
    for (int i = 0; i < (n + 1) / 2; ++i) {
        std::cout << max_values[i] << " ";
    }
    std::cout << "\n";

    // Освобождаем память
    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] max_values;

}

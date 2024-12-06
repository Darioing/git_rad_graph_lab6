#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Матрица смежности графа
const int matrix[8][8] = {
   // A  Б  B  Г  Д  Е  К  Л
    { 0, 1, 1, 1, 0, 0, 0, 0 }, // A
    { 1, 0, 0, 1, 1, 0, 0, 0 }, // Б
    { 1, 0, 0, 0, 0, 1, 0, 0 }, // B
    { 1, 1, 0, 0, 1, 1, 0, 0 }, // Г
    { 0, 1, 0, 1, 0, 0, 1, 0 }, // Д
    { 0, 0, 1, 1, 0, 0, 1, 0 }, // Е
    { 0, 0, 0, 0, 1, 1, 0, 1 }, // К
    { 0, 0, 0, 0, 0, 0, 1, 0 }  // Л
};

// Функция для проверки, является ли граф простым
bool isSimpleGraph(const int matrix[8][8], int n) {
    for (int i = 0; i < n; ++i) {
        if (matrix[i][i] != 0) return false; // Петля
    }
    return true;
}

// Функция для проверки, является ли граф нуль-графом
bool isNullGraph(const int matrix[8][8], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] != 0) return false;
        }
    }
    return true;
}

// Функция для нахождения максимальной степени вершины
int findMaxDegree(const int matrix[8][8], int n) {
    int maxDegree = 0;
    for (int i = 0; i < n; ++i) {
        int degree = 0;
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 1) ++degree;
        }
        maxDegree = max(maxDegree, degree);
    }
    return maxDegree;
}

// Функция для проверки наличия висячих вершин
bool hasHangingVertices(const int matrix[8][8], int n) {
    for (int i = 0; i < n; ++i) {
        int degree = 0;
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 1) ++degree;
        }
        if (degree == 1) return true;
    }
    return false;
}

int main() {
    const int n = 8; // Количество вершин

    // Вывод матрицы смежности
    cout << "Graph adjacency matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Проверка свойств графа
    cout << "Graph is " << (isSimpleGraph(matrix, n) ? "simple" : "not simple") << "." << endl;
    cout << "Graph " << (isNullGraph(matrix, n) ? "is" : "is not ") << " null-graph." << endl;

    // Максимальная степень вершины
    cout << "Maximum degree of a vertex: " << findMaxDegree(matrix, n) << "." << endl;

    // Проверка на наличие висячих вершин
    cout << "Graph " << (hasHangingVertices(matrix, n) ? "have" : "have not") << " hanging peaks." << endl;

    return 0;
}

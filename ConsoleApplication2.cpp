// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h> 
#include <fstream>
#include <ctime>

using namespace std;

struct Node
{
    int key;
    struct Node* left, * right;
};

struct Node* newNode(int item)
{
    struct Node* temp = new Node;
    temp->key = item;
    temp->left = temp->right = 0;
    return temp;
}
void storeSorted(Node* root, int arr[], int& i)
{
    if (root != 0)
    {
        storeSorted(root->left, arr, i);
        arr[i++] = root->key;
        storeSorted(root->right, arr, i);
    }
}
Node* insert(Node* node, int key)
{
    // Возвращается новый узел, если дерево "пустое"
    if (node == 0) return newNode(key);
    // Если дерево не пустое, то идет возврт вниз по дереву 
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    // Возвращается указатель узла 
    return node;
}
// Функция сортировки массива
void treeSort(int arr[], int n)
{
    struct Node* root = 0;
    root = insert(root, arr[0]);
    for (int i = 1; i < n; i++)
        root = insert(root, arr[i]);
    int i = 0;
    storeSorted(root, arr, i);
}

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(0));
    ofstream f1, f2;
    int n = 0;
    f1.open("array.txt");
    f2.open("array_sort.txt");
    cout << "Введите размерность массива: ";
    cin >> n;
    int arr[10000];
    double start_time = clock() / 100000.0; // начальное время
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1;
        f1 << arr[i] << ", ";
    }
    treeSort(arr, n);
    for (int i = 0; i < n; i++)
        f2 << arr[i] << ", ";
    f1.close();
    f2.close();
    double end_time = clock() / 100000.0; // конечное время
    double search_time = end_time - start_time;
    cout << "Сгенерированный массив - файл array.txt\n Отсортированный массив - файл array_sort.txt\n ";
    cout << "Время выполнения программы = " << search_time << " секунд \n";
    return 0;
}

// unsigned int start_time = clock(); // начальное время
// здесь должен быть фрагмент кода, время выполнения которого нужно измерить
// unsigned int end_time = clock(); // конечное время
// unsigned int search_time = end_time - start_time;
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

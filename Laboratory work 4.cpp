#include <iostream>
#include <algorithm>
using namespace std;

void bubble_sort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void print_ring(int* ring, int size, int start) {
    for (int i = 0; i < size; i++) {
        cout << ring[(start + i) % size] << " ";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Rus");
    cout << "Введиет размер кольца: ";
    cin >> size;

    int* ring = new int[size];

    for (int i = 0; i < size; i++) {
        cout << "Введите элемент " << i + 1 << ": ";
        cin >> ring[i];
    }

    cout << "Введенное кольцо: ";
    print_ring(ring, size, 0);

    cout << "Введите стартовый индекс K: ";
    int K;
    cin >> K;

    cout << "Введенное кольцо начиная с K до K+1: ";
    print_ring(ring, size, K);

    cout << "Кольцо после упорядочивания по убыванию: ";
    bubble_sort(ring, size);
    print_ring(ring, size, K);

    int new_size = 0;
    for (int i = 0; i < size; i++) {
        if (ring[i] % 2 == 0) {
            ring[new_size++] = ring[i];
        }
    }

    cout << "Кольцо после удаления нечетных элементов: ";
    print_ring(ring, new_size, K);

    return 0;
}





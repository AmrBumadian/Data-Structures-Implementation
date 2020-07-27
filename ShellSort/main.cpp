#include <iostream>
#include <iterator>

using namespace std;

void insertionSort(int *a, int length, int begin, int inc) {
    int temp, j;
    for (int i = begin + 1; i < length; i += inc) {
        temp = a[i];
        j = i - 1;
        while (j >= begin and a[j] > temp) {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = temp;
    }
}

void ShellSort(int *a, int length) {
    int inc;
    for (inc = 1; inc < (length - 1) / 9; inc = inc * 3 + 1);
    do {
        for (int begin = 0; begin < inc; ++begin)
            insertionSort(a, length, begin, inc);
        inc /= 3;
    } while (inc > 0);
}


int main() {
//    int a[10] = {4, 8, 9, 1, 32, 25, 27, 88, 55, 3};
    int a[15] = {15, 77, 122, 1, 1186, 60, 27, 7000, 5555, 3, 1111, 0, 2, 3, 8};
    ShellSort(a, 15);
    for (int i = 0; i < 15; ++i) {
        cout << a[i] << " ";
    }
    return 0;
}

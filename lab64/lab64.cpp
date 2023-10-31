#include <iostream>
using namespace std;
int countElementsLessThanC(int arr[], int n, double C, int currentIndex = 0) {
    if (currentIndex == n) {
        return 0;
    }

    int count = countElementsLessThanC(arr, n, C, currentIndex + 1);
    if (arr[currentIndex] < C) {
        count++;
    }

    return count;
}

int sumIntPartsAfterLastNegative(int arr[], int n, int currentIndex = 0, bool foundNegative = false) {
    if (currentIndex == n) {
        return 0;
    }

    int sum = sumIntPartsAfterLastNegative(arr, n, currentIndex + 1, foundNegative);

    if (!foundNegative) {
        if (arr[currentIndex] < 0) {
            foundNegative = true;
        }
    }
    else {
        sum += static_cast<int>(arr[currentIndex]);
    }

    return sum;
}

void swapElements(int arr[], int n, int currentIndex = 0, double maxElement = 0) {
    if (currentIndex == n) {
        return;
    }

    if (arr[currentIndex] > maxElement) {
        maxElement = arr[currentIndex];
    }

    swapElements(arr, n, currentIndex + 1, maxElement);

    if (arr[currentIndex] >= (maxElement * 0.8) && arr[currentIndex] <= (maxElement * 1.2)) {
        arr[currentIndex] = -arr[currentIndex];
    }
}

int main() {
    int n;
    double C;

    cout << "Enter the number of elements (n): ";
    cin >> n;

    int* arr = new int[n];

    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    cout << "Enter the value of C: ";
    cin >> C;

    int count = countElementsLessThanC(arr, n, C);
    cout << " less than C: " << count << endl;

    int sum = sumIntPartsAfterLastNegative(arr, n);
    cout << "Sum of integer parts after the last negative element: " << sum << endl;

    swapElements(arr, n);

    cout << "Modified array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}

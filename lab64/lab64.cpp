#include <iostream>

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

    std::cout << "Enter the number of elements (n): ";
    std::cin >> n;

    int* arr = new int[n];

    std::cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::cout << "Enter the value of C: ";
    std::cin >> C;

    int count = countElementsLessThanC(arr, n, C);
    std::cout << " less than C: " << count << std::endl;

    int sum = sumIntPartsAfterLastNegative(arr, n);
    std::cout << "Sum of integer parts after the last negative element: " << sum << std::endl;

    swapElements(arr, n);

    std::cout << "Modified array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr;

    return 0;
}

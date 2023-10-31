#include "pch.h"
#include "CppUnitTest.h"
#include "../lab64/lab64.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:


        TEST_METHOD(CountElementsLessThanC_Test)
        {
            // Arrange
            int arr[] = { 1, 2, 3, 4, 5 };
            int n = sizeof(arr) / sizeof(arr[0]);
            double C = 3.0;

            // Act
            int result = countElementsLessThanC(arr, n, C);

            // Assert
            Assert::AreEqual(2, result, L"Count of elements less than C is incorrect", LINE_INFO());
        }
        
    };
}
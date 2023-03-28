#include "pch.h"
#include "CppUnitTest.h"
#include "F:\Game Programming\211-cpp-OOP-nice1stu\DynamicArrayClass\DynamicArrayClass.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DynamicArrayUnitTest
{
    TEST_CLASS(DynamicArrayTest)
    {
    public:
        TEST_METHOD(AddAndGetElement)
        {
            DynamicArray<int> arr(5);

            arr.add(1);
            arr.add(2);
            arr.add(3);

            Assert::AreEqual(arr.getSize(), static_cast<size_t>(3));

            Assert::AreEqual(arr.get(0), 1);
            Assert::AreEqual(arr.get(1), 2);
            Assert::AreEqual(arr.get(2), 3);
        }

        TEST_METHOD(Resize)
        {
            DynamicArray<int> arr(2);

            arr.add(1);
            arr.add(2);
            arr.add(3);

            Assert::AreEqual(arr.getSize(), static_cast<size_t>(3));

            Assert::AreEqual(arr.get(0), 1);
            Assert::AreEqual(arr.get(1), 2);
            Assert::AreEqual(arr.get(2), 3);
        }

        TEST_METHOD(OutOfRangeException)
        {
            DynamicArray<int> arr(5);

            arr.add(1);
            arr.add(2);
            arr.add(3);

            Assert::ExpectException<std::out_of_range>([&]() { arr.get(3); });
        }

        TEST_METHOD(Sort)
        {
            DynamicArray<int> arr(5);

            arr.add(69);
            arr.add(13);
            arr.add(100);
            arr.add(101);
            arr.add(1);

            arr.sort();

            Assert::AreEqual(arr.getSize(), static_cast<size_t>(5));
            Assert::AreEqual(arr.get(0), 1);
            Assert::AreEqual(arr.get(1), 13);
            Assert::AreEqual(arr.get(2), 69);
            Assert::AreEqual(arr.get(3), 100);
            Assert::AreEqual(arr.get(4), 101);
        }

        TEST_METHOD(TestDoubleArrayAverage)
        {
            DynamicArray<double> doubleArray(10);
            doubleArray.add(1.0);
            doubleArray.add(2.0);
            doubleArray.add(3.0);

            double expectedAverage = 2.0;
            double actualAverage = average(doubleArray);

            Assert::AreEqual(expectedAverage, actualAverage);
        }

        TEST_METHOD(TestIntArrayAverage)
        {
            DynamicArray<int> integerArray(10);
            integerArray.add(1);
            integerArray.add(2);
            integerArray.add(3);

            double expectedAverage = 2.0;
            double actualAverage = average(integerArray);

            Assert::AreEqual(expectedAverage, actualAverage);
        }
    };
}
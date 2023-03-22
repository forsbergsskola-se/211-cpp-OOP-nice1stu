#include "pch.h"
#include "CppUnitTest.h"
#include "D:\Game Programming\211-cpp-OOP-nice1stu\LinkedList\LinkedList.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace LinkedListTest
{
    TEST_CLASS(UnitTestLinkedList)
    {
    private:
        LinkedList<int> list;

    public:
        void SetUpStdList()
        {
            list.Emplace(13);
            list.Emplace(5);
            list.Emplace(100);
            list.Emplace(101);
            list.Emplace(69);
        }

        void ClearStdList()
        {
            list.Clear();
        }

        TEST_METHOD_INITIALIZE(SetUp)
        {
            SetUpStdList();
        }

        TEST_METHOD_CLEANUP(TearDown)
        {
            ClearStdList();
        }

        TEST_METHOD(TestAddOne)
        {
            Assert::AreEqual(list.Count(), 5u, L"List size should be 5", LINE_INFO());
            list.Emplace(4);
            Assert::AreEqual(list.Count(), 6u, L"List size should be 6", LINE_INFO());
        }

        TEST_METHOD(TestEmptyList)
        {
            ClearStdList();
            Assert::AreEqual(list.Count(), 0u, L"List size should be 0", LINE_INFO());
        }

        TEST_METHOD(TestMultiAdd)
        {
            vector<int> items{ 0, -2, 54 };
            list.MultiAdd(items);
            Assert::AreEqual(list.Count(), 8u, L"List size should be 8", LINE_INFO());
        }

        TEST_METHOD(TestGetItemFromCorrectIndex)
        {
            Assert::AreEqual(list.Get(2), 100, L"Item at index 1 should be 100", LINE_INFO());
        }

        TEST_METHOD(TestSetIteminCorrectIndex)
        {
            list.Set(3, 999);
            Assert::AreEqual(list.Get(3), 999, L"Item at index 3 should be 999", LINE_INFO());
        }

        TEST_METHOD(TestCountIsZeroAfterClear)
        {
            list.Clear();
            Assert::AreEqual(list.Count(), 0u, L"List size should be 0", LINE_INFO());
        }

        TEST_METHOD(TestRemoveIndexAt)
        {
            list.RemoveAt(1);
            Assert::AreEqual(list.Count(), 4u, L"List size should be 4", LINE_INFO());
            Assert::AreEqual(list.Get(1), 100, L"Item at index 1 should be 100", LINE_INFO());
        }

        TEST_METHOD(TestContainsValueAtCorrectIndex)
        {
            Assert::IsTrue(list.Contains(5), L"List should contain 5", LINE_INFO());
            Assert::IsFalse(list.Contains(4), L"List should not contain 4", LINE_INFO());
        }

        TEST_METHOD(IndexOfExistingItemReturnsCorrectIndex)
        {
            int itemToFind = 100;
            uint32_t index = list.IndexOf(itemToFind);
            Assert::AreEqual((uint32_t)2, index);
        }

        TEST_METHOD(IndexOfFirstItemReturnsCorrectIndex)
        {
            int itemToFind = 13;
            uint32_t index = list.IndexOf(itemToFind);
            Assert::AreEqual((uint32_t)0, index);
        }

        TEST_METHOD(IndexOfLastItemReturnsCorrectIndex)
        {
            int itemToFind = 69;
            uint32_t index = list.IndexOf(itemToFind);
            Assert::AreEqual((uint32_t)4, index);
        }

        TEST_METHOD(IndexOfNonExistingItemReturnsMinusOne)
        {
            int itemToFind = 123;
            uint32_t index = list.IndexOf(itemToFind);
            Assert::AreEqual((uint32_t)-1, index);
        }

        TEST_METHOD(RemoveExistingItemRemovesItemFromList)
        {
            int itemToRemove = 100;
            int removedItem = list.Remove(itemToRemove);

            Assert::AreEqual(itemToRemove, removedItem);
            Assert::IsFalse(list.Contains(itemToRemove));
        }

        TEST_METHOD(RemoveFirstItemRemovesItemFromList)
        {
            int itemToRemove = 13;
            int removedItem = list.Remove(itemToRemove);

            Assert::AreEqual(itemToRemove, removedItem);
            Assert::IsFalse(list.Contains(itemToRemove));
        }

        TEST_METHOD(RemoveLastItemRemovesItemFromList)
        {
            int itemToRemove = 69;
            int removedItem = list.Remove(itemToRemove);

            Assert::AreEqual(itemToRemove, removedItem);
            Assert::IsFalse(list.Contains(itemToRemove));
        }

        TEST_METHOD(RemoveNonExistingItemReturnsDefaultValue)
        {
            int itemToRemove = 123;
            int removedItem = list.Remove(itemToRemove);

            Assert::AreEqual(0, removedItem);
        }
    };
}
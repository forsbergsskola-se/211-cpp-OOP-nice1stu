#include "pch.h"
#include "CppUnitTest.h"
#include "F:\Game Programming\211-cpp-OOP-nice1stu\StringClassExercise\StringClassExercise.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringClassExerciseTests
{
    TEST_CLASS(StringClassExerciseTests)
    {
    public:

        TEST_METHOD(TestDefaultConstructor)
        {
            StringClassExercise str;
            Assert::AreEqual("", str.getString());
        }

        TEST_METHOD(TestSizeConstructor)
        {
            StringClassExercise str(10);
            Assert::AreEqual("", str.getString());
        }

        TEST_METHOD(TestDefaultTextConstructor)
        {
            StringClassExercise str("Hello world!", 256);
            Assert::AreEqual("Hello world!", str.getString());
        }

        TEST_METHOD(TestCopyConstructor)
        {
            StringClassExercise str1("Hello world!", 256);
            StringClassExercise str2(str1);
            Assert::AreEqual("Hello world!", str2.getString());
        }

        TEST_METHOD(TestMoveConstructor)
        {
            StringClassExercise str1("Hello world!", 256);
            StringClassExercise str2(std::move(str1));
            Assert::AreEqual("Hello world!", str2.getString());
            Assert::AreEqual("", str1.getString());
        }

        TEST_METHOD(TestCopyAssignmentOperator)
        {
            StringClassExercise str1("Hello world!", 256);
            StringClassExercise str2;
            str2 = str1;
            Assert::AreEqual("Hello world!", str2.getString());
        }

        TEST_METHOD(TestMoveAssignmentOperator)
        {
            StringClassExercise str1("Hello world!", 256);
            StringClassExercise str2;
            str2 = std::move(str1);
            Assert::AreEqual("Hello world!", str2.getString());
            Assert::AreEqual("", str1.getString());
        }

        TEST_METHOD(TestEqualityOperator)
        {
            StringClassExercise str1("Hello world!", 256);
            StringClassExercise str2("Hello world!", 256);
            StringClassExercise str3("Goodbye world!", 256);
            Assert::IsTrue(str1 == str2);
            Assert::IsFalse(str1 == str3);
        }

        TEST_METHOD(TestAppend)
        {
            StringClassExercise str("Hello", 256);
            str.append(" world!");
            Assert::AreEqual("Hello world!", str.getString());
        }

        TEST_METHOD(TestAppendLine)
        {
            StringClassExercise str("Hello", 256);
            str.appendLine("world!");
            Assert::AreEqual("Hello\nworld!\n", str.getString());
        }

        TEST_METHOD(TestAppendLineThrowsException)
        {
            StringClassExercise str("Hello\n", 256);
            try
            {
                str.appendLine("world!");
                Assert::Fail(L"Expected runtime_error not thrown");
            }
            catch (const std::runtime_error&)
            {
                Assert::AreEqual("Hello\n", str.getString());
            }
        }
    };
}
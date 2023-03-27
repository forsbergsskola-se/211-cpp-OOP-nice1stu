#include "pch.h"
#include "CppUnitTest.h"
#include "D:\Game Programming\211-cpp-OOP-nice1stu\StringClassExercise\StringClassExercise.cpp"

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
    };
}
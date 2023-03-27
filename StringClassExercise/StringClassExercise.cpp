#include <iostream>
#include <cstring>
#include <stdexcept>
#include <cstdio>
#include "Header.h"

using namespace std;

template<typename T>
class DynamicArray {
private:
    T* data;
    size_t size;
    size_t count;

public:
    DynamicArray(size_t count) : data(new T[count]), size(0), count(count) {}

    ~DynamicArray()
    {
        delete[] data;
    }

    void add(const T& element)
    {
        if (size == count) resize();

        data[size++] = element;
    }

    const T& get(size_t index) const
    {
        return (index >= size) ? throw std::out_of_range("Index out of range!") : data[index];
    }

    size_t getSize() const
    {
        return size;
    }

private:
    void resize()
    {
        count *= 2;
        T* newData = new T[count];
        for (size_t i = 0; i < size; ++i)
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
};


class StringClassExercise
{
private:
    size_t length;
    char* buffer;
    size_t maxSize;

public:
    StringClassExercise() : buffer(new char[256]), length(0), maxSize(256)
    {
        cout << "Constructing empty string\n";
        buffer[0] = '\0';
    }

    StringClassExercise(size_t maxSize) : buffer(new char[maxSize]), length(0), maxSize(maxSize)
    {
        cout << "Constructing empty string with max size " << maxSize << "\n";
        buffer[0] = '\0';
    }

    StringClassExercise(const char* defaultText, size_t maxSize) : buffer(new char[maxSize]), length(strlen(defaultText)), maxSize(maxSize)
    {
        cout << "Constructing string with default text \"" << defaultText << "\"\n";
        length >= maxSize ? throw runtime_error("Default text is too long!") : void();
        strcpy_s(buffer, maxSize, defaultText);
    }

    StringClassExercise(const StringClassExercise& other) : buffer(new char[other.maxSize]), length(other.length), maxSize(other.maxSize)
    {
        cout << "Constructing string by copy\n";
        strcpy_s(buffer, maxSize, other.buffer);
    }

    StringClassExercise(StringClassExercise&& other) noexcept : buffer(other.buffer), length(other.length), maxSize(other.maxSize)
    {
        cout << "Constructing string by move\n";
        other.buffer = nullptr;
        other.length = 0;
        other.maxSize = 0;
    }

    ~StringClassExercise()
    {
        cout << "Destructing string \"" << buffer << "\"\n";
        delete[] buffer;
    }

    StringClassExercise& operator=(const StringClassExercise& other)
    {
        if (this != &other)
        {
            delete[] buffer;
            length = other.length;
            maxSize = other.maxSize;
            buffer = new char[maxSize];
            strcpy_s(buffer, maxSize, other.buffer);
        }
        return *this;
    }

    StringClassExercise& operator=(StringClassExercise&& other) noexcept
    {
        if (this != &other)
        {
            delete[] buffer;
            buffer = other.buffer;
            length = other.length;
            maxSize = other.maxSize;
            other.buffer = nullptr;
            other.length = 0;
            other.maxSize = 0;
        }
        return *this;
    }

    bool operator==(const StringClassExercise& other) const
    {
        return strcmp(buffer, other.buffer) == 0;
    }

    void append(const char* text)
    {
        length + strlen(text) >= maxSize ? throw runtime_error("String would exceed max size!") : void();
        strcat_s(buffer, maxSize, text);
        length += strlen(text);
    }

    void appendLine(const char* text)
    {
        length + strlen(text) >= maxSize ? throw runtime_error("String would exceed max size!") : void();
        strcat_s(buffer, maxSize, text);
        strcat_s(buffer, maxSize, "\n");
        length += strlen(text) + 1;
    }

    void print() const
    {
        cout << "Current string: \"" << buffer << "\"\n";
    }

    const char* getString() const
    {
        return buffer;
    }
};

ostream& operator<<(ostream& os, const StringClassExercise& string)
    os << string.getString();
    return os;
}

int main()
{
    try
    {
        StringClassExercise joinText(20);
        joinText.append("Foo");
        joinText.appendLine("Bar");
        cout << "text1: ";
        joinText.print();

        StringClassExercise defaultText("The quick brown fox", 25);
        defaultText.append(" jumped over the lazy dog");
        cout << "text2: " << defaultText.getString() << endl;

        StringClassExercise tooLongText(5);
        tooLongText.append(">How much wood");
        tooLongText.appendLine("longer text");
        cout << "text3: " << tooLongText.getString() << endl;

        StringClassExercise copiedText = defaultText;
        cout << "text4: " << copiedText.getString() << endl;

        StringClassExercise movedText = move(tooLongText);
        cout << "text5: " << movedText.getString() << endl;

        try
        {
            joinText.append("This string is too long");
        }
        catch (const exception& e)
        {
            cerr << "Error: " << e.what() << endl;
        }
    }
    catch (const exception& e)
    {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}
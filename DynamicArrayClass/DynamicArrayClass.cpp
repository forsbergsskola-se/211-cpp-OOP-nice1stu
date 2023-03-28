#include <iostream>
#include <cstring>
#include <stdexcept>
#include <cstdio>
#include "Header.h"

using namespace std;

template<typename T>
class DynamicArray
{
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
            if (size == count)
            {
                resize();
            }
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

int main()
{
    return 0;
}
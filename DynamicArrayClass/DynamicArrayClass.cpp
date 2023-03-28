#include <iostream>
#include <cstring>
#include <stdexcept>

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
        return (index >= size) ? throw out_of_range("Index out of range!") : data[index];
    }

    size_t getSize() const
    {
        return size;
    }

    void sort()
    {
        for (size_t i = 0; i < size - 1; ++i)
        {
            for (size_t j = 0; j < size - i - 1; ++j)
            {
                if (data[j] > data[j + 1])
                {
                    swap(data[j], data[j + 1]);
                }
            }
        }
    }

    template<typename U>
    U narrow_cast(size_t index) const
    {
        return static_cast<U>(get(index));
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

// EXERCISE: average
double average(const DynamicArray<double>& arr)
{
    double sum = 0.0;
    for (size_t i = 0; i < arr.getSize(); ++i)
    {
        sum += arr.get(i);
    }
    return sum / arr.getSize();
}

double average(const DynamicArray<int>& arr)
{
    double sum = 0.0;
    for (size_t i = 0; i < arr.getSize(); ++i)
    {
        sum += arr.get(i);
    }
    return sum / arr.getSize();
}

int main()
{
    return 0;
}
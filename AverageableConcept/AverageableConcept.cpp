#include <concepts>
#include <iostream>

template<typename T>
concept Averageable = std::is_default_constructible_v<T>
&& requires (T a, T b)
{
    { a + b } -> std::same_as<T>;
    { a / 2 } -> std::same_as<T>;
};

template<Averageable T>
T average(T a, T b)
{
    return (a + b) / 2;
}

int main()
{
    int x = 5;
    int y = 10;
    double z = 3.5;
    double w = 7.5;

    std::cout << average(x, y) << '\n'; // prints 7
    std::cout << average(z, w) << '\n'; // prints 5.5
}

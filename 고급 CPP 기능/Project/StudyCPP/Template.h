#pragma once

#include <iostream>

template <typename T>
T max(T a, T b)
{
    return (a > b) ? a : b;
}

template <typename T>
class Pair
{
private:
    T first, second;
    
public:
    // 생성자
    Pair(T a, T b) : first(a), second(b) {}

    // first에 대한 getter 메소드
    T getFirst() const { return first; }

    // second에 대한 getter 메소드
    T getSecond() { return second; }
};

// 템플릿 특수화 (Template Specialization)

template<>
class Pair<const char*>
{
private:
    const char* first;
    const char* second;
public:
    Pair(const char* a, const char* b) : first(a), second(b) {}
    const char* getFirst() const { return first; }
    const char* getSecond() const { return second; }

    int compare() const
    {
        return strcmp(first, second);
    }
};

template <typename T>
struct TIsArithmetic
{
    enum {Value = false};
};

template<>
struct TIsArithmetic<int>
{
    enum { Value = true };
};

template<>
struct TIsArithmetic<float>
{
    enum { Value = true };
};

template <typename T>
void CheckArithmeticType()
{
    if (TIsArithmetic<T>::Value)
    {
        std::cout << "The type is arithmetic." << std::endl;
    }
    else
    {
        std::cout << "The type is not arithmetic." << std::endl;
    }
}

// Template 부분 특수화

// Template Meta Programing (TMP)
template <int N>
struct Factorial
{
    static const int value = N * Factorial<N - 1>::value;
};
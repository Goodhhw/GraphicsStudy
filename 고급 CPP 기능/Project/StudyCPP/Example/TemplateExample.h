#pragma once

#include <iostream>

#include "BaseExample.h"

template <typename T>
T tmax(T a, T b)
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

// Template 부분 특수화 (Partial specialization)
template <typename T1, typename T2>
class Pair2
{
private:
    T1 first;
    T2 second;
public:
    Pair2(T1 a, T2 b) : first(a), second(b){}
    T1 getFirst() const {return first;}
    T2 getSecond() const {return second;}
};

template <typename T>
class Pair2<T, T>
{
private:
    T first;
    T second;
public:
    Pair2(T a, T b) : first(a), second(b) {}
    T getFirst() const {return first;}
    T getSecond() const {return second;}
    T getSum() const {return first + second;}
};

template <typename T>
class Pair2<T*, T*>
{
private:
    T* first;
    T* second;
public:
    Pair2(T* a, T* b) : first(a), second(b) {}
    T* getFirst() const {return first;}
    T* getSecond() const {return second;}
    T getDereferencedSum() const {return *first + *second;}
};

// Template Meta Programing (TMP)
template <int N>
struct Factorial
{
    static const int value = N * Factorial<N - 1>::value;
};

class TemplateExample : public ExampleBase
{
protected:
    virtual string getTitle() const override
    {
        return "TemplateExample";
    }
    
    virtual void ChildRun() override
    {
        std::cout << tmax(3, 7) << std::endl;
        std::cout << tmax(3.5, 7.2) << std::endl;
        std::cout << tmax('a', 'b') << std::endl;

        Pair<int> intPair(1, 2);
        Pair<double> doublePair(3.5, 4.5);
        Pair<const char*> charPair("hello", "world");

        std::cout << "Int Pair: " << intPair.getFirst() << ", " << intPair.getSecond() << std::endl;
        std::cout << "Double Pair: " << doublePair.getFirst() << ", " << doublePair.getSecond() << std::endl;
        std::cout << "Char Pair comparison: " << charPair.compare() << std::endl;
        
        Pair2<int, double> mixedPair(1, 2.5);
        std::cout << "Mixed Pair: (" << mixedPair.getFirst() << ", " << mixedPair.getSecond() << ")" << std::endl;
    
        Pair2<int, int> intPair2(3, 4);
        std::cout << "Int Pair: (" << intPair2.getFirst() << ", " << intPair2.getSecond() << ") with sum: " << intPair2.getSum() << std::endl;

        int a = 5, b = 6;
        Pair2<int*, int*> pointerPair(&a, &b);
        std::cout << "Pointer Pair: (" << *pointerPair.getFirst() << ", " << *pointerPair.getSecond() << ") with dereferenced sum: " << pointerPair.getDereferencedSum() << std::endl;
    }
};
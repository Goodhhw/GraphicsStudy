### 템플릿과 제네릭 프로그래밍

템플릿은 C++에서 타입에 독립적인 일반화된 코드를 작성할 수 있게 하는 강력한 기능입니다. 이를 통해 코드의 재사용성을 높이고, 다양한 타입을 처리할 수 있습니다.

#### 1. 함수 템플릿

함수 템플릿은 타입에 구애받지 않는 함수를 작성할 수 있게 합니다. 예를 들어, 두 개의 값을 비교하여 큰 값을 반환하는 `max` 함수를 작성해 보겠습니다.

```cpp
#include <iostream>

// 함수 템플릿 정의
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    std::cout << max(3, 7) << std::endl;     // 정수 비교
    std::cout << max(3.5, 7.2) << std::endl; // 실수 비교
    std::cout << max('a', 'z') << std::endl; // 문자 비교
    return 0;
}
```

이 함수 템플릿은 `T`라는 제네릭 타입을 사용합니다. 함수가 호출될 때, 인자의 타입에 맞게 `T`가 구체화됩니다. 예를 들어, `max(3, 7)` 호출 시 `T`는 `int`로, `max(3.5, 7.2)` 호출 시 `T`는 `double`로 구체화됩니다.

#### 2. 클래스 템플릿

클래스 템플릿은 타입에 독립적인 클래스를 작성할 수 있게 합니다. 다음은 두 개의 값을 저장하는 `Pair` 클래스를 템플릿으로 작성한 예제입니다.

```cpp
#include <iostream>

// 클래스 템플릿 정의
template <typename T>
class Pair {
private:
    T first, second;
public:
    Pair(T a, T b) : first(a), second(b) {}
    T getFirst() const { return first; }
    T getSecond() const { return second; }
};

int main() {
    Pair<int> intPair(1, 2);
    Pair<double> doublePair(3.5, 4.5);

    std::cout << "Int Pair: " << intPair.getFirst() << ", " << intPair.getSecond() << std::endl;
    std::cout << "Double Pair: " << doublePair.getFirst() << ", " << doublePair.getSecond() << std::endl;

    return 0;
}
```

이 클래스 템플릿은 `T` 타입의 두 값을 저장합니다. 클래스가 인스턴스화될 때, `T` 타입이 구체화됩니다. 예를 들어, `Pair<int>`는 `int` 타입의 두 값을 저장하고, `Pair<double>`는 `double` 타입의 두 값을 저장합니다.

#### 3. 템플릿 특수화

때로는 특정 타입에 대해 템플릿을 다르게 정의하고 싶을 때가 있습니다. 이를 템플릿 특수화(template specialization)라고 합니다. 예를 들어, `const char*` 타입의 `Pair` 클래스는 문자열 비교를 위해 특수화할 수 있습니다.

```cpp
#include <iostream>
#include <cstring>

// 일반 템플릿
template <typename T>
class Pair {
private:
    T first, second;
public:
    Pair(T a, T b) : first(a), second(b) {}
    T getFirst() const { return first; }
    T getSecond() const { return second; }
};

// 템플릿 특수화
template <>
class Pair<const char*> {
private:
    const char* first;
    const char* second;
public:
    Pair(const char* a, const char* b) : first(a), second(b) {}
    const char* getFirst() const { return first; }
    const char* getSecond() const { return second; }

    int compare() const {
        return strcmp(first, second);
    }
};

int main() {
    Pair<int> intPair(1, 2);
    Pair<const char*> charPair("hello", "world");

    std::cout << "Int Pair: " << intPair.getFirst() << ", " << intPair.getSecond() << std::endl;
    std::cout << "Char Pair comparison: " << charPair.compare() << std::endl;

    return 0;
}
```

이 예제에서 `Pair<const char*>`는 `const char*` 타입의 특수화를 사용하여 문자열 비교 기능을 추가했습니다.

### 요약

- **함수 템플릿**: 타입에 구애받지 않는 함수를 작성할 수 있게 합니다.
- **클래스 템플릿**: 타입에 구애받지 않는 클래스를 작성할 수 있게 합니다.
- **템플릿 특수화**: 특정 타입에 대해 템플릿을 다르게 정의할 수 있습니다. 특수화는 일반 템플릿 정의 이후에 작성합니다.



### 템플릿과 제네릭 프로그래밍

템플릿은 C++에서 타입에 독립적인 일반화된 코드를 작성할 수 있게 하는 강력한 기능입니다. 이를 통해 코드의 재사용성을 높이고, 다양한 타입을 처리할 수 있습니다.

#### 1. 함수 템플릿

함수 템플릿은 타입에 구애받지 않는 함수를 작성할 수 있게 합니다. 예를 들어, 두 개의 값을 비교하여 큰 값을 반환하는 `max` 함수를 작성해 보겠습니다.

```cpp
#include <iostream>

// 함수 템플릿 정의
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    std::cout << max(3, 7) << std::endl;     // 정수 비교
    std::cout << max(3.5, 7.2) << std::endl; // 실수 비교
    std::cout << max('a', 'z') << std::endl; // 문자 비교
    return 0;
}
```

이 함수 템플릿은 `T`라는 제네릭 타입을 사용합니다. 함수가 호출될 때, 인자의 타입에 맞게 `T`가 구체화됩니다. 예를 들어, `max(3, 7)` 호출 시 `T`는 `int`로, `max(3.5, 7.2)` 호출 시 `T`는 `double`로 구체화됩니다.

#### 2. 클래스 템플릿

클래스 템플릿은 타입에 독립적인 클래스를 작성할 수 있게 합니다. 다음은 두 개의 값을 저장하는 `Pair` 클래스를 템플릿으로 작성한 예제입니다.

```cpp
#include <iostream>

// 클래스 템플릿 정의
template <typename T>
class Pair {
private:
    T first, second;
public:
    Pair(T a, T b) : first(a), second(b) {}
    T getFirst() const { return first; }
    T getSecond() const { return second; }
};

int main() {
    Pair<int> intPair(1, 2);
    Pair<double> doublePair(3.5, 4.5);

    std::cout << "Int Pair: " << intPair.getFirst() << ", " << intPair.getSecond() << std::endl;
    std::cout << "Double Pair: " << doublePair.getFirst() << ", " << doublePair.getSecond() << std::endl;

    return 0;
}
```

이 클래스 템플릿은 `T` 타입의 두 값을 저장합니다. 클래스가 인스턴스화될 때, `T` 타입이 구체화됩니다. 예를 들어, `Pair<int>`는 `int` 타입의 두 값을 저장하고, `Pair<double>`는 `double` 타입의 두 값을 저장합니다.

#### 3. 템플릿 특수화

때로는 특정 타입에 대해 템플릿을 다르게 정의하고 싶을 때가 있습니다. 이를 템플릿 특수화(template specialization)라고 합니다. 예를 들어, `const char*` 타입의 `Pair` 클래스는 문자열 비교를 위해 특수화할 수 있습니다.

```cpp
#include <iostream>
#include <cstring>

// 일반 템플릿
template <typename T>
class Pair {
private:
    T first, second;
public:
    Pair(T a, T b) : first(a), second(b) {}
    T getFirst() const { return first; }
    T getSecond() const { return second; }
};

// 템플릿 특수화
template <>
class Pair<const char*> {
private:
    const char* first;
    const char* second;
public:
    Pair(const char* a, const char* b) : first(a), second(b) {}
    const char* getFirst() const { return first; }
    const char* getSecond() const { return second; }

    int compare() const {
        return strcmp(first, second);
    }
};

int main() {
    Pair<int> intPair(1, 2);
    Pair<const char*> charPair("hello", "world");

    std::cout << "Int Pair: " << intPair.getFirst() << ", " << intPair.getSecond() << std::endl;
    std::cout << "Char Pair comparison: " << charPair.compare() << std::endl;

    return 0;
}
```

이 예제에서 `Pair<const char*>`는 `const char*` 타입의 특수화를 사용하여 문자열 비교 기능을 추가했습니다.

### 요약

- **함수 템플릿**: 타입에 구애받지 않는 함수를 작성할 수 있게 합니다.
- **클래스 템플릿**: 타입에 구애받지 않는 클래스를 작성할 수 있게 합니다.
- **템플릿 특수화**: 특정 타입에 대해 템플릿을 다르게 정의할 수 있습니다. 특수화는 일반 템플릿 정의 이후에 작성합니다.

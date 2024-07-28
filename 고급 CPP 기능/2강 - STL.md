### 표준 템플릿 라이브러리 (STL, Standard Template Library)

표준 템플릿 라이브러리(STL)는 C++ 표준 라이브러리의 중요한 구성 요소로, 다양한 컨테이너(Container), 알고리즘(Algorithm), 반복자(Iterator)를 제공합니다. STL을 사용하면 복잡한 데이터 구조와 알고리즘을 쉽게 구현할 수 있습니다.

#### 1. STL의 주요 구성 요소

STL은 세 가지 주요 구성 요소로 이루어져 있습니다:

1. **컨테이너(Container)**: 데이터를 저장하고 관리하는 구조입니다.
2. **알고리즘(Algorithm)**: 데이터를 처리하는 함수들입니다.
3. **반복자(Iterator)**: 컨테이너의 요소를 순회할 수 있는 객체입니다.

#### 2. 컨테이너(Container)

컨테이너는 데이터를 저장하는 구조입니다. 주요 컨테이너로는 `vector`, `list`, `deque`, `set`, `map` 등이 있습니다. 각 컨테이너는 다른 특성과 성능을 제공합니다.

##### 벡터(vector)

`vector`는 동적 배열을 제공하는 컨테이너입니다. 크기가 동적으로 변경되며, 임의 접근이 가능합니다.

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // 요소 출력
    for (int n : numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    // 요소 추가
    numbers.push_back(6);

    // 요소 출력
    for (int n : numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

##### 리스트(list)

`list`는 이중 연결 리스트를 제공하는 컨테이너입니다. 임의 접근은 불가능하지만, 삽입과 삭제가 빠릅니다.

```cpp
#include <iostream>
#include <list>

int main() {
    std::list<int> numbers = {1, 2, 3, 4, 5};

    // 요소 출력
    for (int n : numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    // 요소 추가
    numbers.push_back(6);

    // 요소 출력
    for (int n : numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

##### 맵(map)

`map`은 키-값 쌍을 저장하는 연관 컨테이너입니다. 키는 유일하며, 자동으로 정렬됩니다.

```cpp
#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> ageMap;

    // 요소 추가
    ageMap["Alice"] = 30;
    ageMap["Bob"] = 25;

    // 요소 출력
    for (const auto& entry : ageMap) {
        std::cout << entry.first << ": " << entry.second << std::endl;
    }

    return 0;
}
```

#### 3. 알고리즘(Algorithm)

STL은 다양한 알고리즘을 제공합니다. 주요 알고리즘으로는 `sort`, `find`, `copy`, `transform` 등이 있습니다.

##### 정렬(sort)

`sort` 알고리즘은 컨테이너의 요소를 정렬합니다.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {5, 2, 9, 1, 5, 6};

    // 정렬
    std::sort(numbers.begin(), numbers.end());

    // 요소 출력
    for (int n : numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

##### 찾기(find)

`find` 알고리즘은 컨테이너에서 특정 값을 찾습니다.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {5, 2, 9, 1, 5, 6};

    // 값 찾기
    auto it = std::find(numbers.begin(), numbers.end(), 9);

    if (it != numbers.end()) {
        std::cout << "Found: " << *it << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }

    return 0;
}
```

#### 4. 반복자(Iterator)

반복자는 컨테이너의 요소를 순회하는 객체입니다. 주요 반복자로는 입력 반복자(Input iterator), 출력 반복자(Output iterator), 전진 반복자(Forward iterator), 양방향 반복자(Bidirectional iterator), 임의 접근 반복자(Random access iterator)가 있습니다.

##### 벡터(vector)의 반복자 사용 예제

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // 반복자를 사용하여 요소 출력
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

### 요약

- **컨테이너(Container)**: 데이터를 저장하고 관리하는 구조입니다. 주요 컨테이너로는 `vector`, `list`, `map` 등이 있습니다.
- **알고리즘(Algorithm)**: 데이터를 처리하는 함수들입니다. 주요 알고리즘으로는 `sort`, `find` 등이 있습니다.
- **반복자(Iterator)**: 컨테이너의 요소를 순회할 수 있는 객체입니다.

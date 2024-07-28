#pragma once
#include <list>
#include <map>

#include "BaseExample.h"



class STLExample : public ExampleBase
{
protected:
    virtual string getTitle() const override
    {
        return "STLExample";
    }
    
    virtual void ChildRun() override
    {
        ExampleVector();
        ExampleList();
    }

private:
    void ExampleVector()
    {
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
    }

    void ExampleList()
    {
        list<int> numbers = {1, 2, 3, 4, 5};

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
    }

    void ExampleMap()
    {
        map<std::string, int> ageMap;

        // 요소 추가
        ageMap["Alice"] = 30;
        ageMap["Bob"] = 25;

        // 요소 출력
        for (const auto& entry : ageMap) {
            std::cout << entry.first << ": " << entry.second << std::endl;
        }
    }

    void ExampleAlgorithm()
    {
        std::vector<int> numbers = {5, 2, 9, 1, 5, 6};

        // 정렬
        std::sort(numbers.begin(), numbers.end());

        // 요소 출력
        for (int n : numbers) {
            std::cout << n << " ";
        }
        std::cout << std::endl;

        // 값 찾기
        auto it = std::find(numbers.begin(), numbers.end(), 9);

        if (it != numbers.end()) {
            std::cout << "Found: " << *it << std::endl;
        } else {
            std::cout << "Not found" << std::endl;
        }
    }

    void ExampleIterator()
    {
        std::vector<int> numbers = {1, 2, 3, 4, 5};

        // 반복자를 사용하여 요소 출력
        for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
};


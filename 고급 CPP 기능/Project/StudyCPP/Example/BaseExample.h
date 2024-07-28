#pragma once

#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class ExampleBase
{
public:
    virtual ~ExampleBase() = default;
    void Run()
    {
        cout << "================================" << endl;
        cout << getTitle() << endl;
        cout << "================================" << endl;
        ChildRun();
        cout << endl << endl;
    }

protected:
    virtual string getTitle() const = 0 ;
    virtual void ChildRun() = 0;
};

using ExamplePtr = std::shared_ptr<ExampleBase>;
using ExampleList = std::vector<ExamplePtr>;
using FactoryFunction = function<unique_ptr<ExampleBase>()>;

struct FactoryEntry
{
    FactoryFunction factory;
    int order;

    bool operator<(const FactoryEntry& other) const
    {
        return order < other.order;
    }
};

class Registry
{
public:
    static Registry& instance()
    {
        static Registry instance;
        return instance;
    }

    void registerFactory(const FactoryFunction& factory, int order)
    {
        factories.push_back({factory, order});
    }

    vector<unique_ptr<ExampleBase>> createAll()
    {
        std::sort(factories.begin(), factories.end());
        vector<unique_ptr<ExampleBase>> instances;
        for (const auto& entry : factories)
        {
            instances.push_back(entry.factory());
        }
        return instances;
    }
    
private:
    vector<FactoryEntry> factories;
    
};

class Registar
{
public:
    Registar(const FactoryFunction& factory, int order)
    {
        Registry::instance().registerFactory(factory, order);
    }
};

#define REGISTER_CLASS(CLASS_NAME, ORDER) \
    namespace { \
        Registar registrar_##CLASS_NAME([](){ return std::make_unique<CLASS_NAME>(); }, ORDER); \
    }
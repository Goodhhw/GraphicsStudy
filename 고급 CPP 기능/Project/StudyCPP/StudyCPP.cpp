#include "Example/BaseExample.h"
#include "Example/DataStructureExample.h"
#include "Example/STLExample.h"
#include "Example/TemplateExample.h"

REGISTER_CLASS(TemplateExample, 1)
REGISTER_CLASS(STLExample, 2)
REGISTER_CLASS(DataStructureExample, 3)

static void RunExample()
{
    auto instances = Registry::instance().createAll();
    for (const auto& instance : instances)
    {
        instance->Run();
    }
}

int main(int argc, char* argv[])
{
    RunExample();
    
    return 0;
}

#include <cstdlib>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m) 
{
    set <string> MapValuesSet;
    
    for (const auto& i: m)
    {
        MapValuesSet.insert(i.second);
    }
    
    return MapValuesSet;
}

int main(int argc, char** argv) 
{
    set<string> values = BuildMapValuesSet({
        {1, "odd"},
        {2, "even"},
        {3, "odd"},
        {4, "even"},
        {5, "odd"}
    });

    for (const string& value : values) {
        cout << value << endl;
    }

    return 0;
}


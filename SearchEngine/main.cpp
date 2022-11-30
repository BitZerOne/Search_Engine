#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using std::cin;
using std::cout;
using std::endl;


int main()
{

    std::ifstream f("../example.json");
    json data;
    if(f.is_open())
    {
        data = json::parse(f);
        f.close();

    }
    else std::cerr << "file not fond" << endl;

    if(!data.empty())
    {
//        cout << data.dump(4) << endl;
        for (auto& el : data.items())
        {
            std::cout << "key: " << el.key() << ", value: " << el.value() << '\n';
        }
    }

    return 0;
}



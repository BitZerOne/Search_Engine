#include <iostream>
#include <vector>
#include <string>
#include "converterjson.h"
using std::cin;
using std::cout;
using std::endl;


int main()
{
    ConverterJSON cjs;

    std::vector<std::string> documents(cjs.GetTextDocuments());
    std::vector<std::string> reque(cjs.GetRequests());

    try {
        for(const auto & i : documents)
            cout << i << endl;

        cout << cjs.GetResponsesLimit() << endl;

        for(const auto & i : reque)
            cout << i << endl;

    }  catch (std::exception &e) {
        std::cerr << e.what() << "\n";
    }

    return 0;
}



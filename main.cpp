#include <iostream>

#include "factory.h"

bool isNumber(std::string str)
{
    for (char const& ch : str) {
        if (std::isdigit(ch) == 0)
            return false;
    }
    return true;
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            std::cout << "arg #" << i << " is " << argv[i] << std::endl;
            if (!isNumber(argv[i])) {
                std::cout << "Should enter only numbers!" << std::endl << std::endl;
                continue;
            }
            
            Transport* transport = Factory::createTransport(static_cast<TransportType>(atoi(argv[i])));
            std::cout << transport->getInfo() << std::endl;
        }
    }
    else {
        std::cout << "No args" << std::endl;
    }

    system("pause");
    return 0;
}

// g++ exercise.cpp -o exercise && ./exercise

#include <iostream>
#include <string>

int main(void)
{
    const std::string hello = "Hello";
    const std::string message = hello + ", world" + "!";

    const std::string exclam = "!";
    // const std::string message2 = "Hello" + ", world" + exclam;

    //
    {
        const std::string s = "a string";
        std::cout << s << std::endl;
    }

    {
        const std::string s = "another string";
        std::cout << s << std::endl;
    }

    //
    {
        const std::string s = "a string";
        std::cout << s << std::endl;
        {
            const std::string s = "another string";
            std::cout << s << std::endl;
        }
    }

    {
        const std::string s = "a string";
        std::cout << s << std::endl;
        {
            const std::string s = "another string";
            std::cout << s << std::endl;
        };
    }

    //
    {
        std::string s = "a string";
        {
            std::string x = s + ", really";
            std::cout << s << std::endl;
        }
        std::cout << s << std::endl;
    }

    //
    {
        std::cout << "What is your name? ";
        std::string name;
        std::cin >> name;
        std::cout << "Hello, " << name
                  << std::endl
                  << "And what is yours? ";
        std::cin >> name;
        std::cout << "Hello, " << name
                  << "; nice to meet you too!" << std::endl;
    }

    return 0;
}
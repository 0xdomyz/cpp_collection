// g++ valid_brackets.cpp -o valid_brackets && ./valid_brackets

#include <iostream>
int main()
{
    {
        {
            {
                {
                    {
                        std::cout << "Hello, world!" << std::endl;
                    }
                }
            }
        }
    }
}
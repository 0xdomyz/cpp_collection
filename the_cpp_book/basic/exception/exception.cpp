// g++ exception.cpp -o exception -std=c++11 && ./exception

#include <iostream>
#include <string>

using namespace std;

struct Some_error
{
    /* data */
    string msg;
};

int do_task()
{
    // ...
    int result{2};
    if (/* could perfor m the task */ result == 1)
        return result;
    else
        throw Some_error{};
}

void taskmaster()
{
    try
    {
        auto result = do_task();
        // use result
        cout << "Result: " << result << endl;
    }
    catch (Some_error)
    {
        // failure to do_task: handle problem
        cout << "Some error" << endl;
    }
}

int main()
{
    taskmaster();
}

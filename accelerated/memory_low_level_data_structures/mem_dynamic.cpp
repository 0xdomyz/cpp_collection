// g++ mem_dynamic.cpp -o mem_dynamic && ./mem_dynamic

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int *pointer_to_dynamic()
{
    return new int(0);
}

char *duplicate_chars(const char *p)
{
    // allocate enough space; remember to add one for the null
    size_t length = strlen(p) + 1;
    char *result = new char[length];
    // copy into our newly allocated space and return pointer to first element
    copy(p, p + length, result);
    return result;
}

int main()
{
    int *p = new int(42);
    ++*p; // p is now 43
    delete p;

    int *q = pointer_to_dynamic();
    delete q;

    // array
    {
        int n = 0;
        // T be alias of int
        typedef int T;

        T *p = new T[n];
        vector<T> v(p, p + n);
        delete[] p;
    }

    {
        const char *p = "Hello";
        char *q = duplicate_chars(p);
        cout << q << endl;
        delete[] q;
    }
}
// g++ -std=c++11 -o composition_and_selection composition_and_selection.cpp

namespace His_lib
{
    class String
    { /* ... */
    };
    template <class T>
    class Vector
    { /* ... */
    };
    // ...
}
namespace Her_lib
{
    template <class T>
    class Vector
    { /* ... */
    };
    class String
    { /* ... */
    };
    // ...
}
namespace My_lib
{
    using namespace His_lib; // everything from His_lib
    using namespace Her_lib; // everything from Her_lib
    using Her_lib::Vector;   // resolve potential clash in favor of Her_lib
    using His_lib::String;   // resolve potential clash in favor of His_lib
    template <class T>
    class List
    {  /* ... */
    }; // additional stuff
    // ...
}

namespace Lib2
{
    using namespace His_lib; // everything from His_lib
    using namespace Her_lib; // everything from Her_lib

    using Her_lib::Vector; // resolve potential clash in favor of Her_lib
    using His_lib::String; // resolve potential clash in favor of His_lib

    using Her_string = Her_lib::String; // rename
    template <class T>
    using His_vec = His_lib::Vector<T>; // rename

    template <class T>
    class List
    {  /* ... */
    }; // additional stuff
    // ...
}

using namespace Lib2;

int main(void) {}
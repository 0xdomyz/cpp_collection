// Compile and run: g++ base_initializers.cpp -o base_initializers && ./base_initializers

class B1
{
public:
    B1();
}; // has default constructor

class B2
{
public:
    B2(int);
} // no default constructor
;
struct D1 : B1,
            B2
{
public:
    D1(int i) : B1{}, B2{i} {}
};

struct D2 : B1, B2
{
public:
    D2(int i) : B2{i} {} // B1{} is used implicitly
};

// struct D1 : B1, B2
// {
// public:
//     // D1(int i) {} // error : B2 requires an int initializer
// };

int main()
{
    // D1 d1{1};
    // D2 d2{1};
    return 0;
}
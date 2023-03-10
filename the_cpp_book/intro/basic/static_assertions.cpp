// g++ static_assertions.cpp -std=c++11 -o static_assertions && ./static_assertions

constexpr double C = 299792.458; // km/s
void f(double speed)
{
    constexpr double local_max = 160.0 / (60 * 60); // 160 km/h == 160.0/(60*60) km/s

    // error : speed must be a constant
    // static_assert(speed < C, "can't go that fast");

    static_assert(local_max < C, "can't go that fast"); // OK
    // ...
}

static_assert(4 <= sizeof(int), "integers are too small"); // check integer size

int main()
{
    f(0.1);
}
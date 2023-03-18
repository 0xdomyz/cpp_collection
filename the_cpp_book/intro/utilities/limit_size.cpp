// compile and run: g++ -o limit_size limit_size.cpp && ./limit_size

#include <iostream>
#include <limits>

using namespace std;

int main(void)
{
    constexpr float min = numeric_limits<float>::min(); // smallest positive float (§40.2)
    constexpr float max = numeric_limits<float>::max(); // largest positive float (§40.2)
    constexpr int szi = sizeof(int);                    // the number of bytes in an int
    constexpr int szf = sizeof(float);                  // the number of bytes in a float
    cout << "min: " << min << " szi: " << szi << " szf: " << szf << endl;
    cout << "max: " << max << " szi: " << szi << " szf: " << szf << endl;
}

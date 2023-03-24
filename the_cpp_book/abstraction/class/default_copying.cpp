// Compile and run: g++ default_copying.cpp -o default_copying && ./default_copying

struct Date
{
    int d, m, y;
};

Date my_birthday;

Date d1 = my_birthday; // initialization by copy
Date d2{my_birthday};  // initialization by copy

void f(Date &d)
{
    d = my_birthday;
}

int main(void)
{
    f(my_birthday);
}
// Compile and run: g++ in_class_initializer.cpp -o in_class_initializer && ./in_class_initializer

class Date
{
    int d{1};
    int m{2};
    int y{1991};

public:
    Date(int, int, int); // day, month, year
    Date(int, int);      // day, month, today’s year
    Date(int);           // day, today’s month and year
    Date();              // default Date: today
    Date(const char *);  // date in string representatio
};

Date::Date(int dd)
    : d{dd}
{
    // check that the Date is valid
}

int main(void)
{
    return 0;
}
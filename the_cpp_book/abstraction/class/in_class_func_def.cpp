// Compile and run: g++ in_class_func_def.cpp -o in_class_func_def && ./in_class_func_def

class Date
{
public:
    void add_month(int n) { m += n; } // increment the Date’s m
    // ...
private:
    int d, m, y;
};
// inline void Date::add_month(int n) // add n months
// {
//     m += n; // increment the Date’s m
// }

int main(void)
{
    return 0;
}
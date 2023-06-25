// g++ -o off_the_end off_the_end.cpp && ./off_the_end

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int *begin = a;
    int *end = a + 5;

    // invariant: we must still process the elements in the range [begin, end)
    while (begin != end)
    {
        // do something with the element to which begin refers
        *begin;
        ++begin;
    }
}

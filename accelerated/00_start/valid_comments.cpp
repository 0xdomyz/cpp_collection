// g++ valid_comments.cpp -o valid_comments && ./valid_comments

#include <iostream>
int main()
{
    // /* This is a comment that extends over several lines
    // because it uses /* and */
    // as its starting and ending delimiters * /

    // This is a comment that extends over several lines
    // by using // at the beginning of each line instead of using /*
    // or */ to delimit comments.
    std::cout
        << "Does this work?" << std::endl;
    return 0;
}

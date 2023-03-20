// g++ namespace.cpp -o namespace && ./namespace

namespace Graph_lib
{
    class Shape
    { /* ... */
    };
    class Line : public Shape
    { /* ... */
    };
    class Poly_line : public Shape
    {  /* ... */
    }; // connected sequence of lines
    class Text : public Shape
    {  /* ... */
    }; // text label
    class Graph_reader
    {                                              /* ... */
    };                                             // read Shapes from a file
    Shape operator+(const Shape &, const Shape &); // compose
    Graph_reader open(const char *);               // open file of Shapes
}

namespace Text_lib
{
    class Glyph
    { /* ... */
    };
    class Word
    {  /* ... */
    }; // sequence of Glyphs
    class Line
    {  /* ... */
    }; // sequence of Words
    class Text
    {  /* ... */
    }; // sequence of Lines
    class File
    {                                           /* ... */
    };                                          // text file
    File *open(const char *);                   // open text file
    Word operator+(const Line &, const Line &); // concatenate
}

class Glyph
{ /* ... */
};
class Line
{ /* ... */
};

int main(void)
{
    Glyph glyph(Line & ln, int i);                     // ln[i]
    Text_lib::Glyph glyph(Text_lib::Line & ln, int i); // ln[i]
}
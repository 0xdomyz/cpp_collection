#include <SFML/Graphics.hpp>
using namespace sf;

int N = 30, M = 20;
int size = 16;
int w = size * N;
int h = size * M;

int main()
{

    RenderWindow window(VideoMode(w, h), "Snake Game!");

    Texture t1, t2;
    t1.loadFromFile("images/white.png");
    t2.loadFromFile("images/red.png");

    Sprite sprite1(t1);
    Sprite sprite2(t2);

    while (window.isOpen())
    {

        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window.close();
        }

        ////// draw  ///////
        window.clear();

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                sprite1.setPosition(i * size, j * size);
                window.draw(sprite1);
            }

        window.display();
    }

    return 0;
}

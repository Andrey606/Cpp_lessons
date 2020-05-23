// structure.cpp
// круги в качестве обьектов

#include <iostream>
#include <clocale> // для коректного отображения русских символов
#include "msoftcon.h" // для функции консольной графики
using namespace std;

class circle          // определение класса
{
    protected:
        int xCo, yCo;
        int radius;
        color fillcolor;
        fstyle fillstyle;
    public:
        void set(int x, int y, int r, color fc, fstyle fs)
        {
            xCo = x;
            yCo = y;
            radius = r;
            fillcolor = fc;
            fillstyle = fs;
        }
        void draw()
        {
            set_color(fillcolor);
            set_fill_style(fillstyle);
            draw_circle(xCo, yCo, radius);
        }
};


int main()
{
    setlocale(LC_CTYPE, "rus"); // вызов функции настройки локали

    init_graphics(); // инициилизация графики
    circle c1;
    circle c2;
    circle c3;

    // установка атрибутов кругов
    c1.set(15, 7, 5, cBLUE, X_FILL);
    c2.set(41, 12, 7, cRED, O_FILL);
    c3.set(65, 18, 4, cGREEN, MEDIUM_FILL);

    c1.draw();
    c2.draw();
    c3.draw();

    set_cursor_pos(1, 25); // нижний левый угол

    return 0;
}

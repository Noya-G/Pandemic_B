#include "GeneSplicer.hpp"

namespace pandemic{
    Player& GeneSplicer::discover_cure(const Color &color)
    {
        board.color_madication[color]=true;
        for (int i = 0; i < 48; i++)
        {
            if (board.City_color[City(i)]==color)
            {
                board.City_diseas_level[City(i)]=0;
            }
        }
    }
}
#pragma once
#include <iostream>
#include <map>
#include <set>
#include <list>
#include "City.hpp"
#include "Color.hpp"

namespace pandemic{
    
    class Board{

        private:
        friend class pandemic::Player;
        static std::map<City,std::set<City>> City_map;
        static std::map<City,Color> City_color;
        std::map<Color,bool> color_madication;
        std::map<City, int> City_diseas_level;
        std::map<City, int> reaserch_station;

        public:
            Board();
            ~Board();
            int& operator[](const City &city);
            friend std::ostream &operator<<(std::ostream &out, const Board &board);
            void read_cities();
            void remove_cures();
            bool is_clean();
            
    };
}

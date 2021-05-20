
#include "Player.hpp"


namespace pandemic{
    class GeneSplicer: public Player
    {
        private:
        Board board;
        City city;
        public:
        using Player::Player;
        Player& discover_cure(const Color &color) override;
        inline GeneSplicer(Board board, City city):Player(board,city,"GeneSplicer"){}
    };
}
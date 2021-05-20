#include "doctest.h"

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

#include <iostream>
#include <ctime>

using namespace std;
using namespace pandemic;

/**
 * @ganarate random city card.
 * 
 * @return City& 
 */
int City_Genarator()
{
    srand((unsigned)time(NULL));
    int random_city = (rand()%48);
    return random_city;
}

/**
 * @ganarate random disease cubes.
 * 
 * @return City& 
 */
int disease_cubes_Genarator()
{
    srand((unsigned)time(NULL));
    int random_city = rand()%5;
    return random_city;
}

//Done
TEST_CASE("Board Tests")
{
    Board board;  // Initialize an empty board (with 0 disease cubes in any city).
    CHECK(board.is_clean());          //check if the board is clean.
	board[City::Kinshasa] = 3;      // put 3 yellow disease cubes in Kinshasa.
    CHECK_EQ(board[City::Kinshasa],3); //check that ther are 3 yellow disease cubes in Kinshasa.
	board[City::Kinshasa] = 2;      // change number of disease cubes in Kinshasa to 2.
    CHECK_EQ(board[City::Kinshasa],2); //check that ther are 2 yellow disease cubes in Kinshasa.
	board[City::MexicoCity] = 3;    // put 3 yellow disease cubes in MexicoCity
    CHECK_EQ(board[City::MexicoCity],3); //check that ther are 3 yellow disease cubes in MexicoCity.
	board[City::HoChiMinhCity] = 1; // put 1 red disease cube in HoChiMinhCity
    CHECK_EQ(board[City::HoChiMinhCity],1); //check that ther are 1 red disease cubes in HoChiMinhCity.
	board[City::Chicago] = 1;       // put 1 blue disease cube in Chicago
    CHECK_EQ(board[City::Chicago],1); //check that ther are 1 blue disease cubes in Chicago.

    Board board2;
    /** 
     * check all the city disease cubes. 
     **/
    for (int i = 0; i < 48; i++)
    {
        int disease_cubes = disease_cubes_Genarator();
        board2[(City)i] = disease_cubes;
        CHECK_EQ(board[(City)i],disease_cubes);
    }
}

//Done
TEST_CASE("Fly Shuttel Tests")
{
    //NOTE: fligt shuttel cannot be made without reaserch station in both station
    
    Board board;  // Initialize an empty board (with 0 disease cubes in any city).
	
    //place the player on the board:
    OperationsExpert operations_expert(board, City::Madrid);
    Dispatcher dispatcher(board, City::Madrid);
    GeneSplicer gene_splicer(board, City::Madrid);
    Medic medic(board, City::SanFrancisco);
    Virologist virologist(board, City::Madrid);

    //  cfligt shuttel cannot be made without reaserch station in both station
    for (int i = 0; i < 10; i++)
    {
        CHECK_THROWS(operations_expert.fly_shuttle((City)City_Genarator()));
        CHECK_THROWS(dispatcher.fly_shuttle((City)City_Genarator()));
        CHECK_THROWS(gene_splicer.fly_shuttle((City)City_Genarator()));
        CHECK_THROWS(medic.fly_shuttle((City)City_Genarator()));
        CHECK_THROWS(virologist.fly_shuttle((City)City_Genarator()));
    }

    // Operations expert now builds a research station in Madrid, flies to Paris and build one there too. 
    // Shuttle flights from Madrid to Paris
    operations_expert.build();
    operations_expert.take_card(City::Paris);
    operations_expert.build();

    CHECK_NOTHROW(operations_expert.fly_shuttle(City::Paris));
    CHECK(operations_expert.get_city() == City::Paris);
    CHECK_NOTHROW(operations_expert.fly_shuttle(City::Madrid));
    CHECK(operations_expert.get_city() == City::Madrid);

    CHECK_NOTHROW(dispatcher.fly_shuttle(City::Paris));
    CHECK(dispatcher.get_city() == City::Paris);
    CHECK_NOTHROW(dispatcher.fly_shuttle(City::Madrid));
    CHECK(dispatcher.get_city() == City::Madrid);

    CHECK_NOTHROW(gene_splicer.fly_shuttle(City::Paris));
    CHECK(gene_splicer.get_city() == City::Paris);
    CHECK_NOTHROW(gene_splicer.fly_shuttle(City::Madrid));
    CHECK(gene_splicer.get_city() == City::Madrid);

    CHECK_NOTHROW(medic.fly_shuttle(City::Paris));
    CHECK(medic.get_city() == City::Paris);
    CHECK_NOTHROW(medic.fly_shuttle(City::Madrid));
    CHECK(medic.get_city() == City::Madrid);
    
    CHECK_NOTHROW(virologist.fly_shuttle(City::Paris));
    CHECK(virologist.get_city() == City::Paris);
    CHECK_NOTHROW(virologist.fly_shuttle(City::Madrid));
    CHECK(virologist.get_city() == City::Madrid);
}

//Done
TEST_CASE("Fly Direct Tests")
{
    //NOTE: cannot have direct flieght without cards and without research stations built in both cities.
    Board board;  // Initialize an empty board (with 0 disease cubes in any city).
	
    //place the player on the board:
    OperationsExpert operations_expert(board, City::Madrid);
    Dispatcher dispatcher(board, City::NewYork);
    GeneSplicer gene_splicer(board, City::Paris);
    Medic medic(board, City::SanFrancisco);
    Virologist virologist(board, City::Tokyo);
    
    //  cannot have direct flieght without cards and without research stations built in both cities
    for (int i = 0; i < 10; i++)
    {
        CHECK_THROWS(operations_expert.fly_direct((City)City_Genarator()));
        CHECK_THROWS(dispatcher.fly_direct((City)City_Genarator()));
        CHECK_THROWS(gene_splicer.fly_direct((City)City_Genarator()));
        CHECK_THROWS(medic.fly_direct((City)City_Genarator()));
        CHECK_THROWS(virologist.fly_direct((City)City_Genarator()));
    }

    //the players takes cards:
    operations_expert.take_card(City::NewYork);
    dispatcher.take_card(City::Tokyo);
    gene_splicer.take_card(City::Sydney);
    medic.take_card(City::Taipei);
    virologist.take_card(City::Seoul);

    operations_expert.build();

    City city1 = (City)City_Genarator();
    dispatcher.fly_direct(city1);
    CHECK(dispatcher.get_city() == city1);

    City city2 = (City)City_Genarator();
    gene_splicer.fly_direct(city2);
    CHECK(gene_splicer.get_city() == city2);

    City city3 = (City)City_Genarator();
    medic.fly_direct(city3);
    CHECK(medic.get_city() == city3);
    
    City city4 = (City)City_Genarator();
    virologist.fly_direct(city4);
    CHECK(virologist.get_city() == city4);
}

//Done
TEST_CASE("Take Cards")
{
    Board board0;
    Player player0(board0, (City)City_Genarator());
    for (int i = 0; i < 10; i++)
    {
        player0.take_card((City)City_Genarator());
    }
    CHECK_EQ(player0.num_of_cards(), 10);

    Board board1;
    Player player1(board1, (City)City_Genarator());
    for (int i = 0; i < 48; i++)
    {
        player1.take_card((City)City_Genarator());
    }
    //trying to take cards when ther no longer avalibals cards
    CHECK_THROWS(player1.take_card((City)City_Genarator()));

}


//Done
TEST_CASE("Drive Tests")
{
    Board board;  // Initialize an empty board (with 0 disease cubes in any city).
	Player player1(board, City::NewYork);
    CHECK_NOTHROW(player1.drive(City::London));
    CHECK_EQ(player1.get_city(),City::London);
    CHECK_NOTHROW(player1.drive(City::Paris));
    CHECK_EQ(player1.get_city(),City::Paris);
    CHECK_NOTHROW(player1.drive(City::Madrid));
    CHECK_EQ(player1.get_city(),City::Madrid);
    CHECK_NOTHROW(player1.drive(City::NewYork));
    CHECK_EQ(player1.get_city(),City::NewYork);
    CHECK_NOTHROW(player1.drive(City::Washington));
    CHECK_EQ(player1.get_city(),City::Washington);
    CHECK_NOTHROW(player1.drive(City::Atlanta));
    CHECK_EQ(player1.get_city(),City::Atlanta);
    CHECK_NOTHROW(player1.drive(City::Miami));
    CHECK_EQ(player1.get_city(),City::Miami);
    CHECK_NOTHROW(player1.drive(City::Bogota));
    CHECK_EQ(player1.get_city(),City::Bogota);
    CHECK_NOTHROW(player1.drive(City::Lima));
    CHECK_EQ(player1.get_city(),City::Lima);
    CHECK_THROWS(player1.drive(City::NewYork));
    CHECK_THROWS(player1.drive(City::Jakarta));
    CHECK_THROWS(player1.drive(City::Tokyo));

}



TEST_CASE("Treats Tests")
{
    Board board;  // Initialize an empty board (with 0 disease cubes in any city).
	board[City::Kinshasa] = 3;      // put 3 yellow disease cubes in Kinshasa.
	board[City::Kinshasa] = 2;      // change number of disease cubes in Kinshasa to 2.
	board[City::MexicoCity] = 3;    // put 3 yellow disease cubes in MexicoCity
	board[City::HoChiMinhCity] = 1; // put 1 red disease cube in HoChiMinhCity
	board[City::Chicago] = 1;       // put 1 blue disease cube in Chicago

}

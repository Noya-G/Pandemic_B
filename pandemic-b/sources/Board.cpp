#include <iostream>
#include "Board.hpp"


namespace pandemic{
    Board::Board(){

        //initilizing color_madication map:
            for (int i = 0; i < 4; i++)
            {
                color_madication.insert(std::make_pair(Color(i),false));
            }

        //initilizing City_diseas_level and reaserch_station maps:
        for (int i = 0; i < 48; i++)
        {
            City_diseas_level.insert(std::make_pair(City(i),0));
            reaserch_station.insert(std::make_pair(City(i),0));
        }

    }

    Board::~Board(){}
    int& Board::operator[](const City &city){ 
        int *pointer = new int(0);
        return *pointer;
    }

    std::ostream &operator<<(std::ostream &out, const Board &board)
    { 

        // for (int i=0; i<48; i++)
        // {
        //     Color color = Board::City_color[City(i)];
        //     if (true == Board::color_madication[City(i)])
        //     {
        //         out<<City(i)<<" ,color: "<<Color(color)<<", reaserch station: "<<
        //         Board::reaserch_station[City(i)]<<", cured\n"<<std::endl;
        //     }
        //     else
        //     {
        //         out<<City(i)<" ,color: "<<Color(color)<<", reaserch station: "<<
        //         Board::reaserch_station[City(i)]<<", diseas level:"<<Board::City_diseas_level[City(i)]<<std::endl;
        //     }
        //     return out;
        // }
        
        return out; 
    }
    
    //not finished
    void Board::read_cities()
    {

    }
    
    bool Board::is_clean()
    { 
        for (int i = 0; i < 48; i++)
        {
            if (City_diseas_level[City(i)]!=0 || reaserch_station[City(i)]!=0)
            {
                return false;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            if (Board::color_madication[Color(i)]==true)
            {
                return false;
            }
            
        }
        
        return true; 
    }
    
    void Board::remove_cures()
    {
        for (int i = 0; i < 4; i++)
        {
            color_madication[Color(i)]=false;
        }
    }
   

    std::map<City,Color> Board::City_color={{City::Algiers,Color::Black},
                        {City::Madrid,Color::Black},
                        {City::Paris,Color::Blue},
                        {City::Istanbul,Color::Black},
                        {City::Cairo,Color::Black},
                        {City::Atlanta,Color::Blue},
                        {City::Chicago,Color::Blue},
                        {City::Miami,Color::Blue},
                        {City::Washington,Color::Blue},
                        {City::Baghdad,Color::Black},
                        {City::Tehran,Color::Black},
                        {City::Riyadh,Color::Black},
                        {City::Karachi,Color::Black},
                        {City::Bangkok,Color::Red},
                        {City::Kolkata,Color::Black},
                        {City::Chennai,Color::Black},
                        {City::Jakarta,Color::Black},
                        {City::HoChiMinhCity,Color::Red},
                        {City::HongKong,Color::Red},
                        {City::Beijing,Color::Red},
                        {City::Shanghai,Color::Red},
                        {City::Seoul,Color::Red},
                        {City::Bogota,Color::Yellow},
                        {City::MexicoCity,Color::Blue},
                        {City::Lima,Color::Yellow},
                        {City::Mumbai,Color::Black},
                        {City::SaoPaulo,Color::Yellow},
                        {City::BuenosAires,Color::Yellow},
                        {City::Khartoum,Color::Red},
                        {City::Delhi,Color::Black},
                        {City::Essen,Color::Blue},
                        {City::London,Color::Blue},
                        {City::Milan,Color::Blue},
                        {City::StPetersburg,Color::Blue},
                        {City::Manila,Color::Red},
                        {City::Taipei,Color::Red},
                        {City::Moscow,Color::Black},
                        {City::Sydney,Color::Red},
                        {City::Johannesburg,Color::Yellow},
                        {City::Kinshasa,Color::Red},
                        {City::Lagos,Color::Red},
                        {City::NewYork,Color::Blue},
                        {City::Santiago,Color::Yellow},
                        {City::Montreal,Color::Blue},
                        {City::Osaka,Color::Red},
                        {City::Tokyo,Color::Red},
                        {City::LosAngeles,Color::Blue},
                        {City::SanFrancisco,Color::Blue}
                        };

    std::map<City,std::set<City>> Board::City_map{
        { City::Algiers, {City::Madrid, City::Paris, City::Istanbul, City::Cairo } },
        { City::Atlanta, {City::Chicago, City::Miami, City::Washington } },
        { City::Baghdad, {City::Tehran, City::Istanbul, City::Cairo, City::Riyadh, City::Karachi } },
        { City::Bangkok, {City::Kolkata, City::Chennai, City::Jakarta, City::HoChiMinhCity, City::HongKong } },
        { City::Beijing, {City::Shanghai, City::Seoul } },
        { City::Bogota, {City::MexicoCity, City::Lima, City::Miami, City::SaoPaulo, City::BuenosAires } },
        { City::BuenosAires, {City::Bogota, City::SaoPaulo } },
        { City::Cairo, {City::Algiers, City::Istanbul, City::Baghdad, City::Khartoum, City::Riyadh } },
        { City::Chennai, {City::Mumbai, City::Delhi, City::Kolkata, City::Bangkok, City::Jakarta } },
        { City::Chicago, {City::SanFrancisco, City::LosAngeles, City::MexicoCity, City::Atlanta, City::Montreal } },
        { City::Delhi, {City::Tehran, City::Karachi, City::Mumbai, City::Chennai, City::Kolkata } },
        { City::Essen, {City::London, City::Paris, City::Milan, City::StPetersburg } },
        { City::HoChiMinhCity, {City::Jakarta, City::Bangkok, City::HongKong, City::Manila } },
        { City::HongKong, {City::Bangkok, City::Kolkata, City::HoChiMinhCity, City::Shanghai, City::Manila, City::Taipei } },
        { City::Istanbul, {City::Milan, City::Algiers, City::StPetersburg, City::Cairo, City::Baghdad, City::Moscow } },
        { City::Jakarta, {City::Chennai, City::Bangkok, City::HoChiMinhCity, City::Sydney } },
        { City::Johannesburg, {City::Kinshasa, City::Khartoum } },
        { City::Karachi, {City::Tehran, City::Baghdad, City::Riyadh, City::Mumbai, City::Delhi } },
        { City::Khartoum, {City::Cairo, City::Lagos, City::Kinshasa, City::Johannesburg } },
        { City::Kinshasa, {City::Lagos, City::Khartoum, City::Johannesburg } },
        { City::Kolkata, {City::Delhi, City::Chennai, City::Bangkok, City::HongKong } },
        { City::Lagos, {City::SaoPaulo, City::Khartoum, City::Kinshasa } },
        { City::Lima, {City::MexicoCity, City::Bogota, City::Santiago } },
        { City::London, {City::NewYork, City::Madrid, City::Essen, City::Paris } },
        { City::LosAngeles, {City::SanFrancisco, City::Chicago, City::MexicoCity, City::Sydney } },
        { City::Madrid, {City::London, City::NewYork, City::Paris, City::SaoPaulo, City::Algiers } },
        { City::Manila, {City::Taipei, City::SanFrancisco, City::HoChiMinhCity, City::Sydney, City::HongKong } },
        { City::MexicoCity, {City::LosAngeles, City::Chicago, City::Miami, City::Lima, City::Bogota } },
        { City::Miami, {City::Atlanta, City::MexicoCity, City::Washington, City::Bogota } },
        { City::Milan, {City::Essen, City::Paris, City::Istanbul } },
        { City::Montreal, {City::Chicago, City::Washington, City::NewYork } },
        { City::Moscow, {City::StPetersburg, City::Istanbul, City::Tehran } },
        { City::Mumbai, {City::Karachi, City::Delhi, City::Chennai } },
        { City::NewYork, {City::Montreal, City::Washington, City::London, City::Madrid } },
        { City::Osaka, {City::Taipei, City::Tokyo } },
        { City::Paris, {City::Algiers, City::Essen, City::Madrid, City::Milan, City::London } },
        { City::Riyadh, {City::Baghdad, City::Cairo, City::Karachi } },
        { City::SanFrancisco, {City::LosAngeles, City::Chicago, City::Tokyo, City::Manila } },
        { City::Santiago, {City::Lima } },
        { City::SaoPaulo, {City::Bogota, City::BuenosAires, City::Lagos, City::Madrid } },
        { City::Seoul, {City::Beijing, City::Shanghai, City::Tokyo } },
        { City::Shanghai, {City::Beijing, City::HongKong, City::Taipei, City::Seoul, City::Tokyo } },
        { City::StPetersburg, {City::Essen, City::Istanbul, City::Moscow } },
        { City::Sydney, {City::Jakarta, City::Manila, City::LosAngeles } },
        { City::Taipei, {City::Shanghai, City::HongKong, City::Osaka, City::Manila } },
        { City::Tehran, {City::Baghdad, City::Moscow, City::Karachi, City::Delhi } },
        { City::Tokyo, {City::Seoul, City::Shanghai, City::Osaka, City::SanFrancisco } },
        { City::Washington, {City::Atlanta, City::NewYork, City::Montreal, City::Miami } }
    };
}




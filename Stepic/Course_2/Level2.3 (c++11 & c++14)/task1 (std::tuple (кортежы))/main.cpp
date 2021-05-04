#include <iostream>
#include <tuple>

// кортежи - std::tuple
// напоминает std::pair, но отличается тем что позволяет создавать не 2 значение а больше 


std::tuple<std::string, int, int> getUnitInfo(int id){
    if(id == 0) return std::make_tuple("Elf", 60, 9);
    if(id == 1) return std::make_tuple("Dwarf", 80, 6);
    if(id == 2) return std::make_tuple("Orc", 90, 3);

    return std::make_tuple("Undefined", 0, 0);
}

int main(int argc, const char * argv[]) 
{
    auto ui0 = getUnitInfo(0);
    std::cout   << "race: " << std::get<0>(ui0) << ", "
                << "hp: " << std::get<1>(ui0) << ", "
                << "iq: " << std::get<2>(ui0) << "\n";

    std::string race1; int hp1; int iq1;
    std::tie(race1, hp1, iq1) = getUnitInfo(1);
    std::cout   << "race: " << race1 << ", "
                << "hp: " << hp1 << ", "
                << "iq: " << iq1 << "\n";

    return 0;
}
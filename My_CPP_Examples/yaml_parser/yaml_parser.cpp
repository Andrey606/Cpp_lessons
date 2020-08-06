#include "yaml-cpp/yaml.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// our data types
struct Vec3 {
   float x, y, z;
};

struct Power {
   std::string name;
   int damage;
};

struct Monster {
   std::string name;
   Vec3 position;
   std::vector <Power> powers;
};
/*
// now the extraction operators for these types
void operator >> (YAML::Node& node, Vec3& v) {
    v.x = node[0];
    v.y = node[1];
    v.z = node[2];
}

void operator >> (YAML::Node& node, Power& power) {
    power.name = node["name"];
    power.damage = node["damage"];
}
*/

void operator >> (const YAML::Node& node, std::string name) {
    //std::cout << node["name"] << std::endl;
    //std::cout << typeid(node["name"]).name() << std::endl;
    //node["name"] >> monster.name;
    /*node["position"] >> monster.position;
    YAML::Node& powers = node["powers"];
    for(unsigned i=0;i<powers.size();i++) {
        Power power;
        powers[i] >> power;
        monster.powers.push_back(power);
    }*/
}

void operator >> (const YAML::Node& node, Monster& monster) {
    //std::cout << node["name"] << std::endl;
    //std::cout << typeid(node["name"]).name() << std::endl;
    node["name"] >> monster.name;
    /*node["position"] >> monster.position;
    YAML::Node& powers = node["powers"];
    for(unsigned i=0;i<powers.size();i++) {
        Power power;
        powers[i] >> power;
        monster.powers.push_back(power);
    }*/
}

int main()
{
    std::ifstream fin("monsters.yaml");
    YAML::Node doc = YAML::Load(fin);
    YAML::Node config = YAML::LoadFile("monsters.yaml");

    for(unsigned i=0;i<doc.size();i++) {
        Monster monster;
        doc[i] >> monster;
        //std::cout << monster.name << "\n";
    }

    return 0;
}
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
/*
class CMySingleton
{
public:
  static CMySingleton& Instance()
  {
    static CMySingleton singleton;
    return singleton;
  }

// Other non-static member functions
private:
  CMySingleton() {}                                  // Private constructor
  ~CMySingleton() {}
  CMySingleton(const CMySingleton&);                 // Prevent copy-construction
  CMySingleton& operator=(const CMySingleton&);      // Prevent assignment
};
*/

/*void CMySingleton::upload_immortal_devices(void)
{
    char file_path[50] = "./immortal_omo_devices.yaml";

    std::ifstream fin("./immortal_omo_devices.yaml");
    YAML::Node doc = YAML::Load(fin);

    if(doc.IsNull())
    {
        // ERROR opening yaml file
        exit(228);
    }

    for(unsigned i=0;i<doc.size();i++) 
    {
        std::cout << doc[i].Scalar() << std::endl;
    }
}*/

int main()
{
    /*std::ifstream fin("_immortal_omo_devices.yaml");
    YAML::Node doc = YAML::Load(fin);
    
    if(doc.IsNull())
    {
        std::cout << "doc.IsNull" << std::endl;
        exit(228);
    }

    std::string name;

    for(unsigned i=0;i<doc.size();i++) {
        name = doc[i].Scalar();
        std::cout << name << std::endl;
        //std::cout << monster.name << "\n";
    }*/

    //immortal_device& s = immortal_device::GetInstance(); 

    return 0;
}



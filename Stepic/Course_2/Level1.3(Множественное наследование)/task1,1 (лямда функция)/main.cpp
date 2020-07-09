/*
* Множественное наследование
*/
#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

using namespace std;

struct A
{
    A(){}
};

struct Cluster
{
    bool     _have_read;
    uint16_t cluster;
    uint16_t attribute;
} _Clustsders[3] = {   
    {false, 0x0006, 0x0000},  // on/off
    {false, 0x0008, 0x0000},  // bright
    {false, 0x0300, 0x0007},  // temp
};



//Make B inherit publicly (default) from A
struct B /*: A*/
{   
public:   
    int a;
    int b;

    enum class eCommands {NO_ACTION, ON, OFF, SET_COLOR, SET_TEMP, SET_BRIGHTNESS} command;

    //Cluster _Clusters[3];
    int c;

    B(int aa, int bb/*, function<Cluster(void)> f*/)
    {

        //cout << typeid(arr).name() << endl;
        //a = aa;
        //b = bb;

        for (size_t i = 0; i < 3; i++)
        {
            /*_Clusters[i].attribute = arr[i].attribute;
            _Clusters[i].cluster = arr[i].cluster;
            _Clusters[i]._have_read = arr[i]._have_read;*/
        }
    }

    B(bool cmd, bool evn, B::eCommands ecmd, int eevn, uint64_t timeAct, /*Cluster arr,*/ uint16_t brid, uint16_t temp, string state/*, _color carra*/, uint8_t count )
    {
    }
    /*B():a(), b(){}*/

} BObj = {false, false, B::eCommands::NO_ACTION, 0, 4200/*1h 10m*/, /*{
                                                                                                        {false, 0x0006, 0x0000},  // on/off
                                                                                                        {false, 0x0008, 0x0000},  // bright
                                                                                                        {false, 0x0300, 0x0007},  // temp
                                                                                                      }, */0, 0, "null", /*{0,0},*/ 0};

int main(int argc, const char * argv[]) {
    //B a = {};

    []() ->int { return 0; };

    Cluster isEven{
        [](void)
        {
            Cluster  arr[3] = {   
                        {false, 0x0006, 0x0000},  // on/off
                        {false, 0x0008, 0x0000},  // bright
                        {false, 0x0300, 0x0007},  // temp
                    };

            return arr;
        }
    };


    Cluster * (*addNumbers1)(void){
        [](void) {

            static Cluster  arr[3] = {   
                        {false, 0x0006, 0x0000},  // on/off
                        {false, 0x0008, 0x0000},  // bright
                        {false, 0x0300, 0x0007},  // temp
                    };

            return arr;
        }
    };

    cout << typeid(addNumbers1()[0]).name() << endl;
    Cluster *arr = addNumbers1();
    cout << arr[0].cluster << endl;
    

    return 0;
}


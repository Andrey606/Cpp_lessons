/*
* Множественное наследование
*/
#include <iostream>

using namespace std;


struct Unit {
    Unit (int id, int hp): id_(id), hp_(hp){cout << "Unit constructor!" << endl;}

    virtual int id() const { return id_; }
    virtual int hp() const { return hp_; }

private:
    int id_;
    int hp_;
};

struct Elf: public virtual Unit {
    Elf(int id, int hp): Unit (id, hp){cout << "Elf constructor!" << endl;}

    void elfMethod() { cout << "elfMethod!" << endl; }
};

struct Archer: public virtual Unit {
    Archer(int id, int hp): Unit (id, hp){cout << "Archer constructor!" << endl;}

    void archerMethod() { cout << "archerMethod!" << endl; }
};

struct ElfArcher: Elf, Archer {
    ElfArcher(int id, int hp): Unit (id, hp), Elf(id, hp), Archer(id, hp){}
};

Unit const * ElfBaseToArcherBase( Unit const * unit );

int main(int argc, const char * argv[]) {
    ElfArcher ElfArcherUnit(1, 100);

    cout << ElfArcherUnit.id() << endl;
    cout << ElfArcherUnit.hp() << endl;

    ElfArcherUnit.archerMethod();
    ElfArcherUnit.elfMethod();

    return 0;
}
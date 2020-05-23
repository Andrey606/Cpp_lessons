/*
* Множественное наследование
*/
#include <iostream>

using namespace std;


struct Unit {
    Unit (int id, int hp): id_(id), hp_(hp){}

    virtual int id() const { return id_; }
    virtual int hp() const { return hp_; }

private:
    int id_;
    int hp_;
};

struct Elf: Unit {
    Elf(int id, int hp): Unit (id, hp){}

    void elfMethod() { cout << "elfMethod!" << endl; }
};

struct Archer: Unit {
    Archer(int id, int hp): Unit (id, hp){}

    void archerMethod() { cout << "archerMethod!" << endl; }
};

struct ElfArcher: Elf, Archer {
    ElfArcher(int id, int hp): Elf (id+1, hp+1), Archer (id+1, hp+1){}

    int id() const { return Elf::id(); }
    int hp() const { return  Elf::hp(); }
};

Unit const * ElfBaseToArcherBase( Unit const * unit );

int main(int argc, const char * argv[]) {
    ElfArcher ElfArcherUnit(1, 10);

    cout << ElfArcherUnit.id() << endl;

    ElfArcherUnit.elfMethod();
    ElfArcherUnit.archerMethod();

    cout << "&ElfArcherUnit: " << &ElfArcherUnit << endl;

    Elf &ElfUnit = ElfArcherUnit;
    Archer &ArcherUnit = ElfArcherUnit;

    cout << "&ElfUnit: " << &ElfUnit << endl;
    cout << "&ArcherUnit: " << &ArcherUnit << endl;

    Unit &unitElf = ElfUnit;
    Unit &unitArch = ArcherUnit;

    cout << "&unitElf: " << &unitElf << endl;
    cout << "&unitArch: " << &unitArch << endl;

    ElfBaseToArcherBase(&unitElf);

    return 0;
}


// base указывает на экземпляр Base, соответствующий D1
// нужно вернуть указатель на экземпляр Base, соответствующий D2
Unit const * ElfBaseToArcherBase( Unit const * unit )
{

    const Elf *elfPtr =  static_cast<Elf const *>(unit);
    const ElfArcher *ElfArcherPtr =  static_cast<ElfArcher const *>(elfPtr);

    cout << "elfPtr: " << elfPtr  << endl;
    cout << "ElfArcherPtr: " << ElfArcherPtr  << endl;

    cout << "Archer: " << static_cast<Archer const *>(ElfArcherPtr)  << endl;

    return static_cast<Archer const *>(ElfArcherPtr);
}
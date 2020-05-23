/*
*
* Еще одна важная группа операторов, которые полезно реализовать для класса рациональных чисел — это операторы сравнения. 
* Реализуйте операторы <, <=, >, >=, ==, != для класса Rational так, чтобы можно было сравнивать объекты класса Rational 
* не только друг с другом, но и с целыми числами.
*
*/

#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

struct Rational
{
    Rational(int numerator = 0, int denominator = 1) : numerator_(numerator), denominator_(denominator)
    {

    }


    /*bool operator>(const Rational & rational) const {
        return (this->numerator_>rational.numerator_);
    }
    bool operator>(int d) const {
        return (this->numerator_>d);
    }
    friend bool operator>(int d, const Rational & rational) {
        return (d>rational.numerator_);
    }
    

    bool operator<(const Rational & rational) const {
        return (this->numerator_<rational.numerator_);
    }
    bool operator<(int d) const {
        return (this->numerator_<d);
    }
    friend bool operator<(int d, const Rational & rational) {
        return (d<rational.numerator_);
    }
    

    bool operator>=(const Rational & rational) const {
        return (this->numerator_>=rational.numerator_);
    }
    bool operator>=(int d) const {
        return (this->numerator_>=d);
    }
    friend bool operator>=(int d, const Rational & rational) {
        return (d>=rational.numerator_);
    }
    

    bool operator<=(const Rational & rational) const {
        return (this->numerator_<=rational.numerator_);
    }
    bool operator<=(int d) const {
        return (this->numerator_<=d);
    }
    friend bool operator<=(int d, const Rational & rational) {
        return (d<=rational.numerator_);
    }
    

    bool operator==(const Rational & rational) const {
        return (this->numerator_==rational.numerator_);
    }
    bool operator==(int d) const {
        return (this->numerator_==d);
    }
    friend bool operator==(int d, const Rational & rational) {
        return (d==rational.numerator_);
    }
    

    bool operator!=(const Rational & rational) const {
        return (this->numerator_!=rational.numerator_);
    }
    bool operator!=(int d) const {
        return (this->numerator_!=d);
    }    
    friend bool operator!=(int d, const Rational & rational) {
        return (d!=rational.numerator_);
    }*/

public:
    int get_num(void) const{
        return this->numerator_;
    }

private:
    int numerator_;
    int denominator_;
};

bool operator==(Rational const & lhs, Rational const & rhs){
	return (lhs.get_num()==rhs.get_num());
}

bool operator!=(Rational const & lhs, Rational const & rhs){
	return (lhs.get_num()!=rhs.get_num());
}

bool operator<(Rational const & lhs, Rational const & rhs){
	return (lhs.get_num()<rhs.get_num());
}

bool operator>(Rational const & lhs, Rational const & rhs){
	return (lhs.get_num()>rhs.get_num());
}

bool operator<=(Rational const & lhs, Rational const & rhs){
	return (lhs.get_num()<=rhs.get_num());
}

bool operator>=(Rational const & lhs, Rational const & rhs){
	return (lhs.get_num()>=rhs.get_num());
}

int main()
{
    Rational d1(1);
    Rational d2(2);
    Rational d3(3);

    Rational d4 = 5;

    int d_1 = 1;
    int d_2 = 2;
    int d_3 = 3;

    // < true
    cout << (d1 < d2) << endl;
    cout << (d1 < d_2) << endl;
    cout << (d_1 < d2) << endl;
    // < false
    cout << (d2 < d1) << endl;
    cout << (d2 < d_1) << endl;
    cout << (d_2 < d1) << endl;

    Rational a(5);
    Rational b(6);
    Rational na(7);
    Rational nb(8);

    // 1<5
    if (1 < a){cout<<"ok"<<endl;}else{cout<<"failed"<<endl;}
    // 5<0
    if (a < 0){cout<<"failed"<<endl;}else{cout<<"ok"<<endl;}
    // 5<6
    if (a < b){cout<<"ok"<<endl;}else{cout<<"failed"<<endl;}
    // 5<5
    if (a < a){cout<<"failed"<<endl;}else{cout<<"ok"<<endl;}

    if (a < na){}else{}

    if (na < na){}else{}

    if (b < b){}else{}

    if (b < nb){}else{}

    if (nb < nb){}else{}

    if (!(b < a)){}else{}

    if (!(na < a)){}else{}

    if (!(nb < b)){}else{}
    // !(7<8)
    if (!(na < nb)){cout<<"failed"<<endl;}else{cout<<"ok"<<endl;}

    return 0;                                                  
}


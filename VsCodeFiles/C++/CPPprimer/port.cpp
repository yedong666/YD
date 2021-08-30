#include <cstring>
#include "port.h"
Port::Port(const char * br = "none", const char * st = "none", int b = 0){
    strcpy(brand, br);
    strcpy(style, st);
    bottles = b;
}
Port::Port(const Port & p){
    strcpy(brand, p.brand);
    strcpy(style, p.style);
    bottles = p.bottles;
}
Port & Port::operator=(const Port & p){
    Port newport;
    newport.bottles = p.bottles;
    strcpy(newport.brand, p.brand);
    strcpy(newport.style, p.style);
    return newport;
}
Port & Port::operator+=(int b){
    bottles+=b;
    return *this;
}
Port & Port::operator-=(int b){
    bottles-=b;
    return *this;
}
void Port::Show() const{
    cout << "Brand: " << brand << endl;
    cout << "Kind: " << style << endl;
    cout << "Bottles: " << bottles << endl;
    return;
}
ostream & operator << (ostream & os, const Port & p){
    os << p.brand << ", " << p.style << ", " << p.bottles << endl;
    return os;
}
VintagePort::VintagePort(const char * br, int b, const char *nn, int y) : Port("",br,b) {
    strcpy(nickname, nn);
    year = y;    
}
VintagePort::VintagePort(const VintagePort & vp){
    strcpy(nickname, vp.nickname);
    year = vp.year;
}
VintagePort & VintagePort::operator=(const VintagePort & vp){
    VintagePort newVintagePort;
    newVintagePort.year = vp.year;
    strcpy(newVintagePort.nickname, vp.nickname);
    return newVintagePort;
}
ostream & operator << (ostream & os, const VintagePort & vp){
    os << vp.nickname << ", " << vp.year << endl;
    return os;    
}
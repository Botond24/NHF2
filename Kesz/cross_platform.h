#ifndef CROSS_PLATFORM_H
#define CROSS_PLATFORM_H

#include <iostream>
#include <string>

namespace cp {	    //cross-platform getline
// Működik WinX/Linux/MAC környezetben is.
// Kezeli a \n , a \r\n és a \n\r végű sorokat is.
// Ez utóbbi csak nagyon régi (MAC OS X előtti) MAC rendszerekben fordul elő
std::istream& getline(std::istream& is, std::string& str) {
    std::getline(is, str);
    if (str.size()) {
        if (*str.rbegin() == '\r')
            str.erase(str.size()-1);
        else if  (*str.begin() == '\r')
            str.erase(str.begin());
    }
    return is;
}

} // namespace cp
#endif // CROSS_PLATFORM_H

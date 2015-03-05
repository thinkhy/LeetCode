#include <iostream>

signed int s1 = -4;
unsigned int u1 = 2;
int main()
{
    std::cout << (s1 < u1 ? "s1 < u1" : "s1 !< u1") << "\n";  // "s1 !< u1"
    std::cout << (-4 < 2u ? "-4 < 2u" : "-4 !< 2u") << "\n";  // "-4 !< 2u"
}

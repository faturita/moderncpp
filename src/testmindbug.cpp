/**
  *
  * Testmindbug.cpp
  *
  * Originally, I thought this was a bug but realized the subtle program which was indeed a mind bug.
  *
  * C++ is hard.  And it is hard because it allows you to do a lot of things but you really need to be aware of subtle things.
  *
  * Goal: If you check the code UNAWARE of types and automatic casting you will understand why the code works as it does.
  *
  * Spoiler: Check the return type of STL data structures 'size()' method.
  **/
#include <iostream>
#include <unordered_map>

int main()
{
    std::unordered_map<int, int> mymap;
    mymap[1] = 1;
    mymap[2] = 2;
    mymap[3] = 3;
    mymap[4] = 4;

    int selection = 0;
    printf("->Selection: %d\n", selection);
    if (selection<(mymap.size()*(-1)))
        selection = mymap.size()*(-1);
    printf("<-Selection %d\n", selection);

    return 0;

}
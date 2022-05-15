#include "../src/map.hpp"

int main()
{
    StyledMap map;
    map.render("https://www.mapbox.com", [](){ printf("map rendered!\n"); });
    return 0;
}

extern "C"
{
#include "mapboxswift.h"
}
#include <iostream>
#include "map.hpp"

void render (char *url, void (*callback)()) {
    StyledMap map;
    map.render("https://www.mapbox.com", callback);
}

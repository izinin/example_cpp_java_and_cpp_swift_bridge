#include "../mapgl/map.hpp"

int main()
{
    StyleOptions styleOptions;
    styleOptions.withStyleURL("https://www.mapbox.com");
    std::unique_ptr<Style> stylePointer = Style::createStyle(std::move(styleOptions));
    StyledMap map;
    map.setStyle(std::move(stylePointer));
    map.render([]()
               { printf("map rendered!\n"); });
    return 0;
}

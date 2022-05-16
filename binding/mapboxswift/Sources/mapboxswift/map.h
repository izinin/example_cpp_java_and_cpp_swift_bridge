#pragma once
#include <functional>

class MapInterface
{
public:
    using MapRenderedCallback = std::function<void()>;
    virtual void render(const std::string &url, MapRenderedCallback &&callback) = 0;

protected:
    MapInterface() = default;
};

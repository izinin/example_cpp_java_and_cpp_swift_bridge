#pragma once
#include <functional>
#include <memory>
#include <optional>
#include <string>
#include "map.h"

class StyleOptions
{
public:
    StyleOptions() = default;
    StyleOptions &withStyleURL(const std::string &);
    std::string url;
};

class Style
{
public:
    static std::unique_ptr<Style> createStyle(std::optional<StyleOptions> &&);
    bool isValid() const;

protected:
    Style(std::optional<StyleOptions> &&);

private:
    std::optional<StyleOptions> options;
};

class StyledMap : public MapInterface
{
public:
    StyledMap() = default;
    void setStyle(std::unique_ptr<Style> &&);
    // throws std::runtime_error if no valid style is set.
    void render(const std::string &, MapRenderedCallback &&) final;

private:
    std::unique_ptr<Style> style;
};

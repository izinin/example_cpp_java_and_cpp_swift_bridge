#include "map.hpp"

StyleOptions &StyleOptions::withStyleURL(const std::string &url_)
{
    url = url_;
    return *this;
}

std::unique_ptr<Style> Style::createStyle(std::optional<StyleOptions> &&options_)
{
    return std::make_unique<Style>(Style(std::move(options_)));
}

Style::Style(std::optional<StyleOptions> &&options_)
    : options(std::move(options_)) {}
bool Style::isValid() const
{
    return options && !options->url.empty();
}

void StyledMap::setStyle(std::unique_ptr<Style> &&style_)
{
    style = std::move(style_);
}

void StyledMap::render(const std::string &url, MapRenderedCallback &&callback)
{
    if(url.empty())
    {
        throw std::runtime_error("Style: missing url param");
    }
    StyleOptions styleOptions;
    styleOptions.withStyleURL(url);
    std::unique_ptr<Style> stylePointer = Style::createStyle(std::move(styleOptions));
    StyledMap map;
    map.setStyle(std::move(stylePointer));
    callback();
}

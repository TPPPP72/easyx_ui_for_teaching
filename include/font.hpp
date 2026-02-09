#pragma once

#include "drawable.hpp"
#include "font_info.hpp"
#include <easyx.h>

namespace eui
{

class font : public drawable
{
  public:
    font(const font_info &inf, int x, int y, const std::string &content)
        : m_info(inf), m_x(x), m_y(y), m_content(content)
    {
    }

    void draw() override
    {
        settextstyle(m_info.height, 0, m_info.family.c_str());
        outtextxy(m_x, m_y, m_content.c_str());
    }

  private:
    font_info m_info;
    int m_x, m_y;
    std::string m_content;
};

} // namespace eui

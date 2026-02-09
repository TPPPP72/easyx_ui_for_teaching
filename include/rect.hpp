#pragma once

#include "drawable.hpp"
#include "shape_status.hpp"
#include <easyx.h>

namespace eui
{

class rect : public drawable
{
  public:
    rect(int x, int y, int w, int h, shape_status statu = shape_status::empty)
        : m_left(x), m_top(y), m_right(x + w), m_bottom(y + h), m_statu(statu)
    {
    }
    void draw() override
    {
        switch (m_statu)
        {
        case shape_status::empty:
            rectangle(m_left, m_top, m_right, m_bottom);
            break;
        case shape_status::fill:
            fillrectangle(m_left, m_top, m_right, m_bottom);
            break;
        case shape_status::solid:
            solidrectangle(m_left, m_top, m_right, m_bottom);
            break;
        }
    }

  private:
    int m_left, m_top, m_right, m_bottom;
    shape_status m_statu;
};
} // namespace eui

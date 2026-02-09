#pragma once

#include "drawable.hpp"
#include "shape_status.hpp"
#include <easyx.h>

namespace eui
{

class round_rect : public drawable
{
  public:
    round_rect(int x, int y, int w, int h, int ew, int eh, shape_status statu = shape_status::empty)
        : m_left(x), m_top(y), m_right(x + w), m_bottom(y + h), m_ew(ew), m_eh(eh), m_statu(statu)
    {
    }
    void draw() override
    {
        switch (m_statu)
        {
        case shape_status::empty:
            roundrect(m_left, m_top, m_right, m_bottom, m_ew, m_eh);
            break;
        case shape_status::fill:
            fillroundrect(m_left, m_top, m_right, m_bottom, m_ew, m_eh);
            break;
        case shape_status::solid:
            solidroundrect(m_left, m_top, m_right, m_bottom, m_ew, m_eh);
            break;
        }
    }

  private:
    int m_left, m_top, m_right, m_bottom, m_ew, m_eh;
    shape_status m_statu;
};
} // namespace eui

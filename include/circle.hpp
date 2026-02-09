#pragma once

#include "drawable.hpp"
#include "shape_status.hpp"
#include <easyx.h>

namespace eui
{

inline void CIRCLE(int x, int y, int r)
{
    circle(x, y, r);
}

class circle : public drawable
{
  public:
    circle(int x, int y, int r, shape_status statu = shape_status::empty) : m_x(x), m_y(y), m_r(r), m_statu(statu)
    {
    }
    void draw() override
    {
        switch (m_statu)
        {
        case shape_status::empty:
            CIRCLE(m_x, m_y, m_r);
            break;
        case shape_status::fill:
            fillcircle(m_x, m_y, m_r);
            break;
        case shape_status::solid:
            solidcircle(m_x, m_y, m_r);
            break;
        }
    }

  private:
    int m_x, m_y, m_r;
    shape_status m_statu;
};
} // namespace eui

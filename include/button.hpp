#pragma once

#include "message.hpp"
#include "round_rect.hpp"
#include <functional>

namespace eui
{

class button
{
  public:
    button(int x, int y, int w, int h) : m_x(x), m_y(y), m_w(w), m_h(h)
    {
    }
    void handle_event(message m)
    {
        if (m.m_button != mouse_event::left)
            return;

        if (m.m_x < m_x)
            return;

        if (m.m_x > m_x + m_w)
            return;

        if (m.m_y < m_y)
            return;

        if (m.m_y > m_y + m_h)
            return;

        if (on_click)
            on_click();
    }
    std::function<void()> on_click;
    void draw()
    {
        round_rect r{m_x, m_y, m_w, m_h, 3, 3, shape_status::fill};
        r.draw();
    }

  private:
    int m_x, m_y, m_w, m_h;
    bool is_visible;
    bool is_active;
};

} // namespace eui

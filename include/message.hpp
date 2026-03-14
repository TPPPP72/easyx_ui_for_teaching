#pragma once

#include <cstdint>
#include <easyx.h>

namespace eui
{

enum class mouse_event
{
    null,
    left
};

enum class window_event
{
    null,
    resize
};

struct message
{
    window_event m_window{window_event::null};
    mouse_event m_button{mouse_event::null};
    std::int16_t m_x{0}, m_y{0};
};

inline bool get_message(message &msg)
{
    ExMessage exmsg;
    if (peekmessage(&exmsg, EX_MOUSE | EX_WINDOW))
    {
        if (exmsg.wParam == WM_SIZE)
            msg.m_window = window_event::resize;
        if (exmsg.lbutton)
            msg.m_button = mouse_event::left;
        msg.m_x = exmsg.x;
        msg.m_y = exmsg.y;
    }
    return true;
}

} // namespace eui
#include "include/batch_draw.hpp"
#include "include/font.hpp"
#include "include/message.hpp"
#include "include/window.hpp"
#include <iostream>
#include <thread>

int main()
{
    window w(640, 480);
    w.set_title("easyx ui");

    batch_draw buffer{};

    setlinecolor(RED);
    setfillcolor(BLUE);

    eui::font_info info;
    info.height = 18;
    info.family = "Consolas";

    eui::message msg;
    while (eui::get_message(msg))
    {
        w.clear();
        eui::font f{info, 30, 30, "Hello"};
        f.draw();
        buffer.flush();
        if (msg.m_window == eui::window_event::resize)
            std::cout << "Window resized\n";
        std::cout << msg.m_x << ' ' << msg.m_y << '\n';
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}
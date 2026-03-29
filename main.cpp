#include "include/batch_draw.hpp"
#include "include/button.hpp"
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

    int count = 0;

    eui::font f{info, 30, 30, "Hello"};
    eui::button but{100, 100, 80, 20};
    but.on_click = [&count]() { ++count; };

    eui::button but2{200, 200, 80, 20};
    but2.on_click = [&count]() { std::cout << count; };

    eui::message msg;
    while (eui::get_message(msg))
    {
        w.clear();
        but.handle_event(msg);
        but.draw();
        but2.handle_event(msg);
        but2.draw();
        f.draw();
        buffer.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}
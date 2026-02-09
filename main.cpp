#include "include/batch_draw.hpp"
#include "include/font.hpp"
#include "include/window.hpp"
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

    while (true)
    {
        w.clear();
        eui::font f{info, 30, 30, "Hello"};
        f.draw();
        buffer.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}
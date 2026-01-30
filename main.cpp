#include "include/batch_draw.hpp"
#include "include/window.hpp"
#include <iostream>
#include <thread>

int main()
{
    window w(640, 480);

    std::cout << "current title is : " << w.title() << '\n';

    w.set_title("new_title");

    std::cout << "current title is : " << w.title() << '\n';

    batch_draw buffer{};

    std::uint32_t x = 200;

    while (x <= 600)
    {
        w.clear();
        circle(x, 200, 100);
        ++x;
        buffer.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(80));
    }
}
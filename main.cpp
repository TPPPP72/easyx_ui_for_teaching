#include "include/window.hpp"
#include <iostream>
#include <thread>

int main()
{
    window w(640, 480);

    std::uint32_t x = 200;

    while (x <= 600)
    {
        circle(x, 200, 100);
        ++x;
        std::this_thread::sleep_for(std::chrono::milliseconds(80));
        w.clear();
    }

    std::cin.get();
}
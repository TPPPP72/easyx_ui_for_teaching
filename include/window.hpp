#pragma once

#include <cstdint>
#include <easyx.h>

class window
{
  public:
    window(std::int32_t width, std::int32_t height)
    {
        hwnd = initgraph(width, height);
    }
    window(std::int32_t width, std::int32_t height, std::int32_t flag)
    {
        hwnd = initgraph(width, height, flag);
    }
    ~window()
    {
        closegraph();
    }
    void clear() noexcept
    {
        cleardevice();
    }
    void reset() noexcept
    {
        graphdefaults();
    }

  private:
    HWND hwnd;
};
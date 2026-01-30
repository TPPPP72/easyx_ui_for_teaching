#pragma once

#include <cstdint>
#include <easyx.h>
#include <stdexcept>
#include <string>

class window
{
  public:
    window(std::int32_t width, std::int32_t height, std::int32_t flag)
        : m_hwnd(initgraph(width, height, flag)), m_title(get_title_from_winapi())
    {
        if (m_hwnd == nullptr)
            throw std::runtime_error("Create window failed      error code : " + std::to_string(GetLastError()));
    }
    window(std::int32_t width, std::int32_t height) : window(width, height, 0)
    {
    }
    ~window()
    {
        closegraph();
    }
    window(const window &) = delete;
    window &operator=(const window &) = delete;

    window(window &&other) noexcept : m_hwnd(other.m_hwnd)
    {
        other.m_hwnd = nullptr;
    }
    window &operator=(window &&other) noexcept
    {
        m_hwnd = other.m_hwnd;
        other.m_hwnd = nullptr;
        return *this;
    }
    void clear() noexcept
    {
        cleardevice();
    }
    void reset() noexcept
    {
        graphdefaults();
    }
    HWND get_hwnd() const noexcept
    {
        return m_hwnd;
    }
    std::string title() const noexcept
    {
        return m_title;
    }
    void set_title(const std::string &title)
    {
        if (!SetWindowTextA(m_hwnd, title.c_str()))
            throw std::runtime_error("Set window title failed      error code : " + std::to_string(GetLastError()));

        m_title = title;
    }

  private:
    std::string get_title_from_winapi() const
    {
        char buff[256];

        if (!GetWindowTextA(m_hwnd, buff, 256))
            throw std::runtime_error("Get window title failed      error code : " + std::to_string(GetLastError()));

        return buff;
    }

  private:
    HWND m_hwnd{nullptr};
    std::string m_title;
};
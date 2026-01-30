#pragma once

#include <easyx.h>

class batch_draw
{
  public:
    batch_draw()
    {
        BeginBatchDraw();
    }
    ~batch_draw()
    {
        EndBatchDraw();
    }

    void flush() noexcept
    {
        FlushBatchDraw();
    }

    batch_draw(const batch_draw &) = delete;
    batch_draw &operator=(const batch_draw &) = delete;

    batch_draw(batch_draw &&) noexcept = delete;
    batch_draw &operator=(batch_draw &&) noexcept = delete;
};
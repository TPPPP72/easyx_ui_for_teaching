#pragma once

class drawable
{
  public:
    drawable() = default;
    virtual ~drawable() = default;

    virtual void draw() = 0;
};
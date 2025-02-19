#pragma once

class Controller {
public:
    virtual ~Controller() = default;

    virtual void run() = 0;
};

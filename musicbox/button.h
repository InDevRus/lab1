#pragma once

class Button
{
public:
    Button(int _pin)
    {
        pin = _pin;
        state = LOW;

        pinMode(pin, INPUT_PULLUP);
    }

    bool isPressed()
    {
        state = digitalRead(pin);
        return state == LOW;
    }

private:
    int pin;
    int state;
};

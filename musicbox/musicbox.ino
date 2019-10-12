#include "pitches.h"
#include "button.h"

const auto buttonsCount = 8;
const auto buzzerPin = buttonsCount + 1;

const int notesByButton[buttonsCount] = {
    NOTE_B1,
    NOTE_C2,
    NOTE_D2,
    NOTE_E2,
    NOTE_F2,
    NOTE_G2,
    NOTE_A2,
    NOTE_B2,
};

Button *buttons[8];

void setup()
{
    for (auto number = 0; number < buttonsCount; number++)
    {
        auto pin = number + 1;
        buttons[number] = new Button(pin);
    }
}

void loop()
{
    auto anyWasPressed = false;
    for (auto number = 0; number < buttonsCount; number++)
    {
        auto &button = *buttons[number];
        if (button.wasPressed())
        {
            anyWasPressed = true;
            tone(buzzerPin, notesByButton[number]);
        }
    }
    if (!anyWasPressed)
    {
        noTone(buzzerPin);
    }
}

#include "pitches.h"
#include "button.h"
#include "buzzer.h"

/* #define PIN_BUTTON_SOUND_1 3
#define PIN_BUTTON_SOUND_2 4
#define PIN_BUTTON_SOUND_3 5
#define PIN_BUTTON_SOUND_4 6
#define PIN_BUTTON_SOUND_5 7
#define PIN_BUTTON_SOUND_6 8
#define PIN_BUTTON_SOUND_7 9
#define PIN_BUTTON_SOUND_8 10

int notes[] = {NOTE_A4, NOTE_SILENCE, NOTE_G4, NOTE_SILENCE};
double durations[] = {8, 1, 4, 1};
int melodyLength = 4; */

#define PIN_BUZZER 11

const auto buttonsCount = 8;
const auto defaultNoteDuration = 3;

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
Buzzer buzzer(PIN_BUZZER);

void setup()
{
    for (auto number = 0; number < buttonsCount; number++)
    {
        auto pin = number + 3;
        buttons[number] = new Button(pin);
    }

    // buzzer.setMelody(notes, durations, melodyLength);
}

void loop()
{
    /* buzzer.playSound();

    if (buttonMelodyOne.wasPressed())
    {
        buzzer.setMelody(notes, durations, melodyLength);
        buzzer.turnSoundOn();
    } */

    for (auto number = 0; number < buttonsCount; number++)
    {
        auto button = *buttons[number];
        if (button.wasPressed())
        {
            int sound[1] = {notesByButton[number]};
            double duration[1] = {defaultNoteDuration};

            buzzer.setMelody(sound, duration, defaultNoteDuration);
            buzzer.turnSoundOn();
        }
    }
}

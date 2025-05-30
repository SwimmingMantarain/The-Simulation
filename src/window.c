#include "raylib.h"

// Some Definitions
#define SCREEN_W 800
#define SCREEN_H 450

void checkFullscreen() {
    // check for alt + enter
    if (IsKeyPressed(KEY_ENTER) && (IsKeyDown(KEY_LEFT_ALT) || IsKeyDown(KEY_RIGHT_ALT))) {
        // Current display we are on
        int display = GetCurrentMonitor();

        if (IsWindowFullscreen()) {
            // if we are fullscreen, then shrink back to windowed size
            SetWindowSize(SCREEN_W, SCREEN_H);
        } else {
            // else then blow it up
            SetWindowSize(GetMonitorWidth(display), GetMonitorHeight(display));
        }

        // Tell ourselves what we have just accomplished ;)
        ToggleFullscreen();
    }
}

#include "raylib.h"
#include "rcamera.h"
typedef enum GameScreen { LOGO = 0, TITLE, GAMEPLAY, ENDING} GameScreen;

int main(void)
{
    //Screen Resolution
    const int screenWidth = 800;
    const int screenHeight = 450;

    //Define screen
    InitWindow(screenWidth, screenHeight, "ScreenExample");

    GameScreen currentScreen = LOGO;
    int framesCounter = 0;  //

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        switch (currentScreen)
        {
        case LOGO: 
        {
            //wait for 2 sec (60fps) then switch to TITLE screen
            framesCounter++;
            if (framesCounter > 120)
            {
                currentScreen = TITLE;
            }
        } break;
        case TITLE:
        {
            if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
            {
                currentScreen = GAMEPLAY;
            }
        } break;
        case GAMEPLAY:
        {
            if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
            {
                currentScreen = ENDING;
            }
        } break;
        case ENDING:
        {
            if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
            {
                currentScreen = TITLE;
            }
        } break;
        default: break;
        }
     BeginDrawing();
        ClearBackground(BLACK);

        switch (currentScreen)
        {
        case LOGO:
        {
            DrawText("LOADING...", 20, 20, 40, LIGHTGRAY);
            DrawText("Please Wait...", 290, 220, 20, GRAY);
        } break;
        case TITLE:
        {
            DrawRectangle(0, 0, screenWidth, screenHeight, GREEN);
            DrawText("TITLE SCREEN", 20, 20, 40, DARKGREEN);
            DrawText("PRESS ENTER or TAP to JUMP to GAMEPLAY SCREEN", 120, 220, 20, DARKGREEN);
        }break;
        case GAMEPLAY:
        {
            DrawRectangle(0, 0, screenWidth, screenHeight, PURPLE);
            DrawText("GAMEPLAY SCREEN", 20, 20, 40, MAROON);
            DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, MAROON);
        }break;
        case ENDING:
        {
            DrawRectangle(0, 0, screenWidth, screenHeight, BLUE);
            DrawText("ENDING SCREEN", 20, 20, 40, DARKBLUE);
            DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, DARKBLUE);
        } break;
        default: break;
        }

     EndDrawing();
    }


    CloseWindow();       


    return 0;
}
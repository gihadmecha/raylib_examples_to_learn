/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples in Notepad++, provided with default raylib installer package, 
*   just press F6 and run [raylib_compile_execute] script, it will compile and execute.
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on [C:\raylib\raylib\examples] directory and
*   raylib official webpage: [www.raylib.com]
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2020 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    
    //RLAPI void InitAudioDevice(void);
    InitAudioDevice();

    //RLAPI Music LoadMusicStream(const char *fileName);
    //Music music = LoadMusicStream("music.mp3");

    //RLAPI Sound LoadSound(const char *fileName);
    Sound sound = LoadSound("wave.wav");

    //RLAPI Sound LoadSoundFromWave(Wave wave);
    //Sound sound = LoadSoundFromWave(wave);

    //RLAPI void ExportWave(Wave wave, const char *fileName);
    //ExportWave(wave, "export_wave.wav");
  
    //RLAPI void UnloadWave(Wave wave);
    //UnloadWave(wave);

    //RLAPI void SetSoundVolume(Sound sound, float volume);
    //SetSoundVolume(sound,5);

    //PlayMusicStream(music);
    
    //RLAPI void PlaySound(Sound sound);
    PlaySound(sound);
    

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
            
            //RLAPI void UpdateMusicStream(Music music);
            //UpdateMusicStream(music);
            


        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    //UnloadMusicStream(music);
    //UnloadMusicStream(music);


    //RLAPI void UnloadSound(Sound sound);
    UnloadSound(sound);

    //RLAPI void CloseAudioDevice(void);
      CloseAudioDevice();

      CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
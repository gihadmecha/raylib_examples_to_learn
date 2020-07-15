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

    //RLAPI Sound LoadSound(const char *fileName);
    //Sound sound = LoadSound("wave.wav");
    //Sound sound_Of_angryman = LoadSound("maybe_next_time.wav");

    //RLAPI Wave LoadWave(const char *fileName);
    Wave wave = LoadWave("Sm3na_com_57675.wav");
    WaveCrop(&wave, 193350, 19335049);
    printf("****************** sampleCount %d\n", wave.sampleCount); // 536474
    printf("****************** sampleRate %d\n", wave.sampleRate); // 536474
    printf("****************** sampleSize %d\n", wave.sampleSize); // 536474
    printf("****************** channels %d\n", wave.channels); // 536474

    //RLAPI void UnloadWave(Wave wave);
    //UnloadWave(wave);

    //RLAPI Sound LoadSoundFromWave(Wave wave);
    Sound sound = LoadSoundFromWave(wave);

    //RLAPI void ExportWave(Wave wave, const char *fileName);
    //ExportWave(wave, "export_wave.wav");
  
    //RLAPI void UnloadWave(Wave wave);
    UnloadWave(wave);

    //RLAPI void SetSoundVolume(Sound sound, float volume);
    SetSoundVolume(sound,5);

    //RLAPI void SetSoundPitch(Sound sound, float pitch);
   // SetSoundPitch(sound_Of_angryman,1);


    //RLAPI void PlaySoundMulti(Sound sound);
    //PlaySoundMulti(sound_Of_angryman);
    //PlaySoundMulti(sound);

            
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
      if (IsKeyPressed(KEY_ENTER) )
        {
             //RLAPI void PlaySound(Sound sound);
             PlaySound(sound);
             //PlaySoundMulti(sound);
        }
       if (IsKeyPressed(KEY_TAB))
        {
            //RLAPI void StopSound(Sound sound);
            StopSound(sound);
        }
        if (IsKeyPressed(KEY_A))
        {
            //RLAPI void PauseSound(Sound sound);
            PauseSound(sound);
        }
        if (IsKeyPressed(KEY_B))
        {
            //RLAPI void ResumeSound(Sound sound);
            ResumeSound(sound);
        }


        int sound_number = GetSoundsPlaying();

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText(TextFormat("sound number: %i",sound_number), 190, 200, 20, RED);

            ///RLAPI bool IsSoundPlaying(Sound 
            if (IsSoundPlaying(sound))
                {
                    //RLAPI int GetSoundsPlaying(void);
                    DrawText("HI", 190, 300, 20, RED);
                }        
            

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    //RLAPI void StopSoundMulti(void);
    StopSoundMulti();

    //RLAPI void UnloadSound(Sound sound);
    UnloadSound(sound);

    //RLAPI void CloseAudioDevice(void);
    CloseAudioDevice();

    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
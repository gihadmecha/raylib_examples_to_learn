/*******************************************************************************************
*
*   raylib [core] example - Keyboard input
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;


    

    InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");
    

    Vector2 ballPosition = { (float)screenWidth/2, (float)screenHeight/2 };

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {    
         //BeginDrawing();

        

        // EndDrawing();
        // Update
        //----------------------------------------------------------------------------------
        int ghd_magic_key = GetKeyPressed();
        if (IsKeyDown(KEY_RIGHT)) ballPosition.x += 5.0f;
        if (IsKeyDown(KEY_LEFT)) ballPosition.x -= 2.0f;
        if (IsKeyDown(KEY_UP)) ballPosition.y -= 2.0f;
        if (IsKeyDown(KEY_DOWN)) ballPosition.y += 2.0f;

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
      BeginDrawing();

            ClearBackground(BLACK);

           // DrawText("move the ball with arrow keys ", 10, 10, 50, GOLD);
            DrawCircleV((Vector2){ 100, 100 }, 50, RED);
            DrawCircleV((Vector2){ ballPosition.x, ballPosition.y}, 50, WHITE);
            //RLAPI void DrawRectangle(int posX, int posY, int width, int height, Color color);
            DrawRectangle(ballPosition.x-100, ballPosition.y-100,50,50,WHITE);
            DrawRectangle(200, 300, 100, 100, RED);
            DrawRectangle(500, 400, 100, 100, BLUE);
            //RLAPI void DrawPixelV(Vector2 position, Color color);   
            DrawPixelV((Vector2){ 700, 200}, GOLD); 
            //RLAPI void DrawTriangle(Vector2 v1, Vector2 v2, Vector2 v3, Color color); 
            DrawTriangle((Vector2){ ballPosition.x+100, ballPosition.y},(Vector2){ballPosition.x+200, ballPosition.y},(Vector2){ballPosition.x+200, ballPosition.y-200}, WHITE);   
            
            //CheckCollisionCircles(Vector2 center1, float radius1, Vector2 center2, float radius2);
            //RLAPI bool CheckCollisionRecs(Rectangle rec1, Rectangle rec2); 
            //RLAPI bool CheckCollisionCircleRec(Vector2 center, float radius, Rectangle rec);
            //RLAPI bool CheckCollisionPointRec(Vector2 point, Rectangle rec); 
            //RLAPI bool CheckCollisionPointCircle(Vector2 point, Vector2 center, float radius);
            //RLAPI bool CheckCollisionPointTriangle(Vector2 point, Vector2 p1, Vector2 p2, Vector2 p3); 
             
            if(CheckCollisionCircles((Vector2){ ballPosition.x, ballPosition.y}, 50, (Vector2){ 100, 100 }, 50) || CheckCollisionRecs((Rectangle){ ballPosition.x-100, ballPosition.y-100,50,50}, (Rectangle){200, 300, 100, 100}) || CheckCollisionCircleRec((Vector2){ ballPosition.x, ballPosition.y}, 50,(Rectangle){200, 300, 100, 100}) || CheckCollisionPointRec((Vector2){ 700, 200}, (Rectangle){ ballPosition.x-100, ballPosition.y-100,50,50}) || CheckCollisionPointCircle((Vector2){ 700, 200}, (Vector2){ ballPosition.x, ballPosition.y}, 50) || CheckCollisionPointTriangle((Vector2){ 700, 200}, (Vector2){ ballPosition.x+100, ballPosition.y},(Vector2){ballPosition.x+200, ballPosition.y},(Vector2){ballPosition.x+200, ballPosition.y-200}))      
               {
                DrawCircleV((Vector2){ 100, 100 }, 50, BLUE);
             
               } 

          //RLAPI bool CheckCollisionRecs(Rectangle rec1, Rectangle rec2);
          if (CheckCollisionRecs((Rectangle){ ballPosition.x-100, ballPosition.y-100,50,50}, (Rectangle){200, 300, 100, 100}))
               {
                   //RLAPI void DrawRectangleRec(Rectangle rec, Color color);
                   DrawRectangleRec(GetCollisionRec((Rectangle){ ballPosition.x-100, ballPosition.y-100,50,50}, (Rectangle){200, 300, 100, 100}), BROWN);
               }     
 
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
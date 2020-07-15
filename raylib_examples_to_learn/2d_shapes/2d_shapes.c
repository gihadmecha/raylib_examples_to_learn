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

#define POINTES 4
#define line_points 2
#define triangle_points 4



int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1350;
    const int screenHeight = 700;



    Vector2 mark[POINTES] = { (Vector2){200,100},(Vector2){100,400}, (Vector2){800,100},(Vector2){800,700}  };
    Vector2 line_strip[line_points] = { (Vector2){700,100},(Vector2){500,400}};
    Vector2 trangle_strip[triangle_points] = { (Vector2){1350,0},(Vector2){1300,0}, (Vector2){1350,200},(Vector2){1050,400}  };
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

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
            DrawCircleV((Vector2){400,400}, 20, (Color){ 255, 109, 194, 255 } );
            DrawPixel(1350/2, 700/2, BLACK); 
            
           // DrawPixelV((Vector2){400,400}, (Color){ 230, 41, 55, 255 });; 
            DrawLine(50, 50, 100, 100, RED); 
           // RLAPI void DrawLineV(Vector2 startPos, Vector2 endPos, Color color);
            DrawLineV((Vector2){1000,100},(Vector2){1200,400}, PURPLE);
            //RLAPI void DrawTriangle(Vector2 v1, Vector2 v2, Vector2 v3, Color color);   
            //RLAPI void DrawLineEx(Vector2 startPos, Vector2 endPos, float thick, Color color);  
            DrawLineEx((Vector2){1000,200},(Vector2){1200,500}, 8.5, VIOLET);  
            //RLAPI void DrawLineBezier(Vector2 startPos, Vector2 endPos, float thick, Color color);
            DrawLineBezier((Vector2){1000,400},(Vector2){1200,700}, 5, SKYBLUE);
            //RLAPI void DrawLineStrip(Vector2 *points, int numPoints, Color color);  
            DrawLineStrip(line_strip, 2,BEIGE );  
            //RLAPI void DrawCircle(int centerX, int centerY, float radius, Color color);
            DrawCircle(80, 80, 80, MAROON);
            //RLAPI void DrawCircleSector(Vector2 center, float radius, int startAngle, int endAngle, int segments, Color color);
            DrawCircleSector((Vector2){500,500}, 100, 0, 80, 8, GREEN);
            //RLAPI void DrawCircleSectorLines(Vector2 center, float radius, int startAngle, int endAngle, int segments, Color color);    
            DrawCircleSectorLines((Vector2){700,600},100.5, 90, 270, 5, LIME ); 
            //RLAPI void DrawCircleGradient(int centerX, int centerY, float radius, Color color1, Color color2);       // Draw a gradient-filled circle  
            DrawCircleGradient(200, 500, 200, DARKBROWN, PINK);       // Draw a gradient-filled circle
            //RLAPI void DrawCircleLines(int centerX, int centerY, float radius, Color color);
            DrawCircleLines(500, 600, 100, MAGENTA);
            //RLAPI void DrawEllipse(int centerX, int centerY, float radiusH, float radiusV, Color color);
            DrawEllipse(500, 200,200, 150, BLUE );
            //RLAPI void DrawEllipseLines(int centerX, int centerY, float radiusH, float radiusV, Color color);
            DrawEllipseLines(700, 200, 200, 100, DARKBLUE);
            //RLAPI void DrawRing(Vector2 center, float innerRadius, float outerRadius, int startAngle, int endAngle, int segments, Color color);
            DrawRing((Vector2){700,500}, 15, 17, 0, 360, 8, GRAY);
            //RLAPI void DrawRingLines(Vector2 center, float innerRadius, float outerRadius, int startAngle, int endAngle, int segments, Color color);  
            DrawRingLines((Vector2){700,400}, 40, 50, 0, 90,5, GOLD);  
            //RLAPI void DrawRectangle(int posX, int posY, int width, int height, Color color);
            DrawRectangle(700, 600, 50, 100, BEIGE);
            //RLAPI void DrawRectangleV(Vector2 position, Vector2 size, Color color);
            DrawRectangleV((Vector2){700,400}, (Vector2){75,150}, MAGENTA);
            //RLAPI void DrawRectangleRec(Rectangle rec, Color color);
            DrawRectangleRec((Rectangle){700,200,100,200}, ORANGE);
            //RLAPI void DrawRectanglePro(Rectangle rec, Vector2 origin, float rotation, Color color);
            DrawRectanglePro((Rectangle){900,100,100,200}, (Vector2){-100,-100},90, YELLOW);
            //RLAPI void DrawRectangleGradientV(int posX, int posY, int width, int height, Color color1, Color color2);
            DrawRectangleGradientV(900, 300, 150, 150, PINK, BROWN);
            //RLAPI void DrawRectangleGradientH(int posX, int posY, int width, int height, Color color1, Color color2);
            DrawRectangleGradientH(900, 150, 150, 100, BLUE, DARKBLUE);
            //RLAPI void DrawRectangleGradientEx(Rectangle rec, Color col1, Color col2, Color col3, Color col4);
            DrawRectangleGradientEx((Rectangle){900,100,200,100}, RED, YELLOW, GREEN, BLUE);
            //RLAPI void DrawRectangleLines(int posX, int posY, int width, int height, Color color);
            DrawRectangleLines(1000, 0 , 30, 60, PINK);
            //RLAPI void DrawRectangleLinesEx(Rectangle rec, int lineThick, Color color); 
            DrawRectangleLinesEx((Rectangle){1000,70,100,200}, 5, SKYBLUE); 
            //RLAPI void DrawRectangleRounded(Rectangle rec, float roundness, int segments, Color color);
            DrawRectangleRounded((Rectangle){1000,40,200,200}, 0, 6, BROWN );
            //RLAPI void DrawRectangleRoundedLines(Rectangle rec, float roundness, int segments, int lineThick, Color color);
            DrawRectangleRoundedLines((Rectangle){1100,40,200,200}, 0, 8, 8, PINK);
            //RLAPI void DrawTriangle(Vector2 v1, Vector2 v2, Vector2 v3, Color color);  
            DrawTriangle((Vector2){200,100},(Vector2){100,400}, (Vector2){800,100}, (Color){ 230, 41, 55, 255 });
            DrawTriangleLines((Vector2){300,200},(Vector2){200,500}, (Vector2){900,200}, GOLD );
            DrawTriangleFan(mark,5, ORANGE ); 
            //RLAPI void DrawTriangleStrip(Vector2 *points, int pointsCount, Color color);
            DrawTriangleStrip(trangle_strip, triangle_points, BLACK);
            //RLAPI void DrawPoly(Vector2 center, int sides, float radius, float rotation, Color color);
            DrawPoly((Vector2){1200,600}, 6, 100, 0, RED);
            //RLAPI void DrawPolyLines(Vector2 center, int sides, float radius, float rotation, Color color);
            DrawPolyLines((Vector2){1200,300}, 9, 50, 45, BLUE);
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
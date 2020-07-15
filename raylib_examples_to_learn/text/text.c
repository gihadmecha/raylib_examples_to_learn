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
--------------------------------------------------------------------------------------------
RLAPI Font GetFontDefault(void);                                                            
RLAPI Font LoadFont(const char *fileName);                                                  
RLAPI Font LoadFontEx(const char *fileName, int fontSize, int *fontChars, int charsCount);  
RLAPI Font LoadFontFromImage(Image image, Color key, int firstChar);                        
RLAPI CharInfo *LoadFontData(const char *fileName, int fontSize, int *fontChars, int charsCount, int type); 
RLAPI Image GenImageFontAtlas(const CharInfo *chars, Rectangle **recs, int charsCount, int fontSize, int padding, int packMethod);  
RLAPI void UnloadFont(Font font);

RLAPI void DrawTextEx(Font font, const char *text, Vector2 position, float fontSize, float spacing, Color tint);
void DrawTextRec(Font font, const char *text, Rectangle rec, float fontSize, float spacing, bool wordWrap, Color tint);
RLAPI void DrawTextRecEx(Font font, const char *text, Rectangle rec, float fontSize, float spacing, bool wordWrap, Color tint,
                         int selectStart, int selectLength, Color selectTint, Color selectBackTint);

RLAPI void DrawTextCodepoint(Font font, int codepoint, Vector2 position, float scale, Color tint);
RLAPI int MeasureText(const char *text, int fontSize);                                      
RLAPI Vector2 MeasureTextEx(Font font, const char *text, float fontSize, float spacing);    
RLAPI int GetGlyphIndex(Font font, int codepoint);

RLAPI int TextCopy(char *dst, const char *src);  
RLAPI const char *TextJoin(const char **textList, int count, const char *delimiter);        
RLAPI const char **TextSplit(const char *text, char delimiter, int *count);                 
RLAPI void TextAppend(char *text, const char *append, int *position);                          
RLAPI char *TextToUtf8(int *codepoints, int length);

RLAPI int *GetCodepoints(const char *text, int *count);               
RLAPI int GetCodepointsCount(const char *text);                       
RLAPI int GetNextCodepoint(const char *text, int *bytesProcessed);    
RLAPI const char *CodepointToUtf8(int codepoint, int *byteLength);

RLAPI void DrawTextEx(Font font, const char *text, Vector2 position, float fontSize, float spacing, Color tint);

********************************************************************************************/

#include "raylib.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    
    
    

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    int var = 0;

    SetTargetFPS(30);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // if (IsKeyDown(KEY_SPACE)) var += 8;
        var++;

        // if (IsKeyPressed(KEY_ENTER)) var = 0;
        //----------------------------------------------------------------------------------


        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            //RLAPI void DrawFPS(int posX, int posY);
            DrawFPS(50,50);

            //RLAPI void DrawText(const char *text, int posX, int posY, int fontSize, Color color);
            DrawText("HI",200,200,50,SKYBLUE);

            

            //RLAPI bool TextIsEqual(const char *text1, const char *text2); 
            if(TextIsEqual("gihd", "gihad"))
            {
                DrawText("DONE",400 , 200, 20, GREEN);
            } 
            else
            {
                DrawText("wrong",400 , 200, 20, PINK);
            } 

            //RLAPI unsigned int TextLength(const char *text);
            int lenght = TextLength("textlenght"); 
            //RLAPI const char *TextFormat(const char *text, ...);
            DrawText(TextFormat("%i", lenght),600 , 200, 20, RED);
            //RLAPI const char *TextSubtext(const char *text, int position, int length);
            DrawText(TextSubtext("what", 0,2),700 , 200, 20, BLUE);
            // DrawText(TextSubtext(message, 0, framesCounter/10), 210, 160, 20, MAROON);
            DrawText(TextSubtext("Bla Bla Bla Bla Bla Bla Bla Bla Bla Bla Bla Bla ", 0, var), 210, 160, 20, MAROON);
            //RLAPI char *TextReplace(char *text, const char *replace, const char *by);
            DrawText(TextReplace("fli", "i", "y"),700 , 100, 20, GRAY);
            //RLAPI char *TextInsert(const char *text, const char *insert, int position);
            DrawText(TextInsert(" ", "a", 0),700 , 50, 20, ORANGE);
            //RLAPI int TextFindIndex(const char *text, const char *find);
            int index = TextFindIndex("hla", "a");
            DrawText(TextFormat("%i", index),100 , 100, 20, RED);
            //RLAPI const char *TextToUpper(const char *text);
            DrawText(TextToUpper("lalala"),500 , 50, 20, BROWN);
            //RLAPI const char *TextToLower(const char *text);
            DrawText(TextToLower("LALALA"),500 , 20, 20, BROWN);
            //RLAPI const char *TextToPascal(const char *text);
            DrawText(TextToPascal("Lolololo"),400 , 20, 20, GOLD);
            //RLAPI int TextToInteger(const char *text);
            DrawText(TextFormat("%i", TextToInteger("12345hhhh6789")),100 , 70, 20, RED);





        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
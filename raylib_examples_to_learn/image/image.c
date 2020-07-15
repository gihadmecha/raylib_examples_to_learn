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
*-------------------------------------------------------------------------------------------
RLAPI Image LoadImageEx(Color *pixels, int width, int height);                                           // Load image from Color array data (RGBA - 32bit)
RLAPI void ExportImageAsCode(Image image, const char *fileName);                                         // Export image as code file defining an array of bytes

// Image generation functions
RLAPI Image GenImageColor(int width, int height, Color color);                                           // Generate image: plain color
RLAPI Image GenImageGradientV(int width, int height, Color top, Color bottom);                           // Generate image: vertical gradient
RLAPI Image GenImageGradientH(int width, int height, Color left, Color right);                           // Generate image: horizontal gradient
RLAPI Image GenImageGradientRadial(int width, int height, float density, Color inner, Color outer);      // Generate image: radial gradient
RLAPI Image GenImageChecked(int width, int height, int checksX, int checksY, Color col1, Color col2);    // Generate image: checked
RLAPI Image GenImageWhiteNoise(int width, int height, float factor);                                     // Generate image: white noise
RLAPI Image GenImagePerlinNoise(int width, int height, int offsetX, int offsetY, float scale);           // Generate image: perlin noise
RLAPI Image GenImageCellular(int width, int height, int tileSize);                                       // Generate image: cellular algorithm. Bigger tileSize means bigger cells

// Image manipulation functions
RLAPI Image ImageCopy(Image image);                                                                      // Create an image duplicate (useful for transformations)
RLAPI Image ImageFromImage(Image image, Rectangle rec);                                                  // Create an image from another image piece
RLAPI Image ImageText(const char *text, int fontSize, Color color);                                      // Create an image from text (default font)
RLAPI Image ImageTextEx(Font font, const char *text, float fontSize, float spacing, Color tint);         // Create an image from text (custom sprite font)
RLAPI void ImageFormat(Image *image, int newFormat);                                                     // Convert image data to desired format
RLAPI void ImageToPOT(Image *image, Color fill);                                                         // Convert image to POT (power-of-two)
RLAPI void ImageAlphaPremultiply(Image *image);                                                          // Premultiply alpha channel
RLAPI void ImageResize(Image *image, int newWidth, int newHeight);                                       // Resize image (Bicubic scaling algorithm)
RLAPI void ImageResizeNN(Image *image, int newWidth,int newHeight);                                      // Resize image (Nearest-Neighbor scaling algorithm)
RLAPI void ImageResizeCanvas(Image *image, int newWidth, int newHeight, int offsetX, int offsetY, Color fill);  // Resize canvas and fill with color
RLAPI void ImageMipmaps(Image *image);                                                                   // Generate all mipmap levels for a provided image
RLAPI void ImageDither(Image *image, int rBpp, int gBpp, int bBpp, int aBpp);                            // Dither image data to 16bpp or lower (Floyd-Steinberg dithering)
RLAPI void ImageColorReplace(Image *image, Color color, Color replace);                                  // Modify image color: replace color

RLAPI Color *GetImageData(Image image);                                                                  // Get pixel data from image as a Color struct array
RLAPI Color *GetImagePalette(Image image, int maxPaletteSize, int *extractCount);                        // Get color palette from image to maximum size (memory should be freed)
RLAPI Vector4 *GetImageDataNormalized(Image image);                                                      // Get pixel data from image as Vector4 array (float normalized)
RLAPI Rectangle GetImageAlphaBorder(Image image, float threshold);                                       // Get image alpha border rectangle

RLAPI void ImageDraw(Image *dst, Image src, Rectangle srcRec, Rectangle dstRec, Color tint);             // Draw a source image within a destination image (tint applied to source)
RLAPI void ImageDrawTextEx(Image *dst, Font font, const char *text, Vector2 position, float fontSize, float spacing, Color tint); // Draw text (custom sprite font) within an image (destination)


********************************************************************************************/

#include "raylib.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1350;
    const int screenHeight = 700;

    Rectangle rec = {200,100,800,600};

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    //RLAPI Image LoadImage(const char *fileName);
    Image luck = LoadImage("luck.png");
    //RLAPI Image LoadImageRaw(const char *fileName, int width, int height, int format, int headerSize);
    //Image luck = LoadImageRaw("luck.raw", 800, 600, 7, 20);
    
    //RLAPI void ExportImage(Image image, const char *fileName);
    //ExportImage(luck, "luck.raw"); 

    //RLAPI void ImageCrop(Image *image, Rectangle crop);
    //ImageCrop(&luck, rec);

    //RLAPI void ImageAlphaCrop(Image *image, float threshold);
    //ImageAlphaCrop(&luck,2);

    //RLAPI void ImageAlphaClear(Image *image, Color color, float threshold);
    //ImageAlphaClear(&luck, GOLD, 100);

    //RLAPI void ImageAlphaMask(Image *image, Image alphaMask);
    //ImageAlphaMask(&luck, luck);

    //RLAPI void ImageResize(Image *image, int newWidth, int newHeight);
    //ImageResize(&luck, 200, 200);

    //RLAPI void ImageResizeNN(Image *image, int newWidth,int newHeight);
    //ImageResizeNN(&luck, 400,400);

    //RLAPI void ImageFlipVertical(Image *image);
    //ImageFlipVertical(&luck);

    //RLAPI void ImageFlipHorizontal(Image *image);
    //ImageFlipHorizontal(&luck);

    //RLAPI void ImageRotateCW(Image *image);
    //ImageRotateCW(&luck);

    //RLAPI void ImageRotateCCW(Image *image);
    //ImageRotateCCW(&luck);

    //RLAPI void ImageColorTint(Image *image, Color color);
    //ImageColorTint(&luck, PINK);

    //RLAPI void ImageColorInvert(Image *image);
   //ImageColorInvert(&luck);

    //RLAPI void ImageColorGrayscale(Image *image);
    //ImageColorGrayscale(&luck);

    //RLAPI void ImageColorContrast(Image *image, float contrast);
    //ImageColorContrast(&luck, 60);

    //RLAPI void ImageColorBrightness(Image *image, int brightness);
    //ImageColorBrightness(&luck, 100);

    //void ImageClearBackground(Image *dst, Color color);
    //ImageClearBackground(&luck, WHITE);

    //RLAPI void ImageDrawPixel(Image *dst, int posX, int posY, Color color); 
    //ImageDrawPixel(&luck, 50, 50, BLACK); 

    //RLAPI void ImageDrawPixelV(Image *dst, Vector2 position, Color color);
    //ImageDrawPixelV(&luck, (Vector2){400,100}, BLACK);

    //RLAPI void ImageDrawLine(Image *dst, int startPosX, int startPosY, int endPosX, int endPosY, Color color);
    //ImageDrawLine(&luck, 50, 100, 800, 100, PINK);

    //RLAPI void ImageDrawLineV(Image *dst, Vector2 start, Vector2 end, Color color);
    //ImageDrawLineV(&luck, (Vector2){50,100}, (Vector2){700,100}, SKYBLUE);
    
    //RLAPI void ImageDrawCircle(Image *dst, int centerX, int centerY, int radius, Color color);
    //ImageDrawCircle(&luck, 400, 300, 50, GREEN);


    //RLAPI void ImageDrawCircleV(Image *dst, Vector2 center, int radius, Color color);         
    //ImageDrawCircleV(&luck, (Vector2){350,250}, 50,PINK); 

    //RLAPI void ImageDrawRectangle(Image *dst, int posX, int posY, int width, int height, Color color);
    //ImageDrawRectangle(&luck, 400, 250, 50, 100,SKYBLUE);   

    //RLAPI void ImageDrawRectangleV(Image *dst, Vector2 position, Vector2 size, Color color);
    //ImageDrawRectangleV(&luck, (Vector2){50,200}, (Vector2){100,200},BROWN);

    //RLAPI void ImageDrawRectangleRec(Image *dst, Rectangle rec, Color color);
    //ImageDrawRectangleRec(&luck, (Rectangle){300,400,600,700}, RED);     

    //RLAPI void ImageDrawRectangleLines(Image *dst, Rectangle rec, int thick, Color color);
    //ImageDrawRectangleLines(&luck, (Rectangle){20,40,700,100},8,ORANGE);

    //RLAPI void ImageDrawText(Image *dst, const char *text, int posX, int posY, int fontSize, Color color);
    //ImageDrawText(&luck, "HI", 600,300,50,BLUE);

    //RLAPI Texture2D LoadTextureFromImage(Image image);
    Texture2D luck_texture = LoadTextureFromImage(luck);
    //RLAPI void UnloadImage(Image image);
    UnloadImage(luck);
 
    
    //SetTargetFPS(1);               // Set our game to run at 60 frames-per-second
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

            //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

            //RLAPI void DrawTexture(Texture2D texture, int posX, int posY, Color tint); 
            DrawTexture(luck_texture, 0, 0, WHITE);


        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    //RLAPI void UnloadTexture(Texture2D texture);
    UnloadTexture(luck_texture);

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
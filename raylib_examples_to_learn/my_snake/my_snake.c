#include "raylib.h"

#define SQUARE_SIZE     31
#define SNAKE_LENGTH   256


typedef struct Food {
    Vector2 position;
    Vector2 size;
    bool active;
    Color color;
} Food;

typedef struct Snake {
    Vector2 position;
    Vector2 size;
    Vector2 speed;
    Color color;
} Snake;

static const int screenWidth = 800;
static const int screenHeight = 450;

static int framesCounter = 0;


static Vector2 offset = { 0 };
static Food fruit = { 0 };
static int counterTail = 0;
static Snake snake[SNAKE_LENGTH] = { 0 };



int main(void)
{ 
    InitWindow(screenWidth, screenHeight, "sample game: snake");

    SetTargetFPS(60);

    framesCounter = 0;
    offset.x = screenWidth%SQUARE_SIZE;
    offset.y = screenHeight%SQUARE_SIZE;
    fruit.size = (Vector2){ SQUARE_SIZE, SQUARE_SIZE };
    fruit.color = SKYBLUE;
    int rand_x_value = (GetRandomValue(offset.x/2, screenWidth-(offset.x/2+SQUARE_SIZE))-offset.x/2)/SQUARE_SIZE;
    int rand_y_value = (GetRandomValue(offset.y/2, screenHeight-(offset.y/2+SQUARE_SIZE))-offset.y/2)/SQUARE_SIZE;
    int fruit_integar_x_position = rand_x_value * SQUARE_SIZE + offset.x/2;
    int fruit_integar_y_position = rand_y_value * SQUARE_SIZE + offset.y/2;

    fruit.position = (Vector2){fruit_integar_x_position,fruit_integar_y_position};

    counterTail = 1;
    for (int i = 0; i < SNAKE_LENGTH; i++)
    {
        snake[i].position = (Vector2){ offset.x/2, offset.y/2 };
        snake[i].size = (Vector2){ SQUARE_SIZE, SQUARE_SIZE };
        snake[i].speed = (Vector2){ SQUARE_SIZE, 0 };

        if (i == 0) snake[i].color = DARKBLUE;
        else snake[i].color = BLUE;
    }


while (!WindowShouldClose())
{  
     if (IsKeyPressed(KEY_RIGHT))
            {
                snake[0].speed = (Vector2){ SQUARE_SIZE, 0 };
                snake[0].position.x += snake[0].speed.x;
            }
    if (IsKeyPressed(KEY_LEFT))
            {
                snake[0].speed = (Vector2){ -SQUARE_SIZE, 0 };
                snake[0].position.x += snake[0].speed.x;
            }
    if (IsKeyPressed(KEY_UP))
            {
                snake[0].speed = (Vector2){ 0, -SQUARE_SIZE };
                snake[0].position.y += snake[0].speed.y;
            }
    if (IsKeyPressed(KEY_DOWN))
            {
                snake[0].speed = (Vector2){ 0, SQUARE_SIZE };
                snake[0].position.y += snake[0].speed.y;
            }

    if ((framesCounter%20) == 0)
    { 
     snake[0].position.x += snake[0].speed.x;
     snake[0].position.y += snake[0].speed.y;
    } 
    framesCounter++ ;
    if (CheckCollisionRecs((Rectangle){snake[0].position.x, snake[0].position.y, snake[0].size.x, snake[0].size.y}, (Rectangle){fruit.position.x, fruit.position.y, fruit.size.x,  fruit.position.y}))
                {
                    counterTail += 1;
                }            
                    
    BeginDrawing();

    ClearBackground(RAYWHITE);


    for (int i = 0; i < (screenHeight-offset.y)/SQUARE_SIZE + 1; i++)
    {
        DrawLineV((Vector2){offset.x/2, offset.y/2 + i*SQUARE_SIZE},(Vector2){screenWidth-offset.x/2,  offset.y/2 + i*SQUARE_SIZE}, LIGHTGRAY);
    }   
    for (int i = 0; i < (screenWidth-offset.x)/SQUARE_SIZE + 1; i++)
    {
        DrawLineV((Vector2){offset.x/2 + i*SQUARE_SIZE, offset.y/2},(Vector2){offset.x/2 + i*SQUARE_SIZE, screenHeight-offset.y/2}, LIGHTGRAY);
    }
    DrawRectangleV(fruit.position, fruit.size, fruit.color);

    for (int i = 0; i < counterTail; i++) 
        DrawRectangleV(snake[i].position, snake[i].size, snake[i].color);

    EndDrawing();

} 

CloseWindow();

return 0;   
}
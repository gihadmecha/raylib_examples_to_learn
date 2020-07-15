#include "raylib.h"
#include <math.h>

#define LINES_OF_BRICKS         5
#define BRICKS_PER_LINE        20

typedef struct Player {
    Vector2 position;
    Vector2 size;
    int life;
}Player;

typedef struct Ball {
    Vector2 position;
    Vector2 speed;
    int radius;
    bool active;
} Ball;

typedef struct Brick {
    Vector2 position;
    bool active;
} Brick;

//sohaib
static const int screenWidth = 800;
static const int screenHeight = 450;

static Player player = { 0 };
static Ball ball = { 0 };
static Brick brick[LINES_OF_BRICKS][BRICKS_PER_LINE] = { 0 };
static Vector2 brickSize = { 0 };



int main(void)
{

    InitWindow(screenWidth, screenHeight, "sample game: arkanoid");

    SetTargetFPS(60);

    player.size = (Vector2){screenWidth/4,screenHeight/30};
    player.position = (Vector2){screenWidth/2,screenHeight-screenHeight/5};
    ball.radius = 10;
    ball.position = (Vector2){player.position.x,player.position.y-player.size.y/2-ball.radius};
    ball.speed = (Vector2){0,0};
    ball.active = false;
    brickSize = (Vector2){ GetScreenWidth()/BRICKS_PER_LINE, 40 };
    int initialDownPosition = 50;
    for (int i = 0; i < LINES_OF_BRICKS; i++)
    {
        for (int j = 0; j < BRICKS_PER_LINE; j++)
        {
            brick[i][j].position = (Vector2){ j*brickSize.x + brickSize.x/2, i*brickSize.y + initialDownPosition };
            brick[i][j].active = true;
        }
    }
    

    while (!WindowShouldClose())
    { 
        if (IsKeyDown(KEY_LEFT)) player.position.x -= 2.5;
        if ((player.position.x - player.size.x/2) <= 0) player.position.x = player.size.x/2;
        if (IsKeyDown(KEY_RIGHT)) player.position.x += 2.5;
        if ((player.position.x + player.size.x/2) >= screenWidth) player.position.x = screenWidth - player.size.x/2;
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangle(player.position.x - player.size.x/2, player.position.y - player.size.y/2, player.size.x, player.size.y, BLACK);
        DrawCircleV(ball.position, ball.radius, MAROON);
        for (int i = 0; i < LINES_OF_BRICKS; i++)
        {
                for (int j = 0; j < BRICKS_PER_LINE; j++)
                {
                    if (brick[i][j].active)
                    {    
                        if ((i + j) % 2 == 0) 
                            DrawRectangle(brick[i][j].position.x - brickSize.x/2, brick[i][j].position.y - brickSize.y/2, brickSize.x, brickSize.y, DARKGRAY);
                        else 
                            DrawRectangle(brick[i][j].position.x - brickSize.x/2, brick[i][j].position.y - brickSize.y/2, brickSize.x, brickSize.y, GRAY); 
                    }
                }
        }

        if (!ball.active)
        {
            if (IsKeyPressed(KEY_SPACE))
            {
                   ball.active = true;
                   ball.speed = (Vector2){0, 5};
            }
        }
        if (ball.active)
        {
                ball.position.x += ball.speed.x;
                ball.position.y += ball.speed.y;
        }
        else
        {
               ball.position = (Vector2){player.position.x,player.position.y-player.size.y/2-ball.radius};
        } 

        if (((ball.position.x + ball.radius) >= screenWidth) || ((ball.position.x - ball.radius) <= 0)) ball.speed.x *= -1;
        if ((ball.position.y - ball.radius) <= 0) ball.speed.y *= -1;
        if ((ball.position.y + ball.radius) >= screenHeight)
        {
                ball.speed = (Vector2){ 0, 0 };
                ball.active = false;
        }
        if (CheckCollisionCircleRec(ball.position, ball.radius,
                (Rectangle){ player.position.x - player.size.x/2, player.position.y - player.size.y/2, player.size.x, player.size.y}))
        {
                if (ball.speed.y > 0)
                {
                    ball.speed.y *= -1;
                    //sohaib
                   //ball.speed.x *= -1;
                    ball.speed.x = (ball.position.x - player.position.x)/(player.size.x/2)*5;
                }
        }
        for (int i = 0; i < LINES_OF_BRICKS; i++)
            {
                for (int j = 0; j < BRICKS_PER_LINE; j++)
                {
                    if (brick[i][j].active)
                    {
                       
                        if ((ball.position.y >= brick[i][j].position.y ) && CheckCollisionCircleRec((Vector2){ball.position.x,ball.position.y}, 2*ball.radius,(Rectangle){ brick[i][j].position.x , brick[i][j].position.y, brickSize.x,brickSize.y}))
                        {
                            brick[i][j].active = false;
                            ball.speed.y *= -1;
                        }
                        
                    }
                }
            }
       
                
        EndDrawing();
    }   

    CloseWindow();
    return 0;
}
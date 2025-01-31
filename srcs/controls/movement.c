#include "../../includes/cub3d.h"

void move_w(t_vars *vars)
{
    double nextX;
    double nextY;

    nextX = vars->player.posX + vars->player.dirX * MOVE_SPEED;
    nextY = vars->player.posY + vars->player.dirY * MOVE_SPEED;
    if (vars->map[(int)vars->player.posY][(int)nextX] == '0')
    {
        vars->player.posX = nextX;
    }
    if (vars->map[(int)nextY][(int)vars->player.posX] == '0')
    {
        vars->player.posY = nextY;
    }
}

void move_s(t_vars *vars)
{
    double nextX;
    double nextY;

    nextX = vars->player.posX - vars->player.dirX * MOVE_SPEED;
    nextY = vars->player.posY - vars->player.dirY * MOVE_SPEED;
    if (vars->map[(int)vars->player.posY][(int)nextX] == '0')
    {
        vars->player.posX = nextX;
    }
    if (vars->map[(int)nextY][(int)vars->player.posX] == '0')
    {
        vars->player.posY = nextY;
    }
}

void move_a(t_vars *vars)
{
    double nextX;
    double nextY;

    nextX = vars->player.posX - vars->player.planeX * MOVE_SPEED;
    nextY = vars->player.posY - vars->player.planeY * MOVE_SPEED;
    if (vars->map[(int)nextY][(int)vars->player.posX] == '0')
    {
        vars->player.posY = nextY;
    }
    if (vars->map[(int)vars->player.posY][(int)nextX] == '0')
    {
        vars->player.posX = nextX;
    }
}

void move_d(t_vars *vars)
{
    double nextX;
    double nextY;

    nextX = vars->player.posX + vars->player.planeX * MOVE_SPEED;
    nextY = vars->player.posY + vars->player.planeY * MOVE_SPEED;
    if (vars->map[(int)nextY][(int)vars->player.posX] == '0')
    {
        vars->player.posY = nextY;
    }
    if (vars->map[(int)vars->player.posY][(int)nextX] == '0')
    {
        vars->player.posX = nextX;
    }
}

void move_player(t_vars *vars)
{
    if (vars->keys.w)
        move_w(vars);
    if (vars->keys.s)
        move_s(vars);
    if (vars->keys.a)
        move_a(vars);
    if (vars->keys.d)
        move_d(vars);
    if (vars->keys.left)
        rotate_left(vars);
    if (vars->keys.right)
        rotate_right(vars);
    printf("Player Position: (%.2f, %.2f)\n", vars->player.posX, vars->player.posY);
    printf("Direction Vector: (%.2f, %.2f)\n", vars->player.dirX, vars->player.dirY);
    printf("Plane Vector: (%.2f, %.2f)\n", vars->player.planeX, vars->player.planeY);
    // ベクトルが直交しているか確認
    double dot_product = vars->player.dirX * vars->player.planeX + vars->player.dirY * vars->player.planeY;
    printf("Dot Product (should be ~0): %.5f\n", dot_product);
}
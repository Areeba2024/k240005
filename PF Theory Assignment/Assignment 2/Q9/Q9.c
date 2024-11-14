#include <stdio.h>
#include <stdbool.h>

void print_grid(char grid[5][5])
{
    int i, j;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf(" %c ", grid[i][j]);
        }
        printf("\n");
    }
}

bool game_completion(char grid[5][5])
{
    int i, j;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (grid[i][j] == 'I')
            {
                return true; 
            }
        }
    }
    printf("\nCongratulations! You have collected all the items!\n");
    return false;
}

bool player_movement(char grid[5][5], int *item_collected)
{
    char input;
    int i, j, player_i = -1, player_j = -1;
    printf("Enter (W: up, S: down, A: left, D: right, Q: quit): ");
    scanf(" %c", &input);

    // Locate the player's position
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (grid[i][j] == 'P')
            {
                player_i = i;
                player_j = j;
                break;
            }
        }
        if (player_i != -1)
            break; 
    }

    int newpos_i = player_i, newpos_j = player_j;

    switch (input)
    {
    case 'W':
        newpos_i = player_i - 1;
        break;
    case 'S':
        newpos_i = player_i + 1;
        break;
    case 'A':
        newpos_j = player_j - 1;
        break;
    case 'D':
        newpos_j = player_j + 1;
        break;
    case 'Q':
        printf("Exiting game!\n");
        return false;
    default:
        printf("Invalid move!\n");
        return true;
    }

    if (newpos_i >= 0 && newpos_i < 5 && newpos_j >= 0 && newpos_j < 5)
    {
        if (grid[newpos_i][newpos_j] == 'X')
        {
            printf("Obstacle ahead!\n");
        }
        else if (grid[newpos_i][newpos_j] == 'I')
        {
            (*item_collected)++;
            grid[player_i][player_j] = '_';
            grid[newpos_i][newpos_j] = 'P';
        }
        else
        {
            grid[player_i][player_j] = '_';
            grid[newpos_i][newpos_j] = 'P';
        }
    }
    else
    {
        printf("\nLAND LOCKED!! YOU CAN'T MOVE AHEAD\n");
    }
    return true;
}

int main()
{
    int item_collected = 0;
    char grid[5][5] = {
        {'_', '_', 'I', 'X', '_'},
        {'_', 'X', '_', '_', '_'},
        {'I', '_', 'X', 'X', '_'},
        {'_', '_', '_', 'I', 'X'},
        {'_', 'X', '_', '_', 'P'},
    };

    
    while (true)
    {
        print_grid(grid);
        printf("Items collected: %d\n", item_collected);

        if (!player_movement(grid, &item_collected))
            break;

        if (!game_completion(grid))
            break;
    }
    print_grid(grid);
    printf("Game over! You collected %d items.\n", item_collected);
    return 0;
}

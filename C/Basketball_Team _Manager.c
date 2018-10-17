#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

struct Games{
    float points;
    float assists;
    float rebounds;
};

struct Players{
    char name[20];
    char position;
    struct Games game;
};

void new_player(struct Players *player){
    printf("Enter new player's name.\n");
    scanf(" %s", &(player->name));
    printf("Enter his position(C,F,G).\n");
    scanf(" %c", &(player->position));
    printf("Enter total points, assists, rebounds so far.\n");
    scanf(" %f,%f,%f",&(player->game.points), &(player->game.assists), &(player->game.rebounds));

    //

}

void stats(struct Players *player, float totalgames){
    printf("Average points: %f\nAverage assists: %f\nAverage rebounds: %f\n", player->game.points / totalgames,
           player->game.assists / totalgames,
           player->game.rebounds / totalgames);

    printf("Games played: %f\n", totalgames);
}


void input(struct Players *player){
    float x,y,z;
    printf("Enter %s 's last game stats\n", player->name);
    scanf(" %f,%f,%f", &x, &y, &z);
    player->game.points += x;
    player->game.assists += y;
    player->game.rebounds += z;
}

int main(){
    int choice;
    float totalgames = 10;
    char pl[50];
    struct Players player1;
    struct Games game1;
    do{printf("Basketball Team Manager!\nChoose your option\n1.Enter a new player\n2.Average stats for a player\n3.Insert last game stats\n4.Quit\n");
        scanf(" %d", &choice);
        switch(choice){
            case 1: new_player(&player1);
                break;
            case 2: stats(&player1,totalgames);
                break;
            case 3: totalgames += 1;
                input(&player1);
                break;
            case 4: return 0;
            default: return 1;
        }
    }while(choice!=4);




}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char firstname[50];
    char lastname[50];
    int numeroMaillot;
    char poste[50];
    int age;
    int buts;
} Player;

Player players[500];
int countPlayers = 0;

void addPlayer();
void showPlayers();
void addPlayerMainMenu();
void addmorePlayers();

int main() {
    int choix;
    do {
        printf("==== MENU ====\n");
        printf("1. Add new player\n");
        printf("2. Show all players\n");
        printf("0. Quit\n");
        printf("Choose: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: addPlayerMainMenu(); break;
            case 2: showPlayers(); break;
            case 0: printf("Bye!\n");return 0; 
            default: printf("Invalid Choice!\n"); break;
        }
    } while (choix != 0);
    return 0;
}
void addPlayerMainMenu(){
    int choix;
    do{
    printf("1.Add 1 player\n");
    printf("2.Add More than 1 Player\n");
    printf("0.Go Back To MainMenu\n");
    printf("Choose: ");
    scanf("%d",&choix);

    switch (choix){
        case 1:addPlayer();break;
        case 2:addmorePlayers();break;
        case 0:system("cls");main();break;
        default:printf("Invalid Choice!\n");break;
    }
        
    }while ( choix != 0);
}
void addPlayer() {
    system("cls");
    printf("=== ADDING PLAYER ===\n");

    printf("Enter player first name: ");
    scanf("%s", players[countPlayers].firstname);

    printf("Enter player last name: ");
    scanf("%s", players[countPlayers].lastname);

    printf("Enter shirt number: ");
    scanf("%d", &players[countPlayers].numeroMaillot);

    printf("Enter age: ");
    scanf("%d", &players[countPlayers].age);

    printf("Enter position: ");
    scanf("%s", players[countPlayers].poste);

    printf("Enter goals: ");
    scanf("%d", &players[countPlayers].buts);

    players[countPlayers].id = countPlayers + 1;

    printf("\n=== Player Added Successfully ===\n");
    printf("ID: %d\n", players[countPlayers].id);
    printf("Name: %s %s\n", players[countPlayers].firstname, players[countPlayers].lastname);
    printf("Age: %d\n", players[countPlayers].age);
    printf("Shirt Number: %d\n", players[countPlayers].numeroMaillot);
    printf("Poste: %s\n", players[countPlayers].poste);
    printf("Goals: %d\n", players[countPlayers].buts);
    printf("===============================\n");

    countPlayers++;
    system("pause");
    system("cls");
    main();
}

void showPlayers() {
    if (countPlayers == 0) {
        printf("No players added yet!\n");
        return;
    }

    printf("=== LIST OF PLAYERS ===\n");
    for (int i = 0; i < countPlayers; i++) {
        printf("ID: %d | %s %s | Age: %d | Shirt: %d | Poste: %s | Goals: %d\n",
               players[i].id, players[i].firstname, players[i].lastname,
               players[i].age, players[i].numeroMaillot, players[i].poste, players[i].buts);
    }
    printf("========================\n");
    system("pause");
    system("cls");
}


void addmorePlayers(){
    int times;
    printf("How many players you want to enter : ");
    scanf("%d",&times);
    for(int i = 0 ; i < times ; i++){
        system("cls");
    printf("=== ADDING PLAYER ===\n");

    printf("Enter player first name: ");
    scanf("%s", players[countPlayers].firstname);

    printf("Enter player last name: ");
    scanf("%s", players[countPlayers].lastname);

    printf("Enter shirt number: ");
    scanf("%d", &players[countPlayers].numeroMaillot);

    printf("Enter age: ");
    scanf("%d", &players[countPlayers].age);

    printf("Enter position: ");
    scanf("%s", players[countPlayers].poste);

    printf("Enter goals: ");
    scanf("%d", &players[countPlayers].buts);

    players[countPlayers].id = countPlayers + 1;

    printf("\n=== Player Added Successfully ===\n");
    printf("ID: %d\n", players[countPlayers].id);
    printf("Name: %s %s\n", players[countPlayers].firstname, players[countPlayers].lastname);
    printf("Age: %d\n", players[countPlayers].age);
    printf("Shirt Number: %d\n", players[countPlayers].numeroMaillot);
    printf("Poste: %s\n", players[countPlayers].poste);
    printf("Goals: %d\n", players[countPlayers].buts);
    printf("===============================\n");

    countPlayers++;
    system("pause");
    system("cls");
    }
    main();
}
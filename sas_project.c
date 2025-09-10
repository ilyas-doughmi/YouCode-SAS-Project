#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
typedef struct
{
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
void showPlayersMenu();
void showpAlphabete();
void triwithage();
void triwithposte();
void search(int number);
void searchwithlastname(int number);
void searchwithid(int number);
void triwithname();
void modifie(int i);
void modfieposte(int i);
void modifieage(int i);
void modifiebuts(int i);
int checkrandom(int random);

int main()
{
    int choix;
    do
    {
        printf("==== MENU ====\n");
        printf("1. Add new player\n");
        printf("2. Show all players\n");
        printf("3. Search Player\n");
        printf("4. Edit Player\n");
        printf("5. Delete Player\n");
        printf("0. Quit\n");
        printf("Choose: ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            addPlayerMainMenu();
            break;
        case 2:
            showPlayersMenu();
            break;
        case 3:
            search(1);
            break;
        case 4:
            search(2);
            break;
        case 5:
            search(3);
            break;
        case 0:
            printf("Bye!\n");
            return 0;
        default:
            printf("Invalid Choice!\n");
            break;
        }
    } while (choix != 0);
    return 0;
}
void addPlayerMainMenu()
{
    system("cls");
    printf("=========== ADDING PLAYER ==============\n");
    int choix;
    do
    {
        printf("1.Add 1 player\n");
        printf("2.Add More than 1 Player\n");
        printf("0.Go Back To MainMenu\n");
        printf("Choose: ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            addPlayer();
            break;
        case 2:
            addmorePlayers();
            break;
        case 0:
            system("cls");
            main();
            break;
        default:
            printf("Invalid Choice!\n");
            break;
        }

    } while (choix != 0);
}
void addPlayer()
{
    int random;
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

    srand(time(NULL));
    do
    {
        random = rand() % 99999 + 10000;
    } while (checkrandom(random) != 0);

    players[countPlayers].id = random;

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

void showPlayersMenu()
{

    if (countPlayers == 0)
    {
        printf("No players added yet!\n");
        return;
    }
    int choix;

    do
    {
        printf("========== SHOW PLAYERS ============\n");
        printf("1.in Alphabete order\n");
        printf("2.in Players AGE\n");
        printf("3.Show Players with Poste\n");
        printf("4.Back to Main Menu\n");
        printf("Choose : ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            triwithname();
            break;
        case 2:
            triwithage();
            break;
        case 3:
            triwithposte();
            break;
        case 4:
            main();
            break;
        default:
            printf("invalid Choice\n");
        }
    } while (choix != 0);
}
void showPlayers()
{

    if (countPlayers == 0)
    {
        printf("No players added yet!\n");
        return;
    }

    printf("=== LIST OF PLAYERS ===\n");
    for (int i = 0; i < countPlayers; i++)
    {
        printf("ID: %d | %s %s | Age: %d | Shirt: %d | Poste: %s | Goals: %d\n",
               players[i].id, players[i].firstname, players[i].lastname,
               players[i].age, players[i].numeroMaillot, players[i].poste, players[i].buts);
    }
    printf("========================\n");
    system("pause");
    system("cls");
}

void addmorePlayers()
{
    int times;
    printf("How many players you want to enter : ");
    scanf("%d", &times);
    int random;
    for (int i = 0; i < times; i++)
    {
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
        srand(time(NULL));
        do
        {
            random = rand() % 99999 + 10000;
        } while (checkrandom(random) != 0);

        players[countPlayers].id = random;

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

void triwithage()
{
    if (countPlayers == 0)
    {
        printf("No Player\n");
        return;
    }

    for (int i = 0; i < countPlayers - 1; i++)
    {
        for (int j = i + 1; j < countPlayers; j++)
        {
            if (players[i].age > players[j].age)
            {
                Player temp = players[i];
                players[i] = players[j];
                players[j] = temp;
            }
        }
    }

    showPlayers();
}

void triwithname()
{
    if (countPlayers == 0)
    {
        printf("No Player\n");
        return;
    }

    for (int i = 0; i < countPlayers - 1; i++)
    {
        for (int j = i + 1; j < countPlayers; j++)
        {
            if (strcmp(players[i].lastname, players[j].lastname) > 0)
            {
                Player temp = players[i];
                players[i] = players[j];
                players[j] = temp;
            }
        }
    }

    showPlayers();
}

void triwithposte()
{
    if (countPlayers == 0)
    {
        printf("No Player\n");
        return;
    }
    for (int i = 0; i < countPlayers - 1; i++)
    {
        for (int j = i + 1; j < countPlayers; j++)
        {
            if (strcmp(players[i].poste, players[j].poste) > 0)
            {
                Player temp = players[i];
                players[i] = players[j];
                players[j] = temp;
            }
        }
    }

    showPlayers();
}

void search(int number)
{
    int choix;
    printf("1. Search with ID\n");
    printf("2. Search with lastname\n");
    printf("Choose : ");
    scanf("%d", &choix);
    switch (choix)
    {
    case 1:
        searchwithid(number);
        break;
    case 2:
        searchwithlastname(number);
        break;
    default:
        printf("Invalid Choice\n");
        break;
    }
}

void searchwithid(int number)
{
    int idsearch;
    if (countPlayers == 0)
    {
        printf("No Player\n");
        return;
    }
    printf("Give me ID: ");
    scanf(" %d", &idsearch);
    bool found = false;
    int choix;
    for (int i = 0; i < countPlayers; i++)
    {
        if (idsearch == players[i].id)
        {
            printf("Found It\n");
            printf("ID: %d | %s %s | Age: %d | Shirt: %d | Poste: %s | Goals: %d\n",
                   players[i].id, players[i].firstname, players[i].lastname,
                   players[i].age, players[i].numeroMaillot, players[i].poste, players[i].buts);

            if (number == 2)

            {
                do
                {
                    printf("1.Edit Player\n2. Back To MainMenu\nChoose: ");
                    scanf("%d", &choix);

                    switch (choix)
                    {
                    case 1:
                        modifie(i);
                        break;
                    case 2:
                        main();
                        break;
                    default:
                        printf("Invalid Choice\n");
                        break;
                    }
                } while (choix != 0);
            }

            if (number == 3)
            {
                do
                {
                    printf("Do you want to delete this player : \n");
                    printf("1. DELETE\n");
                    printf("2. RETURN TO MAIN MENU\n");
                    scanf("%d", &choix);

                    switch (choix)
                    {
                    case 1:
                        delete(i);
                        break;
                    case 2:
                        main();
                        break;
                    default:
                        printf("invalid Choice\n");
                        break;
                    }
                } while (choix != 0);
            }

            found = true;
        }
    }

    if (!found)
    {
        printf("Not Found\n");
    }
}

void searchwithlastname(int number)
{
    int idsearch;
    int choix;
    bool found = false;
    if (countPlayers == 0)
    {
        printf("No Player\n");
        return;
    }
    char namesearch[500];
    printf("Enter a Last name of player you want to search for : ");
    scanf("%s", namesearch);

    for (int i = 0; i < countPlayers; i++)
    {
        if (strcmp(namesearch, players[i].lastname) == 0)
        {
            printf("Found it\n");
            printf("ID: %d | %s %s | Age: %d | Shirt: %d | Poste: %s | Goals: %d\n",
                   players[i].id, players[i].firstname, players[i].lastname,
                   players[i].age, players[i].numeroMaillot, players[i].poste, players[i].buts);
            if (number == 2)
            {
                do
                {
                    printf("1.Edit Player\n2. Back To MainMenu\nChoose: ");
                    scanf("%d", &choix);

                    switch (choix)
                    {
                    case 1:
                        modifie(i);
                        break;
                    case 2:
                        main();
                        break;
                    default:
                        printf("Invalid Choice\n");
                        break;
                    }
                } while (choix != 0);
            }

            found = true;
            break;
        }
    }
    if (!found)
    {
        printf("Not Found\n");
    }
}

void modifie(int i)
{
    system("cls");
    printf("===== EDIT %s %s DATA =========\n", players[i].firstname, players[i].lastname);
    int choix;
    getchar();
    do
    {
        printf("1.Edit Player Poste\n2. Edit Age\n3. Edit Buts\n4.Go Back to MainMenu\nChoose : ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            modfieposte(i);
            break;
        case 2:
            modifieage(i);
            break;
        case 3:
            modifiebuts(i);
            break;
        case 4:
            main();
            break;

        default:
            printf("Invalide Choice\n");
            break;
        }
    } while (choix != 0);
}

void modfieposte(int i)
{
    system("cls");
    char newposte[500];
    printf("===== EDIT %s %s POSTE =========\n", players[i].firstname, players[i].lastname);
    printf("Enter new Poste for %s : ", players[i].lastname);
    scanf("%s", &newposte);
    strcpy(players[i].poste, newposte);

    printf("Player Poste Updated Successfully....\n");
    printf("New Poste is : %s\n", players[i].poste);
}

void modifieage(int i)
{
    system("cls");

    int newage;
    printf("===== EDIT %s %s AGE =========\n", players[i].firstname, players[i].lastname);
    printf("Enter new age for %s : ", players[i].lastname);
    scanf("%d", &newage);
    players[i].age = newage;

    printf("Player Poste Updated Successfully....\n");
    printf("New Poste is : %d\n", players[i].age);
}

void modifiebuts(int i)
{
    system("cls");

    int newbuts;
    printf("===== EDIT %s %s AGE =========\n", players[i].firstname, players[i].lastname);
    printf("Enter new buts for %s : ", players[i].lastname);
    scanf("%d", &newbuts);
    players[i].buts = newbuts;

    printf("Player Poste Updated Successfully....\n");
    printf("New Poste is : %d\n", players[i].age);
}

int checkrandom(int random)
{
    if (countPlayers == 0)
    {
        return 0;
    }
    for (int i = 0; i < countPlayers; i++)
    {
        if (random == players[i].id)
        {
            return 1;
        }
    }

    return 0;
}

void delete(int i)
{
    for(int i = 0 ; i < countPlayers ; i++){
        
    }
}
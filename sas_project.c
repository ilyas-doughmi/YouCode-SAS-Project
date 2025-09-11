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
bool setuped = false;

void addPlayer();
void showPlayers();
void addPlayerMainMenu();
void addmorePlayers();
void showPlayersMenu();
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
void delete(int i);
void statistique();
void totalmembers();
void averageage();
void biggerbuts();
void lowertobigger();
void showPlayersWithMoreGoals(); 
void mockdata();

int main()
{

    if(setuped == false){
        mockdata();
        setuped = true;
    }
    int choix;
    do
    {
        printf("==== MENU ====\n");
        printf("1. Add new player\n");
        printf("2. Show all players\n");
        printf("3. Search Player\n");
        printf("4. Edit Player\n");
        printf("5. Delete Player\n");
        printf("6. Statistiques\n");
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
        case 6:
            statistique();
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
        printf("1. Add 1 player\n");
        printf("2. Add More than 1 Player\n");
        printf("0. Go Back To MainMenu\n");
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
    do{
        if(players[countPlayers].numeroMaillot < 0){
            printf("Shirt number cannot be negative. Please enter again: ");
            scanf("%d", &players[countPlayers].numeroMaillot);
        }
    }while(players[countPlayers].numeroMaillot < 0);

    printf("Enter age: ");
    scanf("%d", &players[countPlayers].age);

    do{
        if(players[countPlayers].age < 0){
            printf("Age cannot be negative. Please enter again: ");
            scanf("%d", &players[countPlayers].age);
        }
    }while(players[countPlayers].age < 0);

    printf("Enter position: ");
    scanf("%s", players[countPlayers].poste);

    printf("Enter goals: ");
    scanf("%d", &players[countPlayers].buts);

    do{
        if(players[countPlayers].buts < 0){
            printf("Goals cannot be negative. Please enter again: ");
            scanf("%d", &players[countPlayers].buts);
        }
    }while(players[countPlayers].buts < 0);

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
               players[i].id,  players[i].lastname,players[i].firstname,
               players[i].age, players[i].numeroMaillot, players[i].poste, players[i].buts);
    }
    printf("========================\n");
    system("pause");
    system("cls");
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
        printf("1. Alphabetical order (Lastname)\n");
        printf("2. By Age\n");
        printf("3. By Poste\n");
        printf("4. Back to Main Menu\n");
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
            printf("Invalid Choice\n");
        }
    } while (choix != 0);
}

void triwithage()
{
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
    for (int i = 0; i < countPlayers - 1; i++)
    {
        for (int j = i + 1; j < countPlayers; j++)
        {
            if (stricmp(players[i].lastname, players[j].lastname) > 0)
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
    char posterequested[50];
    printf("Enter Poste you want to filter by : ");
    scanf("%s", posterequested);
    for (int i = 0; i < countPlayers - 1; i++){
        if(strcmp(players[i].poste, posterequested) == 0){
            printf("ID: %d | %s %s | Age: %d | Shirt: %d | Poste: %s | Goals: %d\n",
               players[i].id, players[i].firstname, players[i].lastname,
               players[i].age, players[i].numeroMaillot, players[i].poste, players[i].buts);
        }
    }
    // for (int i = 0; i < countPlayers - 1; i++)
    // {
    //     for (int j = i + 1; j < countPlayers; j++)
    //     {
    //         if (strcmp(players[i].poste, players[j].poste) > 0)
    //         {
    //             Player temp = players[i];
    //             players[i] = players[j];
    //             players[j] = temp;
    //         }
    //     }
    // }
    // showPlayers();
}

void search(int number)
{
    if (countPlayers == 0)
    {
        printf("No Player\n");
        return;
    }

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
                    printf("1. Edit Player\n2. Back To MainMenu\nChoose: ");
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
                    printf("Are u sure you want to delete %s (1) Yes // (2) NO : \n");
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
    char namesearch[500];
    int choix;
    bool found = false;
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
                    printf("1. Edit Player\n2. Back To MainMenu\nChoose: ");
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
    do
    {
        printf("1. Edit Player Poste\n2. Edit Age\n3. Edit Goals\n4. Go Back to MainMenu\nChoose : ");
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
            printf("Invalid Choice\n");
            break;
        }
    } while (choix != 0);
}

void modfieposte(int i)
{
    char newposte[500];
    printf("Enter new Poste for %s : ", players[i].lastname);
    scanf("%s", newposte);
    strcpy(players[i].poste, newposte);
    printf("Player Poste Updated Successfully....\n");
}

void modifieage(int i)
{
    int newage;
    printf("Enter new age for %s : ", players[i].lastname);
    scanf("%d", &newage);
    players[i].age = newage;
    printf("Player Age Updated Successfully....\n");
}

void modifiebuts(int i)
{
    int newbuts;
    printf("Enter new goals for %s : ", players[i].lastname);
    scanf("%d", &newbuts);
    players[i].buts = newbuts;
    printf("Player Goals Updated Successfully....\n");
}

int checkrandom(int random)
{
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
    for (int j = i; j < countPlayers - 1; j++)
    {
        players[j] = players[j + 1];
    }
    countPlayers--;
    printf("Deleted Successfully\n");
    main();
}

void statistique()
{
    system("cls");
    if (countPlayers == 0)
    {
        printf("\nNo Player FOUND\n\n");
        return;
    }

    int choix;

    do
    {
        printf("========== STATISTIQUES ============\n");
        printf("1. Total Team Members\n");
        printf("2. Show Average Age\n");
        printf("3. Players with more than X goals\n");
        printf("4. Best Player in Goals\n");
        printf("5. Youngest and Oldest Player\n");
        printf("0. Back To Main Menu\n");
        printf("Choose: ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            totalmembers();
            break;
        case 2:
            averageage();
            break;
        case 3:
            showPlayersWithMoreGoals();
            break;
        case 4:
            biggerbuts();
            break;
        case 5:
            lowertobigger();
            break;
        case 0:
            main();
            break;
        default:
            printf("Invalid Input\n\n");
            break;
        }
    } while (choix != 0);
}

void totalmembers()
{
    printf("\n\nTotal Players in team are %d\n\n", countPlayers);
    system("pause");
    system("cls");
}

void averageage()
{
    int sum = 0;
    for (int i = 0; i < countPlayers; i++)
    {
        sum += players[i].age;
    }
    printf("Average of age in team : %d\n\n", sum / countPlayers);
    system("pause");
    system("cls");
}

void biggerbuts()
{
    int bigger = players[0].buts;
    int save = 0;
    for (int i = 0; i < countPlayers; i++)
    {
        if (bigger < players[i].buts)
        {
            bigger = players[i].buts;
            save = i;
        }
    }
    printf("\nThe Max Goals is %d scored by %s %s\n\n", players[save].buts, players[save].firstname, players[save].lastname);
    system("pause");
    system("cls");
}

void lowertobigger()
{
    int small = players[0].age;
    int bigger = players[0].age;
    int save1 = 0;
    int save2 = 0;

    for (int i = 0; i < countPlayers; i++)
    {
        if (bigger < players[i].age)
        {
            bigger = players[i].age;
            save1 = i;
        }
        if (small > players[i].age)
        {
            small = players[i].age;
            save2 = i;
        }
    }
    printf("\nThe Oldest Player is %s %s with %d years \n", players[save1].firstname, players[save1].lastname, players[save1].age);
    printf("\nThe Youngest Player is %s %s with %d years \n", players[save2].firstname, players[save2].lastname, players[save2].age);
    printf("\n\n");
    system("pause");
    system("cls");
}


void showPlayersWithMoreGoals()
{
    if (countPlayers == 0)
    {
        printf("\nNo players in the team!\n\n");
        return;
    }

    int x;
    printf("Enter the minimum number of goals: ");
    scanf("%d", &x);

    bool found = false;
    printf("\n=== Players with more than %d goals ===\n", x);
    for (int i = 0; i < countPlayers; i++)
    {
        if (players[i].buts > x)
        {
            printf("ID: %d | %s %s | Age: %d | Shirt: %d | Poste: %s | Goals: %d\n",
                   players[i].id, players[i].firstname, players[i].lastname,
                   players[i].age, players[i].numeroMaillot, players[i].poste, players[i].buts);
            found = true;
        }
    }

    if (!found)
    {
        printf("No player has scored more than %d goals.\n", x);
    }

    printf("=======================================\n\n");
    system("pause");
    system("cls");
}


void mockdata() {
    srand(time(NULL));
    char *firstnames[] = {"Mustapha", "Ahmed", "Abdelmajid", "Salaheddine", "Badou",
                          "Noureddine", "Youssef", "Hakim", "Achraf", "Walid"};
    char *lastnames[]  = {"Hajji", "Faras", "Dolmy", "Bassir", "Zaki",
                          "Naybet", "En-Nesyri", "Ziyech", "Hakimi", "Regragui"};
    char *postes[]     = {"Midfielder", "Forward", "Midfielder", "Forward", "Goalkeeper",
                          "Defender", "Forward", "Midfielder", "Defender", "Defender"};
    int ages[]         = {52, 76, 66, 51, 64, 54, 27, 31, 25, 49};  
    int shirts[]       = {8, 9, 10, 7, 1, 5, 9, 7, 2, 3};
    int buts[]         = {50, 100, 30, 70, 0, 15, 40, 25, 10, 5};

    for (int i = 0; i < 10; i++) {
        strcpy(players[countPlayers].firstname, firstnames[i]);
        strcpy(players[countPlayers].lastname, lastnames[i]);
        strcpy(players[countPlayers].poste, postes[i]);
        players[countPlayers].age = ages[i];
        players[countPlayers].numeroMaillot = shirts[i];
        players[countPlayers].buts = buts[i];

        int random;
        do {
            random = rand() % 99999 + 10000;  
        } while (checkrandom(random) != 0);

        players[countPlayers].id = random;
        countPlayers++;
    }
}
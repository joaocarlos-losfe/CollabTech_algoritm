#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// my fuctions 
#include "screens.h"
#include "keyboard.h"

int main()
{
    system("clear");

    FILE *user_permited = fopen("user_permited.dat", "a"); // autorizadas para adicionar um novo collab e quem pegou determinado collab
    FILE *information_services = fopen("information_services.dat", "a"); // detalhes do servviço cadastrado
    
    int sC = 44, sL = 193;
    char screen_main[sC][sL];

    int cC = 10, cL = 30; //card cmprimento, card largura
    char card[cC][cL];

    // init interface

    GenerateEmptyWindow(sC, sL, screen_main);

    char screen_menu[][100] = {"Add User Permition", "Add Service", "All collabs", "Search Collabs"};
    int i = 0;
    int l_menu_left = 2;

    for(i=0; i<4; i++)
    {
        insertAsciiScreen(l_menu_left, 4, sC, sL, screen_main, screen_menu[i]);
        l_menu_left+=2;
    }

    l_menu_left = 2;
    screen_main[l_menu_left][2] = ']';

    insertAsciiScreen(1, 28, sC, sL, screen_main, "User: ");
    insertAsciiScreen(3, 93, sC, sL, screen_main, "All colabs");
    

    InsertLine(sC, sL, 1, 26, sC, screen_main, 1, '|');
    InsertLine(sC, sL, 2, 27, 166, screen_main, 0, '-');

    //end interface--------------------------

    char keyboard_action = '\0';
    int keyboard_selected = 0;

    while (1)
    {
        system("clear");
        ShowWindow(sC, sL, screen_main);
        keyboard_action = getch();
        //printf("%d", (int)keyboard_action);
        KeyboardEventDraw(&l_menu_left, keyboard_action, sC, sL, screen_main, &keyboard_selected);
        //printf("%s",screen_menu[keyboard_selected]);

    }
    
    
    

    return 0;
}
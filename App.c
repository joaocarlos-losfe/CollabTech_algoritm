#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// my fuctions 
#include "window.h"

int main()
{
    FILE *user_permited = fopen("user_permited.dat", "a"); // autorizadas para adicionar um novo collab e quem pegou determinado collab
    FILE *information_services = fopen("information_services.dat", "a"); // detalhes do servviço cadastrado
    
    int sC = 20, sL = 80;
    char screen_main[sC][sL];
    GenerateEmptyWindow(sC, sL, screen_main);
    char screen_menu[][100] = {"1 - Add User Permition", "2 - Add Service", "3 - All collabs", "4 - Search Collabs"};
    int i = 0;
    int l = 1;

    for(i=0; i<4; i++)
    {
        insertAsciiScreen(l, 30, sC, sL, screen_main, screen_menu[i]);
        l++;
    }
    
    ShowWindow(sC, sL, screen_main);

    
    return 0;
}
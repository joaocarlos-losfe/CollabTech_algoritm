#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// gera uma 'jenela' vazia para inser��o de outras
void GenerateEmptyWindow(int c, int l, char windows[c][l])
{
	//printf("window create...%dx%d\n", c, l);
	int i,j;
	for(i=0; i<c; i++)
	{
		for(j=0; j<l; j++)
		{
			if(i==0 || i== c-1)
			{
				windows[i][j] = '-';
			}
			else
			{
				windows[i][j] = ' ';
			}
			
		}
	}
}

void ShowWindow(int c, int l, char windows[c][l])
{
	int i,j;
	
	for(i=0; i<c; i++)
	{
		for(j=0; j<l; j++)
		{
			printf("%c",windows[i][j]);
		}
		printf("\n");
	}
}

// insere a janela na tela. necessario ter una janela vazia criada antes
void CreateWindow(int c, int l, char empty_window[c][l], int c1, int l1, char window[c1][l1], int coordinateX, int coordinateY)
{
	
	int i, j;
	int y = coordinateY;
	int x = coordinateX;
	
	for(i=0; i<c1; i++)
	{
		for(j=0; j<l1; j++)
		{
			empty_window[x][y] = window[i][j];
			y++;
		}
		y = coordinateY;
		x++;
	}	
			
}

//inserir textos em determinada posição na matriz
void insertAsciiScreen(int position_Line, int position_Colunn, int qtd_l, int qtd_c, char screen[qtd_l][qtd_c], char text[100])
{
	int i = 0;

	while (text[i] != '\0')
	{
		screen[position_Line][position_Colunn] = text[i];
		i++;
		position_Colunn++;
	}
	
}

void InsertLine(int dl, int dc, int l, int c, int dimension, char screen[dl][dc], int direction, char character)
{
	int i, j;

	if (direction == 0)
	{
		
		for (j=0; j<dimension; j++)
		{
			screen[l][c] = character;
			c++;
		}
	}
	else
	{
		
		for (i=0; i<dimension; i++)
		{
			screen[l][c] = character;
			l++;
		}
	}
	
}
#include <stdio.h>
#include <time.h>
#include <stdlib.h>  //Se incluyen las bibliotecas

void loop (char c[3][3]);
void Numeros (char c[3][3]);
void tablero (char c[3][3]);
void Jugador_1 (char c[3][3]);
void Jugador_2 (char c[3][3]);
int ganador(char c[3][3]);

int main (){
  char c[3][3];  //Se crea matriz de 3 x 3
  loop (c);  // Se crea función loop y se le pasa c
  return 0;  // Loop llama a todas las funciones y actualiza pantalla
}

void loop (char c[3][3]){
  int i,j;
  i = 0;
  Numeros(c);
  do{
    system("clear"); //Borra todo lo que hay en pantalla
    tablero(c);

    if(i % 2 == 0){
      Jugador_1(c);
    }
    else{
      Jugador_2(c);
    }
    j = ganador(c);
    i++;
  }while(i <= 9 && j == 2);

  system("clear"); //Borra todo lo que hay en pantalla
  tablero(c);

  if(j == 0){
    printf("El jugador 1 ha ganado\n");
  }if(j == 1){
    printf("El jugador 2 ha ganado\n");
  }if(j == 2){
    printf("Empate! Inténtalo de nuevo!");
  }
}

void Numeros (char c[3][3]){ //Se utiliza para meterle valores a la matriz
  int i, j;  // Contadores
  char x;  //
  x = '1';
  for (i = 0; i < 3; i++){  //Recorre filas
    for(j = 0; j < 3; j++){  //Recorre columnas
      c[i][j] = x++;
    }
  }
}

void Jugador_1 (char c[3][3]){
  int i, j, k;
  char x;

  do{
    do{
      printf("Coloca una ficha jugador 1: \n");
      fflush (stdin);
      scanf ("%c", &x);
    }while(x < '1' || x > '9');

    k = 0;

    switch (x){  // Se comprueba que casilla no esté ocupada
      case '1': {
        i = 0;
        j = 0;
        if (c[i][j] == 'X' || c[i][j] == 'O'){
          k = 1;
          printf("Inténtalo de nuevo\n\n");
        }
        break;
      }
      case '2': {
        i = 0;
        j = 1;
        if (c[i][j] == 'X' || c[i][j] == 'O'){
          k = 1;
          printf("Inténtalo de nuevo\n\n");
        }
        break;
      }
      case '3': {
        i = 0;
        j = 2;
        if (c[i][j] == 'X' || c[i][j] == 'O'){
          k = 1;
          printf("Inténtalo de nuevo\n\n");
        }
        break;
      }
      case '4': {
        i = 1;
        j = 0;
        if (c[i][j] == 'X' || c[i][j] == 'O'){
          k = 1;
          printf("Inténtalo de nuevo\n\n");
        }
        break;
      }
      case '5': {
        i = 1;
        j = 1;
        if (c[i][j] == 'X' || c[i][j] == 'O'){
          k = 1;
          printf("Inténtalo de nuevo\n\n");
        }
        break;
      }
      case '6': {
        i = 1;
        j = 2;
        if (c[i][j] == 'X' || c[i][j] == 'O'){
          k = 1;
          printf("Inténtalo de nuevo\n\n");
        }
        break;
      }
      case '7': {
        i = 2;
        j = 0;
        if (c[i][j] == 'X' || c[i][j] == 'O'){
          k = 1;
          printf("Inténtalo de nuevo\n\n");
        }
        break;
      }
      case '8': {
        i = 2;
        j = 1;
        if (c[i][j] == 'X' || c[i][j] == 'O'){
          k = 1;
          printf("Inténtalo de nuevo\n\n");
        }
        break;
      }
      case '9': {
        i = 2;
        j = 2;
        if (c[i][j] == 'X' || c[i][j] == 'O'){
          k = 1;
          printf("Inténtalo de nuevo\n\n");
        }
        break;
      }
    }
  }while (k == 1);
  c[i][j] = 'X';  // Se introduce el valor de X
}

void Jugador_2 (char c[3][3]){
  int i, j, k;
  char x;

  do{
    do{
      printf("Coloca una ficha jugador 2:\n\n");
      fflush (stdin);
      scanf ("%c", &x);
    }while(x < '1' || x > '9');

    k = 0;

    switch (x){  // Se comprueba que casilla no esté ocupada
      case '1': {
        i = 0;
        j = 0;
        if (c[i][j] == 'X' || c[i][j] == 'O'){
          k = 1;
          printf("Inténtalo de nuevo\n\n");
        }
        break;
      }
      case '2': {
        i = 0;
        j = 1;
        if (c[i][j] == 'X' || c[i][j] == 'O'){
          k = 1;
          printf("Inténtalo de nuevo\n\n");
        }
        break;
      }
      case '3': {
        i = 0;
        j = 2;
        if (c[i][j] == 'X' || c[i][j] == 'O'){
          k = 1;
          printf("Inténtalo de nuevo\n\n");
        }
        break;
      }
      case '4': {
        i = 1;
        j = 0;
        if (c[i][j] == 'X' || c[i][j] == 'O'){
          k = 1;
          printf("Inténtalo de nuevo\n\n");
        }
        break;
      }
      case '5': {
        i = 1;
        j = 1;
        if (c[i][j] == 'X' || c[i][j] == 'O'){
          k = 1;
          printf("Inténtalo de nuevo\n\n");
        }
        break;
      }
      case '6': {
        i = 1;
        j = 2;
        if (c[i][j] == 'X' || c[i][j] == 'O'){
          k = 1;
          printf("Inténtalo de nuevo\n\n");
        }
        break;
      }
      case '7': {
        i = 2;
        j = 0;
        if (c[i][j] == 'X' || c[i][j] == 'O'){
          k = 1;
          printf("Inténtalo de nuevo\n\n");
        }
        break;
      }
      case '8': {
        i = 2;
        j = 1;
        if (c[i][j] == 'X' || c[i][j] == 'O'){
          k = 1;
          printf("Inténtalo de nuevo\n\n");
        }
        break;
      }
      case '9': {
        i = 2;
        j = 2;
        if (c[i][j] == 'X' || c[i][j] == 'O'){
          k = 1;
          printf("Inténtalo de nuevo\n\n");
        }
        break;
      }
    }
  }while (k == 1);
  c[i][j] = 'O';  // Se introduce el valor de X
}

void tablero (char c [3][3]){  // Función encargada de pintar el tablero
  int i, j;
  for (i = 0; i < 3; i++){  // Se leen valores de la matriz y luego se imprime
    for (j = 0; j < 3; j++){  //los valores de la matriz
      if (j < 2){
        printf (" %c |", c[i][j]);
      }
      else{
        printf(" %c ", c[i][j]);
      }
    }
    if (i < 2){
      printf("\n-----------\n");
    }
  }
  printf("\n\n");
}

int ganador (char c[3][3]){
  if (c[0][0] == 'X' || c[0][0] == 'O'){
    if(c[0][0] == c[0][1] && c[0][0] == c[0][2]){
      if(c[0][0] == 'X'){
        return 0; // Ha ganado el jugador 1
      }else{
        return 1; // Ha ganado el jugador 2
      }
    }
    if (c[0][0] == c[1][0] && c[0][0] == c[2][0]){
      if(c[0][0] == 'X'){
        return 0; // Ha ganado el jugador 1
      }else{
        return 1; // Ha ganado el jugador 2
    }
  }
}
  if (c[1][1] == 'X' || c[1][1] == 'O'){
    if(c[1][1] == c[0][0] && c[1][1] == c[2][2]){
    if(c[1][1] == 'X'){
      return 0; // Ha ganado el jugador 1
    }else{
      return 1; // Ha ganado el jugador 2
    }
  }
    if(c[1][1] == c[1][0] && c[1][1] == c[1][2]){
    if(c[1][1] == 'X'){
      return 0; // Ha ganado el jugador 1
    }else{
      return 1; // Ha ganado el jugador 2
    }
  }
    if(c[1][1] == c[2][0] && c[1][1] == c[0][2]){
    if(c[1][1] == 'X'){
      return 0; // Ha ganado el jugador 1
    }else{
      return 1; // Ha ganado el jugador 2
    }
  }
    if(c[1][1] == c[0][1] && c[1][1] == c[2][1]){
    if(c[1][1] == 'X'){
      return 0; // Ha ganado el jugador 1
    }else{
      return 1; // Ha ganado el jugador 2
    }
  }
}
  if (c[2][2] == 'X' || c[2][2] == 'O'){
  if(c[2][2] == c[2][0] && c[2][2] == c[2][1]){
    if(c[2][2] == 'X'){
      return 0; // Ha ganado el jugador 1
    }else{
      return 1; // Ha ganado el jugador 2
    }
  }
  if(c[2][2] == c[0][2] && c[2][2] == c[1][2]){
    if(c[2][2] == 'X'){
      return 0; // Ha ganado el jugador 1
    }else{
      return 1; // Ha ganado el jugador 2
    }
  }
}
return 2;
}

#include <iostream>
#include <stdlib.h>

using namespace std;

void dibujarTablero();
void jugandoTurno();
bool validarJuego();

string nombreX, nombre0; //player name string variables
char turno;             // Player turn char variables
bool dibujar = false;    // drow boolean
char tablero[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}}; // board char array variables

int main()
{
    //beginning:
    system("clear");
    cout << "\t** Bievenido al juego Tic Tac Toe VS **" << endl;
    cout << "\t   =================================" << endl << endl;

    cout << "\t Por favor digite el nombre del jugador X: ";
    cin >> nombreX;
    cout << endl << "\t Por favor dijite el nombre del jugador 0: ";
    cin >> nombre0;
    system("clear");

    cout << "\t\t\t** Juego Tic Tac Toe VS **" << endl;
    cout << "\t\t\t   ====================" << endl << endl;

    cout << "\t\t\tEl jugador 'X' es: " << nombreX << endl;
    cout << "\t\t\tEl jugador '0' es: " << nombre0 << endl << endl;
    turno = 'X';

    while (!validarJuego())
    {
        dibujarTablero();
        jugandoTurno();
        validarJuego();
    }

    if(turno == 'O' && !dibujar)
    {
        dibujarTablero();
        cout << endl << "El jugador " << nombreX << " ha ganado!" << endl;
        cout << "=================================================" << endl;
    }
    else if (turno == 'X' && !dibujar)
    {
        dibujarTablero();
        cout << endl << "El jugador " << nombre0 << " ha ganado!" << endl;
        cout << "=================================================" << endl;
    }
    else
    {
        dibujarTablero();
        cout << endl << endl << "Juego empate, no hay ganadores!" << endl;
    }

    //system("clear");
    /*char decision;
    cout << "\nDesea volver a jugar? (Y/N) ";
    cin >> decision;

    if(decision == 'y' || decision == 'Y')
    {

        goto beginning;
    }
    system("clear");
    cout << "Juego terminado..!\n\n";*/

    return 0;
}

void dibujarTablero()
{
    system("clear");
    cout << "\t\t\t** Juego Tic Tac Toe VS **" << endl;
    cout << "\t\t\t   ====================" << endl << endl;
    cout << "\t\t\tEl jugador 'X' es: " << nombreX << endl;
    cout << "\t\t\tEl jugador '0' es: " << nombre0 << endl << endl;

    cout << "\t\t\t***************************" << endl << endl;
    cout << "\t\t\t\t     |     |     " << endl;
    cout << "\t\t\t\t  " << tablero[0][0] << "  |  " << tablero[0][1] << "  |  " << tablero[0][2] << endl;
    cout << "\t\t\t\t_____|_____|_____" << endl;
    cout << "\t\t\t\t     |     |     " << endl;
    cout << "\t\t\t\t  " << tablero[1][0] << "  |  " << tablero[1][1] << "  |  " << tablero[1][2] << endl;
    cout << "\t\t\t\t_____|_____|_____" << endl;
    cout << "\t\t\t\t     |     |     " << endl;
    cout << "\t\t\t\t  " << tablero[2][0] << "  |  " << tablero[2][1] << "  |  " << tablero[2][2] << endl;
    cout << "\t\t\t\t     |     |     " << endl << endl;
}

void jugandoTurno()
{
    int seleccion;
    int fila = 0, columna = 0;

    if (turno == 'X')
    {
        cout << "El jugador en turno es: " << nombreX << " [X]: ";
    }
    else if(turno == 'O')
    {
        cout << "El jugador en turno es: " << nombre0 << " [O]: ";
    }
    cin >> seleccion;

    switch(seleccion)
    {
        case 1: fila = 0; columna = 0; break;
        case 2: fila = 0; columna = 1; break;
        case 3: fila = 0; columna = 2; break;
        case 4: fila = 1; columna = 0; break;
        case 5: fila = 1; columna = 1; break;
        case 6: fila = 1; columna = 2; break;
        case 7: fila = 2; columna = 0; break;
        case 8: fila = 2; columna = 1; break;
        case 9: fila = 2; columna = 2; break;
        default:
            cout << endl << "Por favor dijite un numero de las coordenas que se muestran." << endl;
            jugandoTurno();
    }

    if (turno == 'X' && tablero[fila][columna] != 'X' && tablero[fila][columna] != 'O')
    {
        tablero[fila][columna] = 'X';
        turno = 'O';
    }
    else if(turno == 'O' && tablero[fila][columna] != 'X' && tablero[fila][columna] != '0')
    {
        tablero[fila][columna] = 'O';
        turno = 'X';
    }
    else
    {
        cout << endl << "La celda que trata de seleccionar ya esta usada, por favor intente otra vez\n";
        jugandoTurno();
    }
}

bool validarJuego()
{
    for (int i = 0; i < 3; i++) //check for a win
    {
        if ((tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2]) || (tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i]) || (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2]) || (tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0]))
        {
           /* if((tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2])
            {
                tablero[0][i] = '';
                tablero[1][i] = '';
                tablero[2][i] = '';
                return true;
            }
            else if (tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i])
            {
                tablero[i][0];
                tablero[i][1];
                tablero[i][2];
                return true;
            }
            else if (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2])
            {

            }*/
            return true;
        }
    }

    for (int i = 0; i < 3; i++) //check for draw
    {
        for (int z = 0; z < 3; z++)
        {
            if (tablero[i][z] != 'X' && tablero[i][z] != 'O')
            {
                return false;
            }
        }
    }
    dibujar = true;
    return true;
}


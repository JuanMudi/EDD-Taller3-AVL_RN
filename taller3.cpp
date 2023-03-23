#include "Ordenamiento.h"
#include <fstream>
#include <cstring>
#include <iomanip>
#include <ctime>


int main(int argc, char* argv[]){
    //Arbol AVL
    //Declaracion del flujo de datos
    fstream arch;
    arch.open(argv[1], ios::in);
    if(arch.fail())
    {
        exit(-1);
    }
    Ordenamiento<int> arboles;

    std::clock_t init_time = std::clock( );
    while(!arch.eof())
    {
        char *datos = new char[100];

        arch.getline(datos, 100);
        char op= datos[0];
        if(std::strcmp(datos,"")==0)
        {
            continue;
        }


        char* token = std::strtok(datos, " ");
        token = std::strtok(NULL, " ");
        int aux = std::stoi(token);


        if(arboles.AVL.esVacio()){
            NodoBinarioAVL<int> nodo = *new NodoBinarioAVL<int>;
            nodo.setDato(aux);
            arboles.AVL.setRaiz(&nodo);
            continue;
        }

        switch (op) {
            case 'E':
                arboles.AVL.eliminar(aux);
                break;
            case 'A':
                arboles.AVL.insertar(aux);
                break;
            default:
                continue;
        }


    }
    arch.close();
    std::clock_t end_time = std::clock( );
    double calc_time = (end_time - init_time)  / double (CLOCKS_PER_SEC);
    std::cout << "Tiempo de ejecucion AVL: " << calc_time << " seconds" << std::endl;
    arboles.AVL.inOrden(arboles.AVL.getRaiz());

    system("pause");
    //Arbol RN
    //Declaracion del flujo de datos
    arch.open(argv[1], ios::in);
    if(arch.fail())
    {
        exit(-1);
    }

    std::clock_t init_time_RN = std::clock( );

    while(!arch.eof())
    {
        char *datos = new char[100];

        arch.getline(datos, 100);
        char op= datos[0];
        if(std::strcmp(datos,"")==0)
        {
            continue;
        }



        char* token = std::strtok(datos, " ");
        token = std::strtok(NULL, " ");
        int aux = std::stoi(token);


        switch (op) {
            case 'E':
                arboles.RN.erase(aux);
                break;
            case 'A':
                arboles.RN.insert(aux);
                break;
            default:
                continue;
        }


    }
    arch.close();
    std::clock_t end_time_RN = std::clock( );
    double calc_time_RN = (end_time - init_time)  / double (CLOCKS_PER_SEC);
    std::cout << "Tiempo de ejecucion RN: " << calc_time << " seconds" << std::endl;

    for (auto it = arboles.RN.begin(); it != arboles.RN.end() ; ++it) {
        std::cout << *it << " ";
        
    }

    system("pause");



    }



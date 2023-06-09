#include "Ordenamiento.h"


int main(int argc, char* argv[]){
    std::list<int> inOrden_RN, inOrden_AVL;
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
    int n=0;
    while(!arch.eof())
    {

        char *datos = new char[100];

        arch.getline(datos, 100);
        if(std::strcmp(datos,"")==0)
            continue;
        char op= datos[0];



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

n++;
    }
    arch.close();
    std::clock_t end_time = std::clock( );
    double calc_time = (end_time - init_time)  / double (CLOCKS_PER_SEC);
    arboles.AVL.inOrdenV(arboles.AVL.getRaiz(), *&inOrden_AVL);
    std::cout << "Tiempo de ejecucion AVL -> " << calc_time << " segundos" << std::endl;
    std::cout << "-*************************************************-" << std::endl;
    /*arboles.AVL.inOrden(arboles.AVL.getRaiz());*/

    //Arbol RN
    //Declaracion del flujo de datos
    arch.open(argv[1], ios::in);
    if(arch.fail())
    {
        exit(-1);
    }
    std::clock_t init_time_RN = std::clock( );
    n=0;

    while(!arch.eof())
    {
        char *datos = new char[100];

        arch.getline(datos, 100);
        if(std::strcmp(datos,"")==0)
            continue;
        char op= datos[0];



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

n++;
    }
    arch.close();
    std::clock_t end_time_RN = std::clock( );
    double calc_time_RN = (end_time_RN - init_time_RN)  / double (CLOCKS_PER_SEC);
    std::cout << "Tiempo de ejecucion RN -> " << calc_time_RN << " segundos" << std::endl;
    std::cout << "-*************************************************-" << std::endl;

   for (std::set<int>::iterator it = arboles.RN.begin(); it != arboles.RN.end() ; ++it) {
       inOrden_RN.push_back(*it);
    }

    std::list<int>::iterator avl;
    std::list<int>::iterator rn;

   if(inOrden_AVL.size() == inOrden_RN.size()) {
       avl = inOrden_AVL.begin();
       rn = inOrden_RN.begin();

       while(avl != inOrden_AVL.end() && rn != inOrden_RN.end())
       {
           if(*avl != *rn)
           {
               std::cout << "La organizacion de los arboles no coinciden " << std::endl;
               exit(-1);
           }
           ++avl;
           ++rn;


       }
       std::cout << "La organizacion de los arboles coinciden" << std::endl;
   }
   else{
       std::cout << "La organizacion de los arboles no coinciden" << std::endl;
   }





    }



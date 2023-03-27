//
// Created by J_mud on 22/03/2023.
//


#ifndef TALLER_3_ARBOLES_BUSQUEDA_ARCHIVOS_ORDENAMIENTO_H
#define TALLER_3_ARBOLES_BUSQUEDA_ARCHIVOS_ORDENAMIENTO_H

#include <iostream>
#include <ctime>
#include <math.h>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include "ArbolBinarioAVL.h"

template <class T>
class Ordenamiento {
public:
    std::set<T> RN;
    ArbolBinarioAVL<T> AVL = *new ArbolBinarioAVL<T>;
};


#endif //TALLER_3_ARBOLES_BUSQUEDA_ARCHIVOS_ORDENAMIENTO_H

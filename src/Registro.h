#ifndef __REGISTRO_H__
#define __REGISTRO_H__

#include <set>

#include "Tipos.h"
#include "modulos_basicos/string_map.h"
using namespace std;

class Registro {
public:
    Registro();
    set<NombreCampo> campos() const;
    Valor& operator[](const NombreCampo& campo);
private:
	string_map<Valor> _reg;
};

#endif /*__REGISTRO_H__*/

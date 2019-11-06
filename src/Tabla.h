#ifndef TP3_TABLA_H
#define TP3_TABLA_H

#include "Tipos.h"
#include "Registro.h"

class Tabla {
public:
	Tabla();
	set<NombreCampo> campos();
	set<Registro> Registros();
	NombreCampo clave();
	void insertar(Registro);
	void borrar(Valor);
	Registro buscarXClave(Valor);

private:
	NombreCampo _clave;
	string_map<Registro*> _claveR;
	set<NombreCampo> _campos;
	set<Registro> _registros;
};


#endif //TP3_TABLA_H

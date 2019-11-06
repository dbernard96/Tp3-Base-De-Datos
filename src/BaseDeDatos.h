#ifndef TP3_BASEDEDATOS_H
#define TP3_BASEDEDATOS_H
#include "Tabla.h"
#include "Registro.h"
#include "Tipos.h"
#include "Consulta.h"
#include "modulos_basicos/string_map.h"
class BaseDeDatos {
public:
	BaseDeDatos();
	void agregarTabla(NombreTabla,Tabla);
	void eliminarTabla(NombreTabla);
	void agregarRegistro(Registro,NombreTabla);
	void eliminarRegistro(Valor,NombreTabla);
	set<Registro> ejecutar(Consulta);
private:
	string_map<Tabla> _tablas;
};


#endif //TP3_BASEDEDATOS_H

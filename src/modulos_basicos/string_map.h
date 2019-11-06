#ifndef STRING_MAP_H_
#define STRING_MAP_H_

#include <string>

using namespace std;

template<typename T>
class string_map {
public:
	string_map();
	string_map(const string_map<T>& aCopiar);
	string_map& operator=(const string_map& d);
	~string_map();
	void insert(const pair<string, T>&);
	int count(const string &key) const;

	const T& at(const string& key) const;
	T& at(const string& key);
	void erase(const string& key);
	int size() const;
	bool empty() const;
	T &operator[](const string &key);
private:
	struct Nodo {
		Nodo():siguientes(256){definicion = nullptr;}
		vector<Nodo*> siguientes;
		T* definicion;
	};

	Nodo* _raiz;
	int _size;

	void destruir(Nodo*);
	void copiar(const Nodo*,Nodo*);
	void borrarC(const string& clave, int i, Nodo*);
	int  nroDeHijos(Nodo*);
};

#include "string_map.hpp"

#endif
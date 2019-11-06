template <typename T>
string_map<T>::string_map(){
	_raiz = nullptr;
	_size = 0;
}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {
	destruir(_raiz);
	if(d._raiz != nullptr) {
        Nodo *nRaiz = new Nodo();
        _raiz = nRaiz;
        copiar(d._raiz, _raiz);
    }
}

template <typename T>
void string_map<T>::copiar(const Nodo* aCopiar, Nodo* copia) {
    if(aCopiar->definicion != nullptr)
        copia->definicion = new T(*aCopiar->definicion);
    for (int i = 0; i < aCopiar->siguientes.size(); ++i) {
        if(aCopiar->siguientes[i] != nullptr){
            Nodo* nuevo = new Nodo;
            copia->siguientes[i] = nuevo;
            copiar(aCopiar->siguientes[i],nuevo);
        }
    }
}

template <typename T>
string_map<T>::~string_map(){
	destruir(_raiz);
}

template <typename T>
void string_map<T>::insert(const pair<string, T>& def) {
	int i = 0;
	Nodo* actual = _raiz;
	if(actual == nullptr){
		actual = new Nodo();
		_raiz = actual;
	}

	while(i < def.first.size()){
		if(actual->siguientes[def.first[i]] == nullptr){
			Nodo *nuevo = new Nodo();
			(actual->siguientes)[def.first[i]] = nuevo;
		}
		actual = (actual->siguientes)[def.first[i]];
		i++;
	}
	if(actual->definicion == nullptr) {
		actual->definicion = new T(def.second);
	}else{
		delete(actual->definicion);
		actual->definicion = new T(def.second);
	}
	_size++;
}

template <typename T>
T& string_map<T>::operator[](const string& clave){
    // COMPLETAR
}


template <typename T>
int string_map<T>::count(const string& clave) const{
	Nodo* actual = _raiz;
	int i = 0;
	while(actual != nullptr && i < clave.size()){
		actual = actual->siguientes[clave[i]];
		i++;
	}
	if(i == clave.size() && actual->definicion != nullptr){
		return 1;
	} else {
		return 0;
	}
}

template <typename T>
const T& string_map<T>::at(const string& clave) const {
	int i = 0;
	Nodo* actual = _raiz;
	while(i < clave.size()){
		actual = actual->siguientes[clave[i]];
		i++;
	}
	return actual->definicion;
}

template <typename T>
T& string_map<T>::at(const string& clave) {
	int i = 0;
	Nodo* actual = _raiz;
	while(i < clave.size()){
		actual = actual->siguientes[clave[i]];
		i++;
	}
	return *actual->definicion;
}

template <typename T>
void string_map<T>::erase(const string& clave) {
    Nodo* actual = _raiz;
    Nodo* ultNUtil = nullptr;
    int aux = 0;
    for (int i = 0; i < clave.size(); ++i) {
        if(i < clave.size()-1 && (nroDeHijos(actual) > 1 || actual->definicion != nullptr)){
            ultNUtil = actual;
            aux = i;
        }
        actual = actual->siguientes[clave[i]];
    }
    if(nroDeHijos(actual) == 0) {
        if (ultNUtil == nullptr) {
            destruir(_raiz);
            _raiz = nullptr;
        } else {
            destruir(ultNUtil->siguientes[clave[aux]]);
            ultNUtil->siguientes[clave[aux]] = nullptr;
        }
    }else{
        delete(actual->definicion);
        actual->definicion = nullptr;
    }
}

template <typename T>
int string_map<T>::nroDeHijos(Nodo* nodo) {
    int res = 0;
    for (int i = 0; i < nodo->siguientes.size(); ++i) {
        if(nodo->siguientes[i] != nullptr)
            res++;
    }
    return res;
}

template <typename T>
int string_map<T>::size() const{
	return _size;
}

template <typename T>
bool string_map<T>::empty() const{
	return _size == 0;
}

template <typename T>
void string_map<T>::destruir(Nodo* actual){
	if(actual != nullptr) {
		for (int i = 0; i < actual->siguientes.size(); ++i) {
			if (actual->siguientes[i] != nullptr)
				destruir(actual->siguientes[i]);
		}
		if (actual->definicion != nullptr)
			delete (actual->definicion);
		delete (actual);
		_size = 0;
	}
}
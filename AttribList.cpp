#include "AttribList.h"

///Attribute
template<class T>
Attribute<T>::Attribute(const T& attr) : t(attr) {}

template<class T>
Attribute<T>::Attribute(const Attribute<T>& attr) : t(attr.Get()) {}

template<class T>
const T& Attribute<T>::Get() {
    return t;
}

template<class T>
void Attribute<T>::Set(const T& new_t) {
    t=new_t;
}

template<class T>
BaseAttribute* Attribute<T>::Clone() const {
    const BaseAttribute* base_ptr=new Attribute<T>(*this);
    return base_ptr;
}

///AttribList

AttribList::~AttribList() {
    Clear();
}

template<class T>
void AttribList::AddAttribute(const std::string& name, T& value) {
    attribute_map[name]=std::unique_ptr<BaseAttribute>((Attribute<T>(value)).Clone());
}

const BaseAttribute& AttribList::GetAttribute(const std::string& name) {
    return *(attribute_map[name]);
}

void AttribList::DeleteAttribute(const std::string& name) {
    attribute_map.erase(name);
}

void AttribList::Clear() {
    attribute_map.clear();
}

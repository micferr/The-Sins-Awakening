#include "Vector.h"

#include <algorithm>

namespace nfl {

//Vector<T>::iterator

template<typename T>
Vector<T>::iterator::iterator(Vector<T>* v, std::size_t pos) : vect(v), position(pos) {}

template<typename T>
T& Vector<T>::iterator::operator*() {
    return vect[position];
}

template<typename T>
typename Vector<T>::iterator& Vector<T>::iterator::operator++() {
    if (position==vect->last_taken) {
        ++position;
        return *this;
    }
    while (position<vect->last_taken) {
        ++position;
        if (vect->isValid(position))
            return *this;
    }
    return nullptr;
}

template<typename T>
typename Vector<T>::iterator& Vector<T>::iterator::operator--() {
    while (position>vect->first_taken) {
        --position;
        if (vect->isValid(position))
            return *this;
    }
    return nullptr;
}

template<typename T>
bool Vector<T>::iterator::operator!=(const Vector<T>::iterator& it) const {
    return this->vect!=it->vect || this->position!=it->position;
}

//Vector<T>

template<typename T>
Vector<T>::Vector(std::size_t elements) : values(), index(), first_taken(0), last_taken(0), first_free(0) {}

template<typename T>
Vector<T>::~Vector() {}

template<typename T>
bool Vector<T>::isValid(std::size_t i) {
    return index.size()>i ? index(i) : false;
}

template<typename T>
typename Vector<T>::iterator Vector<T>::begin() {
    return Vector<T>::iterator(values, first_taken);
}

template<typename T>
typename Vector<T>::iterator Vector<T>::end() {
    return Vector<T>::iterator(values, last_taken+1);
}

template<typename T>
T& Vector<T>::operator[](std::size_t i) {
    return values[i];
}

template<typename T>
T& Vector<T>::addNew(void) {
    typename std::vector<T>::iterator first_free_iterator;
    if (first_free==0) { //If there is no free slot
        first_free_iterator=std::find(index.begin(), index.end(), false);
        if (first_free_iterator==index.end()) { //Consecutive ifs for performance
            index.push_back(true);
            values.push_back(T());
            first_taken=std::min(first_taken,index.size()-1);
            last_taken=index.size()-1;
            return values.back();
        }
    }

    size_t i=first_free; //Get index
    index[i]=true; //Set as taken
    size_t temp=first_free_iterator-values.begin();
    first_taken=std::min(first_taken, i);
    last_taken=std::max(last_taken, i);
    first_free = temp!=index.size() ? temp : 0;
    return values[i];
}

template<typename T>
void Vector<T>::erase(std::size_t i) {
    if (i>=index.size())
        return;

    index[i]=false;
    if (first_taken==i)
        first_taken=std::find(index.begin()+first_taken, index.begin()+last_taken, true)-index.begin();
    if (last_taken==i) {
        for (size_t i=last_taken; i>=0; --i) {
            if (index[i]==true) {
                last_taken=i;
                break;
            }
        }
    }
    first_free=std::min(first_free, i);
}

template<typename T>
void Vector<T>::clear() {
    for (auto& b : index) {
        b=false;
    }
    first_taken=0;
    last_taken=0;
    first_free=0;
}

}

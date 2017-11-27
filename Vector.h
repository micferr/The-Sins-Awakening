#ifndef NFL_VECTOR

#include <vector>

namespace nfl {

template <typename T>
class Vector {
    std::vector<T> values;
    std::vector<unsigned char> index;
    std::size_t first_taken, last_taken, first_free;

    public:

    class iterator {
        Vector<T>* vect;
        std::size_t position;

        public:

        iterator(Vector<T>* v, std::size_t pos = 0);
        T& operator*();
        iterator& operator++();
        iterator& operator--();
        bool operator!=(const iterator& it) const;
    };

    Vector(std::size_t elements = 0);
    virtual ~Vector();

    bool isValid(std::size_t i);
    Vector<T>::iterator begin();
    Vector<T>::iterator end();

    T& operator[](std::size_t i);
    T& addNew(void);
    void erase(std::size_t i);
    void clear();
    void size();


};

}

#endif // NFL_VECTOR

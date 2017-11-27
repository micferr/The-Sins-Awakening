#ifndef ATTRIBLIST_H
#define ATTRIBLIST_H

#include <string>
#include <map>
#include <memory>

class BaseAttribute {
    public:
    BaseAttribute()=default;
    virtual ~BaseAttribute()=default;

    virtual BaseAttribute* Clone() const =0;
};

template<class T>
class Attribute : public BaseAttribute {
    T t;

    public:
    Attribute()=default;
    Attribute(const T& attr);
    Attribute(const Attribute<T>& attr);

    const T& Get();
    void Set(const T& new_t);
    virtual BaseAttribute* Clone() const;
};

class AttribList {
    std::map<std::string, std::unique_ptr<BaseAttribute>> attribute_map;

    public:
    ~AttribList();
    template<class T> void AddAttribute(const std::string& name, T& value);
    const BaseAttribute& GetAttribute(const std::string& name);
    void DeleteAttribute(const std::string& name);
    void Clear();
};

#endif // ATTRIBLIST_H

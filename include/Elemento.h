#pragma once

class Elemento {
private:
    long id;

public:
    Elemento(long id_val) : id(id_val) {}
    virtual ~Elemento() {}

    long getID() const {
        return id;
    }

    virtual void imprimirInfo() const = 0;
    virtual Elemento* clone() const = 0; 
};
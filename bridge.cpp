#include <iostream>
#include <cstdio>

using namespace std;

// 类比Color
class ImplBase {
public:
    virtual ~ImplBase() { }
    virtual void ConcreteInterface() = 0;
};

// 类比Red
class ConcreteImplA : public ImplBase {
public:
    void ConcreteInterface() override {
        cout << "impl A" << endl;
    }
};

// 类比Green
class ConcreteImplB : public ImplBase {
public:
    void ConcreteInterface() override {
        cout << "impl B" << endl;
    }
};

// 类比Shape
class ObjectBase {
public:
    virtual ~ObjectBase() { }
    ObjectBase(ImplBase *impl) : m_impl(impl) {
    }

    virtual void invoke() {
        cout << "ObjectBase invoke: ";
        m_impl->ConcreteInterface();
    }

    void set_impl(ImplBase *impl) {
        m_impl = impl;
    }
protected:
    ImplBase *m_impl;
};

// 类比Circle
class ObjectA : public ObjectBase {
public:
    ObjectA(ImplBase *impl) : ObjectBase(impl) { }

    void invoke() override {
        cout << "ObjectA invoke: ";
        m_impl->ConcreteInterface();
    }
};

void client(ObjectBase* obj) {
    obj->invoke();
}

int main() {
    ImplBase *impla = new ConcreteImplA;
    ImplBase *implb = new ConcreteImplB;
    ObjectBase *obj = new ObjectBase(impla);
    client(obj);

    obj->set_impl(implb);
    client(obj);
    
    ObjectBase *obja = new ObjectA(impla);
    client(obja);

    obja->set_impl(implb);
    client(obja);

    getchar();
    return 0;
}

#include <iostream>
#include <cstdio>

using namespace std;

// 产品A
class ProductBaseA {
public:
    virtual ~ProductBaseA() { }
    virtual void ProductAcall() = 0;
};

class ProductA1 : public ProductBaseA {
public:
    ProductA1() { }
    void ProductAcall() override {
        cout << "Product A1 is called." << endl;
    }
};

class ProductA2 : public ProductBaseA {
public:
    ProductA2() { }
    void ProductAcall() override {
        cout << "Product A2 is called." << endl;
    }
};

// 产品B
class ProductBaseB {
public:
    virtual ~ProductBaseB() { }
    virtual void ProductBcall() = 0;
};

class ProductB1 : public ProductBaseB {
public:
    ProductB1() { }
    void ProductBcall() override {
        cout << "Product B1 is called." << endl;
    }
};

class ProductB2 : public ProductBaseB {
public:
    ProductB2() { }
    void ProductBcall() override {
        cout << "Product B2 is called." << endl;
    }
};

class AbstractFactory {
public:
    virtual ~AbstractFactory() { }
    virtual ProductBaseA *Create_Product_A() const = 0;
    virtual ProductBaseB *Create_Product_B() const = 0;
};

class Factory1 : public AbstractFactory {
public:
    ProductBaseA *Create_Product_A() const override {
        return new ProductA1;
    }

    ProductBaseB *Create_Product_B() const override {
        return new ProductB1;
    }
};

class Factory2 : public AbstractFactory {
public:
    ProductBaseA *Create_Product_A() const override {
        return new ProductA2;
    }

    ProductBaseB *Create_Product_B() const override {
        return new ProductB2;
    }
};

void client(AbstractFactory* factory) {
    // 每个工厂可生产一类产品族（这里是产品A，产品B为一个产品族）
    ProductBaseA *producta = factory->Create_Product_A();
    ProductBaseB *productb = factory->Create_Product_B();
    producta->ProductAcall();
    productb->ProductBcall();
    delete producta;
    delete productb;
}

int main() {
    Factory1 *factory1 = new Factory1;
    Factory2 *factory2 = new Factory2;

    client(factory1);
    client(factory2);

    delete factory1;
    delete factory2;
    getchar();
    return 0;
}

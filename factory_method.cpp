#include <iostream>
#include <cstdio>


// 
class Product {
public:
    virtual ~Product() { }
    virtual void call() = 0;
};

// 具体产品对接口做不同的实现
class ProductA :public Product {
public:
    ProductA() { }
    void call() override {
        std::cout << "ProductA is called." << std::endl;
    }
    ~ProductA() { }
};

class ProductB :public Product {
public:
    ProductB() { }
    void call() override {
        std::cout << "ProductB is called." << std::endl;
    }
    ~ProductB() { }
};

// Factory
class Factory {
public:
    virtual ~Factory() { }
    virtual Product* CreateProduct() = 0;
protected:
    Factory() { }
};

// 由不同的具体工厂去创建不同的产品， 一般每个具体工厂只能创建一个对应的产品类实例。
class ConcreteFactory1 :public Factory {
public:
    ConcreteFactory1() { }

    ~ConcreteFactory1() { }

    Product* CreateProduct() override {
        return new ProductA();
    }
};

class ConcreteFactory2 :public Factory {
public:
    ConcreteFactory2() { }

    ~ConcreteFactory2() { }

    Product* CreateProduct() override {
        return new ProductB();
    }
};

void client(Factory* factory) {
    Product *product = factory->CreateProduct();
    product->call();
    delete product;
}

int main() {
    Factory *factory1 = new ConcreteFactory1();
    client(factory1);
    delete factory1;
    
    Factory *factory2 = new ConcreteFactory2();
    client(factory2);
    delete factory2;

    getchar();
    return 0;
}

#include <iostream>
#include <cstdio>

using namespace std;

class ProductBase {
public:
    virtual ~ProductBase() {}
    virtual void call() = 0;
protected:
    ProductBase() {}
};

class ProductA : public ProductBase {
public:
    ProductA() {}
    void call() override {
        cout << "productA is called." << endl;
    }
};

class ProductB : public ProductBase {
public:
    ProductB() {}
    void call() override {
        cout << "productB is called." << endl;
    }
};

class SimpleFactory {
public:
    SimpleFactory() { }
    ~SimpleFactory() { }

    static ProductBase* CREATE_PRODUCT(const string& product_name) {
        if ("a" == product_name) {
            return new ProductA;
        }else if ("b" == product_name) {
            return new ProductB;
        }else {
            throw("product not found.");
        }
    }
};

int main() {
    ProductBase *product = SimpleFactory::CREATE_PRODUCT("a");
    product->call();
    delete product;

    product = SimpleFactory::CREATE_PRODUCT("b");
    product->call();
    delete product;

    getchar();
    return 0;
}

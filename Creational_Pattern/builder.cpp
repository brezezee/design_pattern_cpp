#include <iostream>
#include <cstdio>
#include <stdlib.h>

using namespace std;

class IntegratedProduct {
public:
    IntegratedProduct() {}

    friend ostream & operator<<(ostream &out, const IntegratedProduct& p) {
        out << "partA: " << p.m_part_a << endl
            << "partB: " << p.m_part_b << endl;
    }
public:
    string m_part_a;
    string m_part_b;
};

class BuilderBase {
public:
    BuilderBase()  { 
        m_product = new IntegratedProduct;
    }
    virtual ~BuilderBase() { 
        delete m_product;
    }
    virtual void BuildPartA() {};
    virtual void BuildPartB() {};

    virtual IntegratedProduct* getProduct() {
        return m_product;
    }
protected:
    IntegratedProduct *m_product;
};

class Builder1 : public BuilderBase {
public:
    void BuildPartA() override {
        m_product->m_part_a = "builder1 parta";
    }

    void BuildPartB() override {
        m_product->m_part_b = "builder1 partb";
    }
    
};

class Builder2 : public BuilderBase {
public:
    void BuildPartA() override {
        m_product->m_part_a = "builder2 parta";
    }

    void BuildPartB() override {
        m_product->m_part_b = "builder2 partb";
    }
};

class Director {
public:
    void setBuilder(BuilderBase* builder) {
        m_builder = builder;
    }

    void build() {
        if (!m_builder) {
            cout << "You should set the builder first." << endl;
            exit(-1);
        }
        m_builder->BuildPartA();
        m_builder->BuildPartB();
    }
private:
    BuilderBase* m_builder;
};

void client(BuilderBase* builder) {
    Director director;
    director.setBuilder(builder);
    director.build();

    IntegratedProduct* product = builder->getProduct();
    cout << *product << endl;
}

int main() {
    BuilderBase *builder1 = new Builder1;
    client(builder1);

    BuilderBase *builder2 = new Builder2;
    client(builder2);
    
    getchar();
    return 0;
}

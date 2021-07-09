#include <iostream>
#include <cstdio>

using namespace std;

// 本例为server添加html request的适配器。
class Server {
public:
    virtual void Request() {
        cout << "origin request." << endl;
    }
};

class Html {
public:
    void HtmlRequest() {
        cout << "html request." << endl;
    }
};

// 对于没有多重继承的语言，需要在Adapter中保存被适配的对象(Html)，且同时只能适配一个。
class Adapter : public Server, private Html {
public:
    void Request() override {
        HtmlRequest();
    }
};

void client(Server* ser) {
    ser->Request();
}

int main() {
    Server *ser = new Server;
    client(ser);

    Server *ser_html = new Adapter;
    client(ser_html);

    delete ser;
    delete ser_html;

    getchar();
    return 0;
}

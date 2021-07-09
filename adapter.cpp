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

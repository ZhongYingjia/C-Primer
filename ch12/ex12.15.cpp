#include <iostream>
#include <string>
#include <memory>
using std::string;

struct destination{
    int port;
    string ip;
    destination(int port_,string ip_):port(port_),ip(ip_){}
};

struct connection{
    int port;
    string ip;
    connection(int port_,string ip_):port(port_),ip(ip_){}
};

connection connect(destination *pdest){
    //connecttion
    std::shared_ptr<connection> pConn(new connection(pdest->port, pdest->ip));
    std::cout << "creating connection(" << pConn.use_count() << ")"
              << std::endl;
    return *pConn;
}

void disconnect(connection conn){
    std::cout << "connection close(" << conn.ip << ":" << conn.port << ")"
              << std::endl;
}

void f(destination &d){
    connection c =connect(&d);
    std::shared_ptr<connection> p(&c,[](connection *p){ disconnect(*p); });
}

int main(){
    destination dest(3316, "202.118.176.67");
    f(dest);
    return 0;
}
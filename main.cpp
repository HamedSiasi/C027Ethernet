#include "mbed.h"
#include "TCPSocket.h"
#include "EthernetInterface.h"

DigitalOut led1(LED1);

EthernetInterface eth;
TCPSocket socket;


int main() {

    eth.connect();
    const char *ip = eth.get_ip_address();
    const char *mac = eth.get_mac_address();

    printf("IP address is: %s\r\n", ip ? ip : "No IP");
    printf("MAC address is: %s\r\n", mac ? mac : "No MAC");

    
    
    
    socket.open(&eth);
    socket.connect("developer.mbed.org", 80);

    // Send a simple http request
    char sbuffer[] = "GET / HTTP/1.1\r\nHost: httpbin.org/ip\r\n\r\n";
    int scount = socket.send(sbuffer, sizeof sbuffer);
    printf("sent %d [%.*s]\r\n", scount, strstr(sbuffer, "\r\n")-sbuffer, sbuffer);

    // Recieve a simple http response and print out the response line
    char rbuffer[64];
    int rcount = socket.recv(rbuffer, sizeof rbuffer);
    printf("recv %d [%.*s]\r\n", rcount, strstr(rbuffer, "\r\n")-rbuffer, rbuffer);

    // Close the socket to return its memory and bring down the network interface
    socket.close();
    eth.disconnect();

    printf("Done\r\n");
    
    //Blinky
    while (true) {
        led1 = !led1;
        Thread::wait(500);
    }
}


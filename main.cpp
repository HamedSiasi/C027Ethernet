/*
 * PackageLicenseDeclared: Apache-2.0
 * Copyright (c) 2015 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "mbed.h"
//#include "TCPSocket.h"
#include "EthernetInterface.h"


DigitalOut led1(LED1);
EthernetInterface eth;
//TCPSocket socket;

int main() {

    eth.connect();
    const char *ip = eth.get_ip_address();
    const char *mac = eth.get_mac_address();

    printf("IP address is: %s\r\n", ip ? ip : "No IP");
    printf("MAC address is: %s\r\n", mac ? mac : "No MAC");

    /*
    socket.open(&eth);
    socket.connect("developer.mbed.org", 80);

    // Send a simple http request
    char sbuffer[] = "GET / HTTP/1.1\r\nHost: developer.mbed.org\r\n\r\n";
    int scount = socket.send(sbuffer, sizeof sbuffer);
    printf("sent %d [%.*s]\r\n", scount, strstr(sbuffer, "\r\n")-sbuffer, sbuffer);

    // Recieve a simple http response and print out the response line
    char rbuffer[64];
    int rcount = socket.recv(rbuffer, sizeof rbuffer);
    printf("recv %d [%.*s]\r\n", rcount, strstr(rbuffer, "\r\n")-rbuffer, rbuffer);

    // Close the socket to return its memory and bring down the network interface
    socket.close();
    */


    eth.disconnect();
    printf("Done\r\n");
    
    //BlinkyLoop
    while (true) {
        led1 = !led1;
        Thread::wait(500);
    }
}


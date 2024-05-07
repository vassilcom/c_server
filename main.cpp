
#include <sys/socket.h>
#include <string.h>
#include <fcntl.h> // open
#include <sys/sendfile.h> // sendfile
#include <unistd.h>
#include <netinet/in.h>
#include <stdio.h>
#include <iostream>

int main()
{
    /*
        $ man socket

        AF_INET - regular ipv4, 
        SOCK_STREAM - simple TCP socket(htp protocol uses)
        0 - default protocol

        returns the file desctipter of the socket
    */ 
    int s = socket(AF_INET, SOCK_STREAM, 0);

    /*
        structure for the address
        $ man sockaddr_in

        sockaddr_in - for internet
    */
    struct sockaddr_in addr ={
        /*
            sa_family_t     sin_family;     // AF_INET
            in_port_t       sin_port;       // Port number
            struct in_addr  sin_addr;       // IPv4 address
        */
        AF_INET,
        //0x901f, // reversed 8080 ( hex(8080) = '0x1f90' >> '0x901f'
        0x401f, // reversed 8000 ( hex(8000) = '0x1f40' >> '0x401f'
        0 // bind on all network interfaces
    };

    /*
        bind socket to certain address
        $ man bind

        s - socket file descripter
        addr - structure with address to bind
        sizeof(addr) - size of the asdress
    */
    //bind(s, &addr, sizeof(addr) );
    bind(s,(struct sockaddr *) &addr,sizeof(addr));

    /*
        listen initializes socket for incomming connection
        $ man listen

        s - socket
        10 - number of connections that can be waiting at the same time until server starts rejecting new connections
    */
    listen(s, 10);

    /*
        accept connection comming from the clients
        $ man accept

        s - socket
        0 - address
        0 - address length
            this two can be 0 if we dont cate about additional client info

        returns file desctipter of the client socket
    */
    int client_fd = accept(s, 0, 0);

    char buffer[256] ={0}; // will bw http request, something like "GET /file.html ..."

    /*
        reccieve string that client is sending. receive a message from a socket
        $ man recv

        client_fd - client socket
        buffer - actual buffer to store in
        256 - length
        0 - flags

    */
    recv(client_fd, buffer, 256, 0);

    
    std::cout<<" \n";
    std::cout<<"VVVVVVVV full: \n";
    std::cout<<buffer;
    std::cout<<" \n";
    std::cout<<" \n";
    std::cout<<" \n";

    // get "file.html" from "GET /file.html ..."
    char* f = buffer + 5; // skip 5 bytes
    *strchr(f, ' ') = 0; // $ man strchr - returns pointer where character was found. put terminator instead of ' ' space


    std::cout<<" \n";
    std::cout<<"VVVVVVVV part: \n";
    std::cout<<f;
    std::cout<<" \n";
    std::cout<<" \n";
    std::cout<<" \n";

    /*
        open file
        $ man 2 open

        f - filename
        O_RDONLY - flag: read only
    */
    int opened_fd = open(f, O_RDONLY);

    /*
        send file . transfer data between file descriptors
        $ man sendfile

        client_fd - output file descriptor
        opened_fd - opend file
        0 - offset
        256 - count
    */
    sendfile(client_fd, opened_fd, 0, 256);

    // close client socket
    close(client_fd);

    // close socket
    close(s);


    
    return 0;
}
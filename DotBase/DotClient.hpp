// client.cpp
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>
#include <iostream>
#include <string>

#pragma comment(lib, "ws2_32.lib") // Linka biblioteca Winsock

class DotClient
{
public:
    WSADATA wsaData;
    SOCKET sock;
    struct sockaddr_in server;

    void initialize()
    {
        if (WSAStartup(MAKEWORD(2, 2), &wsaData))
        {
            std::cerr << "WSAStartup failed;" << std::endl;
        }
    }

    void create_socket(const char *host, int port)
    {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == INVALID_SOCKET)
        {
            std::cerr << "Error while creating the socket;" << std::endl;
            WSACleanup();
            return;
        }

        server.sin_family = AF_INET;
        server.sin_port = htons(port);
        server.sin_addr.s_addr = inet_addr(host);
    }

    void connect_to_server()
    {
        if (::connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0)
        {
            std::cerr << "Error while connecting;" << std::endl;
            closesocket(sock);
            WSACleanup();
        }
        else
        {
            std::cout << "Connected with success!" << std::endl;
        }
    }

    std::string send_message(const char* msg)
{
    send(sock, msg, strlen(msg), 0);

    char buffer[4096] = {0};
    int bytesReceived = recv(sock, buffer, sizeof(buffer), 0);
    if (bytesReceived > 0)
    {
        std::cout << "Received from server: " << std::string(buffer, bytesReceived) << std::endl;
        return std::string(buffer, bytesReceived);
    }
    std::cerr << "No response from server" << std::endl;
    return "";
}


    void cleanup()
    {
        closesocket(sock);
        WSACleanup();
    }
};
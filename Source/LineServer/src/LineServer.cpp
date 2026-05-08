#include "LineServer.h"

#include "Logger.h"

#include <arpa/inet.h>
#include <asm-generic/socket.h>
#include <cerrno>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <netinet/in.h>
#include <string>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <unistd.h>

void init_sockaddr_in(sockaddr_in& _addr, const in_addr_t& _s_addr,
                      const int& _port) {
    _addr.sin_family = AF_INET;
    _addr.sin_addr.s_addr = _s_addr;
    _addr.sin_port = htons(_port);
}

LineServer::LineServer(int port) {
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        Logger::fatal("Failed to create server.");
        exit(1);
    }

    int reuse_addr_opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &reuse_addr_opt,
               sizeof(reuse_addr_opt));

    sockaddr_in server_addr{};
    init_sockaddr_in(server_addr, INADDR_ANY, port);

    if (bind(server_fd, (sockaddr*)(&server_addr), sizeof(server_addr)) < 0) {
        Logger::fatal("Failed to bind port " + std::to_string(port) + ".");
        exit(1);
    }

    if (listen(server_fd, SOMAXCONN) < 0) {
        Logger::fatal("Failed to listen.");
        exit(1);
    }

    epoll_fd = epoll_create1(0);
    if (epoll_fd < 0) {
        Logger::fatal("Failed to create epoll.");
        exit(1);
    }
    epoll_event ev{};
    ev.events = EPOLLIN;
    ev.data.fd = server_fd;
    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, server_fd, &ev);

    Logger::info("Server launched at port [" + std::to_string(port) + "].");
}
LineServer::~LineServer() {
    if (server_fd > 0) close(server_fd);
    if (epoll_fd > 0) close(epoll_fd);
}
void LineServer::run() {
    running = true;
    epoll_event events[MAX_EVENTS];
    uint8_t buffer[BUFFER_SIZE];

    while(running) {
        int nfds = epoll_wait(epoll_fd, events, MAX_EVENTS, -1);
        if(nfds < 0) {
            if(errno == EINTR) continue;
            else {
                Logger::fatal("Function epoll_wait() error: " + std::string(strerror(errno)));
                break;
            }
        }
        for (int i = 0; i < nfds; ++i) {
            int fd = events[i].data.fd;
            
        }
    }
}
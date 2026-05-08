#pragma once
#include <atomic>
#include <map>
#include <netinet/in.h>
#include <string>
#include <sys/socket.h>
#include <vector>

void init_sockaddr_in(sockaddr_in& _addr, const in_addr_t& _s_addr, const int& port);

class LineServer {
public:
    explicit LineServer(int port);
    ~LineServer();
    void run();
    void stop();
private:
    int server_fd;  //服务器文件描述符
    int epoll_fd;   //epoll文件描述符
    std::atomic<bool> running;  //服务器状态

    std::map<int, int> line_sender; //线路id -> 客户端fd
    std::map<int, std::vector<int>> line_receiver;  //线路id -> 客户端fd
    std::map<int, int> client_line;     //客户端fd -> 线路id
    std::map<int, std::string> client_role; //客户端fd -> 角色"Sender" "Receiver"

    inline static constexpr int MAX_EVENTS = 1024;
    inline static constexpr int BUFFER_SIZE = 65536;
};
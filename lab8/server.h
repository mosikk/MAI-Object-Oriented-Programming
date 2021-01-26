#pragma once

#include <vector>
#include <queue>
#include <mutex>
#include <thread>
#include <functional>
#include <fstream>

template <class MESSAGE_T>
class server {
public:
    using subscriber_t = std::function<void(const MESSAGE_T&)>;

    // singleton
    static server& get()
    {
        static server instance;
        return instance;
    }

    // subscriber - function to handle buffer
    void register_subscriber(const subscriber_t& sub) {
        subscribers.push_back(sub);
    }

    // publisher - element of a buffer (figure)
    void publish(const MESSAGE_T& msg) {
        std::lock_guard<std::mutex> lck(mtx);
        message_queue.push(msg);
    }

    // starting handler
    void run(size_t max_size) {
        while (active) {
            if (message_queue.size() == max_size) {
                // handling
                std::string file_name = generate_file_name();
                fd.open(file_name);
                while (!message_queue.empty()) {
                    std::lock_guard<std::mutex> lck(mtx);
                    MESSAGE_T val = message_queue.front();
                    message_queue.pop();
                    for (auto sub : subscribers) {
                        sub(val);
                    }
                }
                fd.flush();
                fd.close();
            }
            else {
                std::this_thread::yield;
            }
        }
    }

    void stop() {
        active = false;
    }

    std::ofstream& get_fd() {
        return fd;
    }

private:
    std::vector<subscriber_t> subscribers;
    std::queue<MESSAGE_T> message_queue;
    std::mutex mtx;
    std::string file_name;
    std::ofstream fd;
    server() {};
    bool active = true;

    std::string generate_file_name() {
        std::string file_name;
        srand(time(NULL));
        for (int i = 0; i < 3; ++i) {
            file_name.push_back(rand() % 10 + '0');
        }
        return file_name;
    }
};


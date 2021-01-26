#ifndef OOP_LAB7_DOCUMENT_H
#define OOP_LAB7_DOCUMENT_H

#include <stack>
#include <fstream>

#include "factory.h"

class document {
private:

    struct memento {
        std::vector<std::shared_ptr<figure>> state;

        memento() = default;

        memento(std::vector<std::shared_ptr<figure>> &other) : state(other) {}
    };

    struct originator {
        std::stack<memento> mementos;

        void create_memento(std::vector<std::shared_ptr<figure>> &state) {
            mementos.emplace(state);
        }

        std::vector<std::shared_ptr<figure>> restore() {
            if (!mementos.empty()) {
                std::vector<std::shared_ptr<figure>> res = mementos.top().state;
                mementos.pop();
                return res;
            }
            throw std::logic_error("Can't undo");
        }
    };

    std::string name;
    std::vector<std::shared_ptr<figure>> buffer;
    originator origin;

public:
    document(std::string &name_) : name(name_) {}

    void add(const std::shared_ptr<figure> &figure) {
        origin.create_memento(buffer);
        buffer.push_back(figure);
    }

    void remove(int id) {
        if (id >= 0 && id < buffer.size()) {
            origin.create_memento(buffer);
            buffer.erase(buffer.begin() + id);
        } else {
            throw std::logic_error("Invalid position");
        }
    }

    void undo() {
        buffer = origin.restore();
    }

    void print() {
        for (auto &f : buffer) {
            f->print();
            std::cout << std::endl;
            std::cout << "Square: " << f->square() << std::endl;
            auto center = f->get_center();
            std::cout << "Center: (" << center.first << "; " << center.second << ")" << std::endl << std::endl;
        }
    }

    void save() {
        std::ofstream out;
        out.open(name, std::ios::out | std::ios::binary | std::ios::trunc);
        if (!out.is_open()) {
            throw std::logic_error("Can't open file");
        } else {
            int size = buffer.size();
            out.write((char *) &size, sizeof(int));
            for (auto &f : buffer) {
                f->write_to_file(out);
            }
            out.close();
        }
    }

    void open(std::ifstream &in) {
        int size;
        in.read((char *) &size, sizeof(int));
        for (int i = 0; i < size; ++i) {
            int type;
            in.read((char *) &type, sizeof(int));
            buffer.push_back(factory::read_from_file((figure_type) type, in));
        }
    }

};


#endif //OOP_LAB7_DOCUMENT_H

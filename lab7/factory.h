#ifndef OOP_LAB7_FACTORY_H
#define OOP_LAB7_FACTORY_H

#include "rhombus.h"
#include "pentagon.h"
#include "hexagon.h"

enum class figure_type {
    rhombus = 1,
    pentagon = 2,
    hexagon = 3
};

struct factory {
    static std::shared_ptr<figure> create(figure_type t) {
        switch (t) {
            case figure_type::rhombus: {
                std::pair<double, double> center;
                double d1, d2;
                std::cin >> center.first >> center.second >> d1 >> d2;
                return std::make_shared<rhombus>(center, d1, d2);
            }
            case figure_type::pentagon: {
                std::pair<double, double> center;
                double r;
                std::cin >> center.first >> center.second >> r;
                return std::make_shared<pentagon>(center, r);
            }
            case figure_type::hexagon: {
                std::pair<double, double> center;
                double r;
                std::cin >> center.first >> center.second >> r;
                return std::make_shared<hexagon>(center, r);
            }
            default:
                throw std::logic_error("Wrong figure id");
        }
    }

    static std::shared_ptr<figure> read_from_file(figure_type t, std::ifstream &in) {
        switch (t) {
            case figure_type::rhombus: {
                std::pair<double, double> center;
                double d1, d2;
                in.read((char *) &center.first, sizeof(double));
                in.read((char *) &center.second, sizeof(double));
                in.read((char *) &d1, sizeof(double));
                in.read((char *) &d2, sizeof(double));
                return std::make_shared<rhombus>(center, d1, d2);
            }
            case figure_type::pentagon: {
                std::pair<double, double> center;
                double r;
                in.read((char *) &center.first, sizeof(double));
                in.read((char *) &center.second, sizeof(double));
                in.read((char *) &r, sizeof(double));
                return std::make_shared<pentagon>(center, r);
            }
            case figure_type::hexagon: {
                std::pair<double, double> center;
                double r;
                in.read((char *) &center.first, sizeof(double));
                in.read((char *) &center.second, sizeof(double));
                in.read((char *) &r, sizeof(double));
                return std::make_shared<hexagon>(center, r);
            }
            default:
                throw std::logic_error("Wrong figure id");
        }
    }
};


#endif //OOP_LAB7_FACTORY_H

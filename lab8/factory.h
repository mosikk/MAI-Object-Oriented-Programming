#pragma once

#include <memory>

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
};

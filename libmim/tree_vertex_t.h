#pragma once

#include <string>
#include <map>
#include <cassert>
#include <vector>
#include <iostream>
#include "vertex_t.h"

namespace mim {
    using namespace std;

    struct tree_vertex_t: vertex_t {
        using b = vertex_t;

    public:
        //tree_vertex_t(const string& name);
        tree_vertex_t(const string& name, const string& mim_file);

        tree_vertex_t(const tree_vertex_t&);
        vertex_t* clone() const override;
    };

}


#pragma once

#include <set>
#include <string>
#include <iostream>

namespace mim {
    using namespace std;

    struct vertex_t;

    struct edges_t final {
        struct directional_edges_t final: set<vertex_t*> {
            directional_edges_t();
            vertex_t* find_by_name(const string& name);
            void dump(ostream& os) const;
        };

        edges_t();
        edges_t(const edges_t&);
        void dump(ostream& os) const;

        directional_edges_t in;
        directional_edges_t out;
    };

}


#pragma once

#include <string>
#include <map>
#include <cassert>
#include <vector>
#include <iostream>
#include "namespace_t.h"

namespace mim {
    using namespace std;

    struct menu_vertex_t;
    
    struct root_vertex_t: tree_vertex__deps_t { 
        using b = tree_vertex__deps_t;

        root_vertex_t(const string& name, const string& mim_file);
        root_vertex_t(const root_vertex_t&);
        vertex_t* clone() const override;
        bool merge(vertex_t* other, int op) override;

        string conf_target_dir(const string& lang) const override;
        using b::conf_target_dir;
        void dump_(ostream&) const override;

        void collect_all_menus(vector<const menu_vertex_t*>& menus) const;

        float z_order() const override;
    };

}


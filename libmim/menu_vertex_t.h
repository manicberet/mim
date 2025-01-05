#pragma once

#include <string>
#include <map>
#include <cassert>
#include <vector>
#include <iostream>
#include "android_vertex_t.h"
#include "menuspec_t.h"

namespace mim {
    using namespace std;

    struct namespace_t;

    struct menu_vertex_t: android_vertex_t {
        using b = android_vertex_t;
        using menuspec_t = mim::menuspec_t;

        menu_vertex_t(const string& name, const string& mim_file);

        menu_vertex_t(const menu_vertex_t&);
        vertex_t* clone() const override;

        void add(menuspec_t&&);
        using b::add;

        void dump_(ostream&) const override;
        string spec_classname(const menuspec_t&) const;

        void pre_configure(const menuspec_t&);

        bool pre_configure() override;
        bool configure() override;
        bool gen() override;
        bool merge(vertex_t* other, int op) override;

    public:
        map<string, menuspec_t> menus;
        const menu_vertex_t* base{nullptr};
    };

}


#pragma once

#include <string>
#include <map>
#include <cassert>
#include <vector>
#include <iostream>
#include "namespace_t.h"
#include "lang_codefiles_t.h"

namespace mim {
    using namespace std;

    struct namespace_t;

    struct sdk_vertex_t: namespace_t {
        using b = namespace_t;

        sdk_vertex_t(const string& name, const string& mim_file);
        sdk_vertex_t(const sdk_vertex_t&);
        vertex_t* clone() const override;

        string conf_target_dir(const string& lang) const override;
        using b::conf_target_dir;
        bool merge(vertex_t* other, int op) override;
        void dump_(ostream&) const override;

    };

}


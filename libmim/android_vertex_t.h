#pragma once

#include <string>
#include <map>
#include <cassert>
#include <vector>
#include <iostream>
#include "namespace_t.h"

namespace mim {
    using namespace std;

    struct namespace_t;
    struct lang_codefiles_t;
    
    struct android_vertex_t: namespace_t {
        using b = namespace_t;

        android_vertex_t(const string& name, const string& mim_file);
        android_vertex_t(const android_vertex_t&);
        vertex_t* clone() const override;

        string conf_target_dir(const string& lang) const override;
        using b::conf_target_dir;
        //bool merge(vertex_t* other, int op) override;
        lang_codefiles_t* create_lang_codefiles(const string& lang) override;
        void dump_(ostream&) const override;

    public:
        static string package_ns;
        static string package_dir;

        static string cfg_str28; //Android app package name
        static string cfg_str32; //Android app name

    };

}


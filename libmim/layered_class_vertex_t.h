#pragma once

#include <string>
#include <map>
#include <cassert>
#include <vector>
#include <iostream>
#include "android_vertex_t.h"

namespace mim {
    using namespace std;

    struct namespace_t;
    struct lang_codefiles_t;
    
    struct layered_class_vertex_t: android_vertex_t {
        using b = android_vertex_t;

        struct layerdef_t {
            string name;
            string mim_file;
            string kickoff_dir;
        };
        using layers_t = vector<layerdef_t>;

        layered_class_vertex_t(const string& name, const string& layer_name, const string& mim_file);
        layered_class_vertex_t(const string& name, const vector<string>& layer_names, const string& mim_file);
        layered_class_vertex_t(const layered_class_vertex_t&);
        vertex_t* clone() const override;

        bool merge(vertex_t* other_, int op) override;

        void customize_after_being_instantiated_by_a_template() override;
        bool pre_configure() override;

        void dump_(ostream&) const override;

        static string layerize(const string& name0, const string& layer_name);
        token_resolution_t resolve_token(const string& token) const override;

        string package() const;
        string layer_class_content(layers_t::const_iterator z) const;
        string layer_class_template() const;


    public:
        layers_t layers;
        string deepest_baseclass;
        string subhome;
    };

}


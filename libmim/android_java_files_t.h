#pragma once

#include <string>
#include <cassert>
#include "java_files_t.h"

namespace mim {
    using namespace std;

    struct namespace_t;
    struct android_vertex_t;

    struct android_java_files_t final: java_files_t {
        using b = java_files_t;
        android_java_files_t(namespace_t& vertex, const string& name);
        android_java_files_t(const android_java_files_t&);
        ~android_java_files_t() override;
        lang_codefiles_t* clone() const override;
    };


}


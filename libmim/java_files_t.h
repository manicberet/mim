#pragma once

#include <string>
#include <cassert>
#include <set>
#include "lang_codefiles_t.h"

namespace mim {
    using namespace std;
    struct namespace_t;

    struct java_files_t: lang_codefiles_t {
        using b = lang_codefiles_t;
        java_files_t(namespace_t& vertex, const string& name);
        java_files_t(const java_files_t&);
        lang_codefiles_t* clone() const override;
        void write_include_code(const set<string>& includes, ostream&) const override;
    };

}


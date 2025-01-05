#pragma once

#include <string>
#include <cassert>
#include <set>
#include "lang_codefiles_t.h"

namespace mim {
    using namespace std;
    struct namespace_t;

    struct cpp_files_t: lang_codefiles_t {
        using b = lang_codefiles_t;
        cpp_files_t(namespace_t& vertex, const string& name);
        cpp_files_t(const cpp_files_t&);
        lang_codefiles_t* clone() const override;
        void write_include_code(const set<string>& includes, ostream&) const override;
    };

}


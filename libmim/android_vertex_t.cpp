#include <sys/stat.h>
#include <sys/types.h>
#include <iostream>
#include <map>
#include <sstream>
#include <cassert>
#include <vector>
#include <filesystem>

#include "ko.h"

#include "android_vertex_t.h"
#include "android_java_files_t.h"

using namespace std;
using namespace mim;

using c = mim::android_vertex_t;

string c::package_ns = "us.cash";
string c::package_dir = "us/cash";

string c::cfg_str28 = "us.cash"; //Android app package name
string c::cfg_str32 = "US Cash"; //Android app name

c::android_vertex_t(const string& name, const string& mim_file): b(name, mim_file) {
}

c::android_vertex_t(const c& other): b(other) {
}

vertex_t* c::clone() const {
    return new c(*this);
}

string c::conf_target_dir(const string& lang) const {
    assert(lang == "java");
    return "us/android/app/src/main/java/" + package_dir;
}

lang_codefiles_t* c::create_lang_codefiles(const string& lang) {
    lang_codefiles_t* o = nullptr;
    if (lang == "java") {
        o = new android_java_files_t(*this, lang);
    }
    assert(o != nullptr);
    return o;
}

void c::dump_(ostream& os) const {
    {
        ind_t ind(os, "  ");
        os << "[] android vertex.\n";
    }
    b::dump_(os);
}


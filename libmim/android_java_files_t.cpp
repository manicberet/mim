#include <sys/stat.h>
#include <sys/types.h>
#include <iostream>
#include <map>
#include <sstream>
#include <cassert>
#include <vector>
#include <filesystem>

#include "ko.h"
#include "android_java_files_t.h"
#include "android_vertex_t.h"
#include "namespace_t.h"
#include "engine_t.h"

using namespace std;
using namespace mim;
using mim::cout;

using c = mim::android_java_files_t;

c::android_java_files_t(namespace_t& vertex, const string& name): b(vertex, name) {
    auto o = new java_files_t(vertex, name);
    o->subhome = "scr";
    assert(find(o->subhome) == end());
    emplace(o->subhome, o);
}

c::android_java_files_t(const c& other): b(other) {

}

c::~android_java_files_t() {
}

lang_codefiles_t* c::clone() const {
    //cout << "clone android_java_files_t" << endl;
    return new c(*this);
}




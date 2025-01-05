#include <sys/stat.h>
#include <sys/types.h>
#include <iostream>
#include <map>
#include <sstream>
#include <cassert>
#include <vector>
#include <filesystem>

#include "ko.h"

#include "tree_vertex_t.h"

using namespace std;
using namespace mim;

using c = tree_vertex_t;

c::tree_vertex_t(const string& name, const string& mim_file): b(name, mim_file) {
}
c::tree_vertex_t(const c& other): b(other) {
}

vertex_t* c::clone() const {
    return new c(*this);
}


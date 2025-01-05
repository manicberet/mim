#include <sys/stat.h>
#include <sys/types.h>
#include <iostream>
#include <map>
#include <sstream>
#include <cassert>
#include <vector>
#include <sstream>
#include <filesystem>

#include "ko.h"

#include "cpp_files_t.h"
#include "namespace_t.h"
#include "engine_t.h"

using namespace std;
using namespace mim;
using mim::cout;

using c = mim::cpp_files_t;

c::cpp_files_t(namespace_t& vertex, const string& name): b(vertex, name) {
}

c::cpp_files_t(const c& other): b(other) {

}

lang_codefiles_t* c::clone() const {
    return new c(*this);
}

void c::write_include_code(const set<string>& includes, ostream& os) const {
    for (auto& i: includes) {
        os << "#include " << i << ";\n";
    }
}


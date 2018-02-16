
#include "precomp.hpp"

namespace std {

thread_ostream tout(cout);
thread_endl_type tendl(tout.endl());

} // namespace std

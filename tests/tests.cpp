#include <type_from_string/type_from_string.hpp>

static_assert(
    std::is_same_v<
        type_from_string::from<"int">,
        int>
);

static_assert(
    std::is_same_v<
        type_from_string::from<"bool">,
        bool>
);

int main() {}
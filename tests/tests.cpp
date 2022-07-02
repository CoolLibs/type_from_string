#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
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

template<typename T>
auto say_type() -> std::string
{
    return "FAILED";
}
template<>
auto say_type<int>() -> std::string
{
    return "I say INT";
}
template<>
auto say_type<float>() -> std::string
{
    return "I say FLOAT";
}

TEST_CASE("At runtime")
{
    std::string type_as_string = "int";
    CHECK(
        TFS_EVALUATE_FUNCTION_TEMPLATE(say_type, type_as_string) ==
        "I say INT"
    );
}
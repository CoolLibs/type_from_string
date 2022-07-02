# ---HOW TO---
# Modify `all_associations()` and `includes()`, then run this script.
# ------------


def all_associations():
    return {
        "bool":               ["bool"],
        "int":                ["int"],
        "float":              ["float",  "vec1"],
        "glm::vec2":          ["float2", "vec2"],
        "glm::vec3":          ["float3", "vec3"],
        "glm::vec4":          ["float4", "vec4"],
        "Cool::RgbColor":     ["RgbColor"],
        "Cool::Angle":        ["Angle"],
        "Cool::Direction2D":  ["Direction2D"],
        "Cool::Hue":          ["Hue"],
        "Cool::ColorPalette": ["ColorPalette"],
    }


def includes():
    return f"""
#include <glm/glm.hpp>
"""


def string_to_type_associations():
    out = "\n"
    for key, values in all_associations().items():
        for value in values:
            out += f"""
template<>
struct from_impl<"{value}"> {{
    using type = {key};
}};
"""
    return out


def evaluate_function_template():
    out = "#define TFS_EVALUATE_FUNCTION_TEMPLATE(function_template, type_as_string) \\\n"
    out += "([&]() { \\\n"
    is_first = True
    for key, values in all_associations().items():
        for value in values:
            out += f'{"else " if not is_first else ""}if ((type_as_string) == "{value}") return function_template<{key}>();' + "\\\n"
            is_first = False

    out += f'else {{ assert(false && "Unknown type!"); return function_template<{list(all_associations().keys())[0]}>(); }} \\\n}})()'
    return out


if __name__ == '__main__':
    from tooling.generate_files import generate
    generate(
        folder="generated",
        files=[
            string_to_type_associations,
            includes,
            evaluate_function_template,
        ],
    )

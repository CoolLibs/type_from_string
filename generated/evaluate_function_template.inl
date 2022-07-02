/* -----------------------------------------------------------------------------
 * This file was automatically generated by a Python script.
 * PLEASE DON'T EDIT IT DIRECTLY, your changes would be overwritten the next time the script is run.
 * Instead, go to "generator.py" and edit the "evaluate_function_template" function there.
 * -----------------------------------------------------------------------------
 */
#define TFS_EVALUATE_FUNCTION_TEMPLATE(function_template, type_as_string) \
([&]() { \
if ((type_as_string) == "bool") return function_template<bool>();\
else if ((type_as_string) == "int") return function_template<int>();\
else if ((type_as_string) == "float") return function_template<float>();\
else if ((type_as_string) == "vec1") return function_template<float>();\
else if ((type_as_string) == "float2") return function_template<glm::vec2>();\
else if ((type_as_string) == "vec2") return function_template<glm::vec2>();\
else if ((type_as_string) == "float3") return function_template<glm::vec3>();\
else if ((type_as_string) == "vec3") return function_template<glm::vec3>();\
else if ((type_as_string) == "float4") return function_template<glm::vec4>();\
else if ((type_as_string) == "vec4") return function_template<glm::vec4>();\
else if ((type_as_string) == "Color") return function_template<Cool::Color>();\
else if ((type_as_string) == "Angle") return function_template<Cool::Angle>();\
else if ((type_as_string) == "Hue") return function_template<Cool::Hue>();\
else { assert(false && "Unknown type!"); return function_template<bool>(); } \
})()
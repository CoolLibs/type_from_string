#pragma once
#include <algorithm>
#include "../generated/includes.inl"

/// Thanks to https://vector-of-bool.github.io/2021/10/22/string-templates.html
/// and https://ctrpeach.io/posts/cpp20-string-literal-template-parameters/

namespace type_from_string {

namespace internal {

template<size_t N>
struct FixedString {
    constexpr FixedString(const char (&str)[N])
    {
        std::copy_n(str, N, value);
    }

    char value[N];
};

template<FixedString>
struct from_impl {};

#include "../generated/string_to_type_associations.inl"

} // namespace internal

template<internal::FixedString S>
using from = typename internal::from_impl<S>::type;

} // namespace type_from_string

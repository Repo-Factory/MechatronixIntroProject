// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from package1:msg/Time.idl
// generated code does not contain a copyright notice

#ifndef PACKAGE1__MSG__DETAIL__TIME__TRAITS_HPP_
#define PACKAGE1__MSG__DETAIL__TIME__TRAITS_HPP_

#include "package1/msg/detail/time__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<package1::msg::Time>()
{
  return "package1::msg::Time";
}

template<>
inline const char * name<package1::msg::Time>()
{
  return "package1/msg/Time";
}

template<>
struct has_fixed_size<package1::msg::Time>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<package1::msg::Time>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<package1::msg::Time>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PACKAGE1__MSG__DETAIL__TIME__TRAITS_HPP_

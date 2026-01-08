// Copyright 2026 VOIDMARE Team
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef _VOIDMARE_LIBS_RESULT_H
#define _VOIDMARE_LIBS_RESULT_H

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

// Represents the error code type.
//
// Notes:
//  - All defined error codes across the library
//    must have type vm_libs_err_t.
typedef uint16_t vm_libs_err_t;

// Represents the standard error codes.
//
// Notes:
//  - This is not the only source of error codes.
//    Some headers define their own error codes.
typedef enum vm_libs_err_code
{
  vm_libs_err_code_ok = (vm_libs_err_t)0,
  vm_libs_err_code_allocation_failed = (vm_libs_err_t)1,
  vm_libs_err_code_ptr_null = (vm_libs_err_t)2,
} vm_libs_err_code_t;

// Defines standard declaration and its methods
// for result types.
#define VOIDMARE_LIBS_RESULT_DEFINE(name, type)                                \
  typedef struct name                                                          \
  {                                                                            \
    vm_libs_err_t code;                                                        \
    type value;                                                                \
  } name##_t;                                                                  \
  inline name##_t name##_ok(type value)                                        \
  {                                                                            \
    return (name##_t){.value = value, .code = vm_libs_err_code_ok};            \
  }                                                                            \
  inline name##_t name##_err(vm_libs_err_t code)                               \
  {                                                                            \
    return (name##_t){.code = code};                                           \
  }

#ifdef __cplusplus
}
#endif

#endif

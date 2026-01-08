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

#ifndef _VOIDMARE_LIBS_SLICE_H
#define _VOIDMARE_LIBS_SLICE_H

#include "result.h"
#include <stddef.h>

#ifdef __cplusplus
extern "C"
{
#endif

VOIDMARE_LIBS_RESULT_DEFINE(vm_libs_slice_ptr_result, void *)

// Represents the dynamic slice.
typedef struct vm_libs_slice
{
  size_t capacity;
  size_t size;
  size_t elem_size;
  void *data;
} vm_libs_slice_t;

// Initializes a pointer to vm_libs_slice_t.
//
// Parameters:
// - slice: Slice to initialize.
// - elem_size: A element size, usually: sizeof(T).
// - initial_capacity: Initial capacity for slice.
//
// Error codes:
// - vm_libs_err_code_allocation_failed: It function fails to allocate data.
vm_libs_err_code_t vm_libs_slice_init(vm_libs_slice_t *slice, size_t elem_size, size_t initial_capacity);

// Resizes the slice to new capacity. Does nothing if new_capacity is
// already equal to old capacity.
//
// Parameters:
// - slice: Slice to resize, must be not NULL.
// - new_capacity: New capacity.
//
// Error codes:
// - vm_libs_err_code_ptr_null: If slice is NULL.
// - vm_libs_err_code_allocation_failed: If resizing failed.
vm_libs_err_code_t vm_libs_slice_resize(vm_libs_slice_t *slice,
					size_t new_capacity);

// Pushes new element to the slice data.
//
// Parameters:
// - slice: Slice where you push element, must be not NULL.
// - elem: New element to push.
//
// Notes:
// - It may resize the capacity if size is equal or greater
//   than the current capacity.
//
// Error codes:
// - vm_libs_err_code_ptr_null: If slice is NULL.
vm_libs_err_code_t vm_libs_slice_push(vm_libs_slice_t *slice, void *elem);

// Gets and returns the element from slice at given index.
//
// Parameters:
// - slice: Slice where you get element, must be not NULL.
// - index: An index where you want to get element at.
//
// Error codes:
// - vm_libs_err_code_ptr_null: If slice is NULL.
// - vm_libs_err_code_out_of_bounds: If index is out of bounds.
vm_libs_slice_ptr_result_t vm_libs_slice_at(vm_libs_slice_t *slice,
					    size_t index);

// Frees the slice, setting data, slice to null and size, capacity and elem_size
// to 0. Does nothing if slice is already NULL.
void vm_libs_slice_free(vm_libs_slice_t *slice);

#ifdef __cplusplus
}
#endif

#endif

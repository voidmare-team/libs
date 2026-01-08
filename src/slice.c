#include <stdlib.h>
#include <string.h>
#include <voidmare/libs/result.h>
#include <voidmare/libs/slice.h>

vm_libs_err_code_t vm_libs_slice_init(vm_libs_slice_t *slice, size_t elem_size,
				      size_t initial_capacity)
{
  slice->size = 0;
  slice->capacity = initial_capacity;
  slice->elem_size = elem_size;
  slice->data = malloc(slice->capacity * slice->elem_size);
  if (!slice->data)
  {
    return vm_libs_err_code_allocation_failed;
  }
  return vm_libs_err_code_ok;
}

vm_libs_err_code_t vm_libs_slice_resize(vm_libs_slice_t *slice,
					size_t new_capacity)
{
  if (!slice)
  {
    return vm_libs_err_code_ptr_null;
  }
  if (slice->capacity == new_capacity)
  {
    return vm_libs_err_code_ok;
  }
  slice->data = realloc(slice->data, new_capacity * slice->elem_size);
  if (!slice->data)
  {
    return vm_libs_err_code_allocation_failed;
  }
  slice->capacity = new_capacity;
  return vm_libs_err_code_ok;
}

vm_libs_slice_ptr_result_t vm_libs_slice_at(vm_libs_slice_t *slice,
					    size_t index)
{
  if (!slice)
  {
    return vm_libs_slice_ptr_result_err(vm_libs_err_code_ptr_null);
  }

  if (index >= slice->size)
  {
    return vm_libs_slice_ptr_result_err(vm_libs_err_code_out_of_bounds);
  }

  void *ptr = (unsigned char *)slice->data + index * slice->elem_size;
  return vm_libs_slice_ptr_result_ok(ptr);
}

vm_libs_err_code_t vm_libs_slice_push(vm_libs_slice_t *slice, void *elem)
{
  if (!slice)
  {
    return vm_libs_err_code_ptr_null;
  }

  if (slice->size >= slice->capacity)
  {
    vm_libs_err_code_t err = vm_libs_slice_resize(slice, slice->capacity * 2);
    if (err != vm_libs_err_code_ok)
    {
      return err;
    }
  }

  vm_libs_slice_ptr_result_t res = vm_libs_slice_at(slice, slice->size);
  if (res.code != vm_libs_err_code_ok)
  {
    return res.code;
  }

  memcpy(res.value, elem, slice->elem_size);
  slice->size++;
  return vm_libs_err_code_ok;
}

void vm_libs_slice_free(vm_libs_slice_t *slice)
{
  if (!slice)
  {
    return;
  }
  free(slice->data);
  slice->data = NULL;
  slice->size = slice->capacity = 0;
  slice->elem_size = 0;
}

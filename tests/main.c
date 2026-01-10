#include <stdio.h>
#include <voidmare/test.h>

int main()
{
  vm_test_suite_t suite;
  if (!vm_test_suite_init(&suite, 0))
  {
    printf("Failed to initialize test suite (exit code 1)");
    return 1;
  }
  vm_test_suite_free(&suite);
  return 0;
}

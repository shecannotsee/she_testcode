#include <iostream>
#include "t1_filesystem.h"
#include "t2_optional.h"
#include "t3_variant.h"

int main() {
  std::cout << "cpp17_test start------------------------------------------------------------------------------------\n";

  t1_filesystem::run();
  t2_optional::run();
  t3_variant::run();

  std::cout << "----------------------------------------------------------------------------------------------------\n";
  std::cout << "cpp17_test done\n";
  return 0;
}

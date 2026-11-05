#include "cachecraft/cache.hpp"

#include <cstdlib>
#include <iostream>
#include <optional>
#include <string>
#include <utility>

namespace {

int failures = 0;

void expect(bool condition, const std::string &description) {
  if (condition) {
    std::cout << "[PASS] " << description << '\n';
  } else {
    std::cerr << "[FAIL] " << description << '\n';
    ++failures;
  }
}

void test_set_and_get() {
  cachecraft::Cache cache;

  cache.set("language", "C++");
  expect(cache.get("language") == std::optional<std::string>{"C++"},
         "GET returns a value previously stored with SET");
}

void test_update_existing_key() {
  cachecraft::Cache cache;

  cache.set("language", "Python");
  cache.set("language", "C++");

  expect(cache.get("language") == std::optional<std::string>{"C++"},
         "SET updates an existing key");
}

void test_missing_key() {
  const cachecraft::Cache cache;

  expect(!cache.get("missing").has_value(),
         "GET returns no value for a missing key");
}

void test_empty_value() {
  cachecraft::Cache cache;

  cache.set("empty", "");

  const auto value = cache.get("empty");
  expect(value.has_value() && value->empty(),
         "An empty string is distinct from a missing key");
}

void test_delete_existing_key() {
  cachecraft::Cache cache;

  cache.set("temporary", "value");
  const bool erased = cache.erase("temporary");

  expect(erased, "DELETE reports success for an existing key");
  expect(!cache.get("temporary").has_value(),
         "Deleted key is no longer retrievable");
}

void test_delete_missing_key() {
  cachecraft::Cache cache;

  expect(!cache.erase("missing"), "DELETE reports failure for a missing key");
}

void test_independent_keys() {
  cachecraft::Cache cache;

  cache.set("first", "one");
  cache.set("second", "two");

  const bool erased = cache.erase("first");

  expect(erased, "DELETE successfully removes the first key");
  expect(cache.get("second") == std::optional<std::string>{"two"},
         "Deleting one key leaves other keys unchanged");
}

} // namespace

int main() {
  test_set_and_get();
  test_update_existing_key();
  test_missing_key();
  test_empty_value();
  test_delete_existing_key();
  test_delete_missing_key();
  test_independent_keys();

  if (failures != 0) {
    std::cerr << "\n" << failures << " test(s) failed.\n";
    return EXIT_FAILURE;
  }

  std::cout << "\nAll tests passed.\n";
  return EXIT_SUCCESS;
}

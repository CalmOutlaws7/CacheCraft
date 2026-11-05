#pragma once

#include <optional>
#include <string>
#include <unordered_map>

namespace cachecraft {

class Cache {
public:
  void set(std::string key, std::string value);

  [[nodiscard]] std::optional<std::string> get(const std::string &key) const;

  [[nodiscard]] bool erase(const std::string &key);

private:
  std::unordered_map<std::string, std::string> entries_;
};

} // namespace cachecraft

#include "cachecraft/cache.hpp"

#include <utility>

namespace cachecraft {

void Cache::set(std::string key, std::string value) {
  entries_.insert_or_assign(std::move(key), std::move(value));
}

std::optional<std::string> Cache::get(const std::string &key) const {
  const auto it = entries_.find(key);

  if (it == entries_.end()) {
    return std::nullopt;
  }

  return it->second;
}

bool Cache::erase(const std::string &key) { return entries_.erase(key) > 0; }

} // namespace cachecraft

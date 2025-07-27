/*
 * Flox Engine
 * Developed by FLOX Foundation (https://github.com/FLOX-Foundation)
 *
 * Copyright (c) 2025 FLOX Foundation
 * Licensed under the MIT License. See LICENSE file in the project root for full
 * license information.
 */

#include "flox-connectors/net/curl_session_pool.h"

#include <stdexcept>

namespace flox
{

CurlSessionPool::CurlSessionPool(std::size_t size)
{
  curl_global_init(CURL_GLOBAL_ALL);
  _pool.reserve(size);
  for (std::size_t i = 0; i < size; ++i)
  {
    CURL* h = curl_easy_init();
    if (!h)
    {
      throw std::runtime_error("curl_easy_init failed");
    }
    _pool.push_back(h);
  }
}

CurlSessionPool::~CurlSessionPool()
{
  for (auto* h : _pool)
  {
    curl_easy_cleanup(h);
  }
  curl_global_cleanup();
}

CURL* CurlSessionPool::acquire()
{
  std::lock_guard lock(_mutex);
  if (_pool.empty())
  {
    return curl_easy_init();
  }
  CURL* h = _pool.back();
  _pool.pop_back();
  return h;
}

void CurlSessionPool::release(CURL* h)
{
  if (!h)
  {
    return;
  }
  std::lock_guard lock(_mutex);
  _pool.push_back(h);
}

}  // namespace flox

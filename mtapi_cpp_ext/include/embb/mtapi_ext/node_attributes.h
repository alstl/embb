/*
 * Copyright (c) 2014-2015, Siemens AG. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef EMBB_MTAPI_NODE_ATTRIBUTES_H_
#define EMBB_MTAPI_NODE_ATTRIBUTES_H_

#include <embb/mtapi/c/mtapi.h>
#include <embb/base/core_set.h>
#include <embb/mtapi_ext/internal/check_status.h>

namespace embb {
namespace mtapi {

/**
 * Contains attributes of a Node.
 *
 * \ingroup CPP_MTAPI_EXT
 */
class NodeAttributes {
public:
  /**
   * Constructs a NodeAttributes object.
   */
  NodeAttributes() {
    mtapi_status_t status;
    mtapi_nodeattr_init(&attributes_, &status);
    internal::CheckStatus(status);
  }

  /**
   * Copies a NodeAttributes object.
   */
  NodeAttributes(
    NodeAttributes const & other       /**< The NodeAttributes to copy. */
    )
    : attributes_(other.attributes_) {
    // empty
  }

  /**
   * Copies a NodeAttributes object.
   */
  void operator=(
    NodeAttributes const & other       /**< The NodeAttributes to copy. */
    ) {
    attributes_ = other.attributes_;
  }

  NodeAttributes & SetCoreAffinity(embb::base::CoreSet const & cores) {
    mtapi_status_t status;
    mtapi_nodeattr_set(&attributes_, MTAPI_NODE_CORE_AFFINITY,
      &cores.GetInternal(), sizeof(embb_core_set_t), &status);
    internal::CheckStatus(status);
    return *this;
  }

  NodeAttributes & SetMaxTasks(mtapi_uint_t value) {
    mtapi_status_t status;
    mtapi_nodeattr_set(&attributes_, MTAPI_NODE_MAX_TASKS,
      &value, sizeof(value), &status);
    internal::CheckStatus(status);
    return *this;
  }

  NodeAttributes & SetMaxActions(mtapi_uint_t value) {
    mtapi_status_t status;
    mtapi_nodeattr_set(&attributes_, MTAPI_NODE_MAX_ACTIONS,
      &value, sizeof(value), &status);
    internal::CheckStatus(status);
    return *this;
  }

  NodeAttributes & SetMaxGroups(mtapi_uint_t value) {
    mtapi_status_t status;
    mtapi_nodeattr_set(&attributes_, MTAPI_NODE_MAX_GROUPS,
      &value, sizeof(value), &status);
    internal::CheckStatus(status);
    return *this;
  }

  NodeAttributes & SetMaxQueues(mtapi_uint_t value) {
    mtapi_status_t status;
    mtapi_nodeattr_set(&attributes_, MTAPI_NODE_MAX_QUEUES,
      &value, sizeof(value), &status);
    internal::CheckStatus(status);
    return *this;
  }

  NodeAttributes & SetQueueLimit(mtapi_uint_t value) {
    mtapi_status_t status;
    mtapi_nodeattr_set(&attributes_, MTAPI_NODE_QUEUE_LIMIT,
      &value, sizeof(value), &status);
    internal::CheckStatus(status);
    return *this;
  }

  NodeAttributes & SetMaxJobs(mtapi_uint_t value) {
    mtapi_status_t status;
    mtapi_nodeattr_set(&attributes_, MTAPI_NODE_MAX_JOBS,
      &value, sizeof(value), &status);
    internal::CheckStatus(status);
    return *this;
  }

  NodeAttributes & SetMaxActionsPerJob(mtapi_uint_t value) {
    mtapi_status_t status;
    mtapi_nodeattr_set(&attributes_, MTAPI_NODE_MAX_ACTIONS_PER_JOB,
      &value, sizeof(value), &status);
    internal::CheckStatus(status);
    return *this;
  }

  NodeAttributes & SetMaxPriorities(mtapi_uint_t value) {
    mtapi_status_t status;
    mtapi_nodeattr_set(&attributes_, MTAPI_NODE_MAX_PRIORITIES,
      &value, sizeof(value), &status);
    internal::CheckStatus(status);
    return *this;
  }

  /**
   * Returns the internal representation of this object.
   * Allows for interoperability with the C interface.
   *
   * \returns A reference to the internal mtapi_node_attributes_t structure.
   */
  mtapi_node_attributes_t const & GetInternal() const {
    return attributes_;
  }

private:
  mtapi_node_attributes_t attributes_;
};

} // namespace mtapi
} // namespace embb

#endif // EMBB_MTAPI_NODE_ATTRIBUTES_H_

/*
 * Copyright (c) 2014-2017, Siemens AG. All rights reserved.
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

#ifndef BASE_CPP_TEST_MEMORY_ALLOCATION_TEST_H_
#define BASE_CPP_TEST_MEMORY_ALLOCATION_TEST_H_

#include <partest/partest.h>
#include <embb/base/memory_allocation.h>

namespace embb {
namespace base {
namespace test {

class MemoryAllocationTest : public partest::TestCase {
 public:
  /**
  * Adds test methods.
  */
  MemoryAllocationTest();

 private:
  void ClassAllocationTest();
  void AllocatorTest();

  class DummyClassForAllocatorTests {
   public:
    unsigned int A;
    double B;
    long C;
    long long D;
    long E;
    unsigned int F;
  };

  class DummyClassForAlignedAllocation
    : public embb::base::CacheAlignedAllocatable {
   public:
    int a;
    size_t b;
  };

  class DummyClassForUnalignedAllocation
    : public embb::base::Allocatable {
   public:
    int a;
    size_t b;
  };
};

} // namespace test
} // namespace base
} // namespace embb


#endif // BASE_CPP_TEST_MEMORY_ALLOCATION_TEST_H_

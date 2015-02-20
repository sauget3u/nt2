//==============================================================================
//         Copyright 2014 - 2015   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_SDK_CUDA_CUDA_HPP_INCLUDED
#define NT2_SDK_CUDA_CUDA_HPP_INCLUDED

#include <boost/dispatch/functor/forward.hpp>
#include <boost/assert.hpp>

namespace nt2 { namespace memory
{
  template<class T> class cuda_buffer;
} }

namespace nt2 { namespace tag
{
  template<typename Site> struct cuda_ : Site
  {
    typedef void   device_tag;

    template<typename Container> struct device_traits
    {
      using value_type  = typename Container::declared_value_type;
      using buffer_type = memory::cuda_buffer<value_type>;
    };

    typedef Site  parent;
  };
} }

#ifdef NT2_HAS_CUDA

#define CUDA_ERROR(status)                                                      \
BOOST_VERIFY_MSG( status == cudaSuccess, cudaGetErrorString(status))            \
/**/

BOOST_DISPATCH_COMBINE_SITE( nt2::tag::cuda_<tag::cpu_> )
#endif

#endif

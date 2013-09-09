//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_ARITHMETIC_FUNCTIONS_ISQRT_HPP_INCLUDED
#define BOOST_SIMD_ARITHMETIC_FUNCTIONS_ISQRT_HPP_INCLUDED
#include <boost/simd/include/functor.hpp>
#include <boost/dispatch/include/functor.hpp>

namespace boost { namespace simd { namespace tag
  {
   /*!
      @brief  isqrt generic tag

      Represents the isqrt function in generic contexts.

      @par Models:
      Hierarchy
    **/
    struct isqrt_ : ext::elementwise_<isqrt_>
    {
      /// @brief Parent hierarchy
      typedef ext::elementwise_<isqrt_> parent;
    };
  }
  /*!
    Computes the integer truncation of the square root of its parameter.

    @par semantic:
    For any given value @c x of type @c T:

    @code
    as_integer<T> r = isqrt(x);
    @endcode

    is equivalent to:

    @code
    as_integer<T> r = toints(sqrt(tofloat(x)));
    @endcode


    @param  a0

    @return an integral value of the integral type associated to the input.

  **/
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::isqrt_, isqrt, 1)
} }

#endif



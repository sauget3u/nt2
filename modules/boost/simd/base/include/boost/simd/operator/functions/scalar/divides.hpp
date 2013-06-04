//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_OPERATOR_FUNCTIONS_SCALAR_DIVIDES_HPP_INCLUDED
#define BOOST_SIMD_OPERATOR_FUNCTIONS_SCALAR_DIVIDES_HPP_INCLUDED

#include <nt2/operator/functions/divides.hpp>

#ifdef BOOST_MSVC
  #pragma warning(push)
  #pragma warning(disable: 4723) // potential divide by 0
#endif

namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::divides_, tag::cpu_, (A0)
                            , (scalar_< fundamental_<A0> >)
                              (scalar_< fundamental_<A0> >)
                            )
  {
    typedef A0 result_type;
    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2) { return a0/a1; }
  };
} } }

#ifdef BOOST_MSVC
  #pragma warning(pop)
#endif

#endif

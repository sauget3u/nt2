//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_BITWISE_FUNCTION_SIMD_SSE_SSE2_SHRAI_HPP_INCLUDED
#define NT2_TOOLBOX_BITWISE_FUNCTION_SIMD_SSE_SSE2_SHRAI_HPP_INCLUDED
#include <nt2/sdk/meta/as_integer.hpp>
#include <nt2/sdk/meta/strip.hpp>
#include <nt2/include/functions/is_gtz.hpp>
#include <nt2/include/functions/select.hpp>
#include <nt2/include/functions/shri.hpp>
#include <nt2/include/functions/group.hpp>
#include <nt2/include/functions/split.hpp>

namespace nt2 { namespace functors
{
  template<class Extension,class Info>
  struct validate<shrai_,tag::simd_(tag::arithmetic_,Extension),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
    struct result<This(A0,A1)> :
      boost::mpl::and_<meta::is_integral<A0>
                      ,meta::is_scalar<A1>
                      ,meta::is_integral<A1>
                      > {};
  };
  template<class Extension,class Info>
  struct call<shrai_,tag::simd_(tag::arithmetic_,Extension),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0, class A1>
    struct result<This(A0,A1)>  : meta::strip<A0>{};

    NT2_FUNCTOR_CALL_DISPATCH(
      2,
      typename nt2::meta::scalar_of<A0>::type,
      (5, (unsigned_,int64_t,int32_t,int16_t,int8_t))
    )

    NT2_FUNCTOR_CALL_EVAL_IF(2,   unsigned_)
    {
      return shri(a0, a1);
    }
    NT2_FUNCTOR_CALL_EVAL_IF(2,     int64_t)
    {

      A0 that = {shrai(a0[0], a1), shrai(a0[1], a1)}; 
      return that;
    }
    NT2_FUNCTOR_CALL_EVAL_IF(2,     int32_t)
    {
      typedef typename meta::as_integer<A0,signed>::type sint;
      sint const that = {_mm_srai_epi32(simd::native_cast<sint>(a0), a1)};
      return simd::native_cast<A0>(that);
    }
    NT2_FUNCTOR_CALL_EVAL_IF(2,     int16_t)
    {
      typedef typename meta::as_integer<A0,signed>::type sint;
      sint const that =  {_mm_srai_epi16(simd::native_cast<sint>(a0), a1)};
      return simd::native_cast<A0>(that);
    }
    NT2_FUNCTOR_CALL_EVAL_IF(2,      int8_t)
    {
      typedef typename NT2_CALL_RETURN_TYPE(2)::type result_type;
      typedef simd::native<typename meta::int16_t_<A0>::type,tag::sse_> gen_type;
      gen_type a0h, a0l;
      boost::fusion::tie(a0l, a0h) = split(a0);
      return simd::native_cast<A0>(group(shrai(a0l, a1),shrai(a0h, a1)));
    }
  };
} }

#endif

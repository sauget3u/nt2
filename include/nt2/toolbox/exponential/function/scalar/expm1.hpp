//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_EXPONENTIAL_FUNCTION_SCALAR_EXPM1_HPP_INCLUDED
#define NT2_TOOLBOX_EXPONENTIAL_FUNCTION_SCALAR_EXPM1_HPP_INCLUDED
#include <nt2/sdk/constant/digits.hpp>
#include <nt2/sdk/constant/real.hpp>

#include <nt2/include/functions/log.hpp>
#include <nt2/include/functions/exp.hpp>
#include <nt2/include/functions/minusone.hpp>
#include <nt2/include/functions/abs.hpp>
#include <nt2/include/functions/is_invalid.hpp>

namespace nt2 { namespace functors
{

  //  no special validate for expm1

  /////////////////////////////////////////////////////////////////////////////
  // Compute expm1(const A0& a0)
  /////////////////////////////////////////////////////////////////////////////
  template<class Info>
  struct call<expm1_,tag::scalar_(tag::arithmetic_),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)> : 
      boost::result_of<meta::floating(A0)>{};

    NT2_FUNCTOR_CALL_DISPATCH(
      1,
      A0,
      (2, (real_,arithmetic_))
    )

    NT2_FUNCTOR_CALL_EVAL_IF(1,  real_)
    {
	const A0 u = nt2::exp(a0);
	if( is_invalid(u) || (nt2::abs(a0) > Half<A0>()))
	  {
	    return u-One<A0>();
	  }
	else if (u!=One<A0>())
	  {
	    return (u-One<A0>())*a0/nt2::log(u);
	  }
	else
	  {
	    return a0;
	  } 
    }
    NT2_FUNCTOR_CALL_EVAL_IF(1, arithmetic_)
    {
      return minusone(exp(a0)); 
    }
  };
} }


      
#endif

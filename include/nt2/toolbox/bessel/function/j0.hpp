//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_BESSEL_FUNCTION_J0_HPP_INCLUDED
#define NT2_TOOLBOX_BESSEL_FUNCTION_J0_HPP_INCLUDED
#include <nt2/include/simd.hpp>
#include <nt2/include/functor.hpp>
#include <nt2/toolbox/bessel/include.hpp>

namespace nt2 { namespace functors
  {	       
    struct j0_ {};
  }
  NT2_FUNCTION_IMPLEMENTATION(functors::j0_, j0, 1)
}
 
#include <nt2/toolbox/bessel/function/scalar/j0.hpp>
#include NT2_BESSEL_INCLUDE(j0.hpp) 

 
#endif

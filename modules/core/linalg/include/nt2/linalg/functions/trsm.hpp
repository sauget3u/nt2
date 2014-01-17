//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2013   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_TOOLBOX_LINALG_FUNCTIONS_TRSM_HPP_INCLUDED
#define NT2_TOOLBOX_LINALG_FUNCTIONS_TRSM_HPP_INCLUDED

/*!
  @file
  @brief Defines and implements lapack dsgesv function that computes the solution
  of real system of linear equations a*x = b with mixed precision.
**/

#include <nt2/include/functor.hpp>

namespace nt2
{
  namespace tag
  {
    /// @brief Defines gesvx function tag
    struct trsm_ : boost::dispatch::tag::formal_
    {
      /// INTERNAL ONLY
      typedef boost::dispatch::tag::formal_  parent;
    };
  }

  /*!
    @brief

    @param
    @param

    @return
  **/

  NT2_FUNCTION_IMPLEMENTATION_TPL (tag::trsm_, trsm
                                  , (A0 const&)(A1 const&)(A2 const&) (A3 const&)
                                    (A4 const&) (A5&)
                                  , 6
                                  );



}

#endif

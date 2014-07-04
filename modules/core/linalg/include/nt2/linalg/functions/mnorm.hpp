//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_LINALG_FUNCTIONS_MNORM_HPP_INCLUDED
#define NT2_LINALG_FUNCTIONS_MNORM_HPP_INCLUDED
#include <nt2/include/functor.hpp>

/*!
 * \ingroup algebra
 * \defgroup algebra_mnorm mnorm
 *
 * \par Description
 * compute the matricial norms of a matrix chosen by the optional second parameter
 * that can be 1,  2, inf or fro_
 * 1, 2 and inf can be given dynamically or statically as template parameter ie:
 * mnorm(a, 1) or mnorm<tag::One>(a) or mnorm<1>(a)
 * mnorm(a, 2) or mnorm<tag::Two>(a) or mnorm<2>(a) or mnorm(a)
 * mnorm(a, Inf<T>()) or mnorm<tag::Inf>(a)
 * mnorm(a, nt2::Fro) or mnorm<tag::Fro>(a)
 *
 * \par Header file
 *
 * \code
 * #include <nt2/include/functions/mnorm.hpp>
 * \endcode
 *
 *
 * mnorm can be used as
 * mnorm(a) and compute the 2 norm of a  matrix ie the largest singular value of the matrix
 *
 * \param a the matrix or vector expression a
 *
 **/

namespace nt2 { namespace tag
  {
    /*!
     * \brief Define the tag mnorm_ of functor mnorm
     *        in namespace nt2::tag for toolbox algebra
    **/
    struct mnorm_ :  boost::dispatch::tag::formal_
    {
      /// INTERNAL ONLY
      typedef  boost::dispatch::tag::formal_ parent;
    };
  }

  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::mnorm_, mnorm, 1)
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::mnorm_, mnorm, 2)
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::mnorm_, mnorm2, 1)

  template < class T, class A>
  BOOST_FORCEINLINE
  typename meta::as_real<typename A::value_type>::type
  mnorm(const A& a)
  {
    return mnorm(a, nt2::meta::as_<T>());
  }
}

#endif


//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
/*!
 * \file
**/
#ifndef BOOST_SIMD_CONSTANT_CONSTANTS_FACT_4_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_CONSTANTS_FACT_4_HPP_INCLUDED

#include <boost/simd/include/functor.hpp>
#include <boost/simd/constant/register.hpp>
#include <boost/simd/constant/hierarchy.hpp>

/*!
 * \ingroup boost_simd_constant
 * \defgroup boost_simd_constant_fact_4 Fact_4
 *
 * \par Description
 * Constant Fact_4 4! = 24
 *
 * \par Header file
 *
 * \code
 * #include <nt2/include/functions/fact_4.hpp>
 * \endcode
 *
 *
 * \synopsis
 *
 * \code
 * namespace boost::simd
 * {
 *   template <class T,class A0>
 *     meta::call<tag::fact_4_(A0)>::type
 *     Fact_4();
 * }
 * \endcode
 *
 *
 * \param T template parameter of Fact_4
 *
 * \return type T value
 *
 *
**/

namespace boost { namespace simd
{
  namespace tag
  {
    /*!
     * \brief Define the tag Fact_4 of functor Fact_4
     *        in namespace boost::simd::tag for toolbox boost.simd.constant
    **/
    BOOST_SIMD_CONSTANT_REGISTER( Fact_4,double
                                , 24, 0x41c00000, 0x4038000000000000ll
                                );
  }

  BOOST_SIMD_CONSTANT_IMPLEMENTATION(boost::simd::tag::Fact_4, Fact_4)
  BOOST_SIMD_CONSTANT_IMPLEMENTATION(boost::simd::tag::Fact_4, Twentyfour)
} }

#include <boost/simd/constant/common.hpp>

#endif
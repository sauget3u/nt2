//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
/*!
 * \file
**/
#ifndef NT2_TOOLBOX_CEPHES_FUNCTIONS_NBDTRC_HPP_INCLUDED
#define NT2_TOOLBOX_CEPHES_FUNCTIONS_NBDTRC_HPP_INCLUDED
#include <nt2/include/functor.hpp>

/*!
 * \ingroup cephes
 * \defgroup cephes_nbdtrc nbdtrc
 *
 * \par Description
 * Please for details consult the proper documentation of the external
 * library cephes.
 *
 * \par Header file
 *
 * \code
 * #include <nt2/toolbox/cephes/include/functions/nbdtrc.hpp>
 * \endcode
 *
 *
 * \synopsis
 *
 * \code
 * namespace nt2
 * {
 *   namespace cephes
 *   {
 *     template <class A0>
 *       meta::call<tag::nbdtrc_(A0,A0,A0)>::type
 *       nbdtrc(const A0 & a0,const A0 & a1,const A0 & a2);
 *   }
 * }
 * \endcode
 *
 * \param a0 the first parameter of nbdtrc
 * \param a1 the second parameter of nbdtrc
 * \param a2 the third parameter of nbdtrc
 *
 * \return a value of the common type of the parameters
 *
 * \par Notes
 * In SIMD mode, this function acts elementwise on the inputs vectors elements
 * \par
 * When calling external library, nt2 simply encapsulates the
 * original proper call to provide easy use.
 * \par
 * Remenber that SIMD implementation is therefore merely
 * mapping the scalar function to each SIMD vectors elements
 * and will not provide acceleration, but ease.
 * \par
 * cephes library defines functions for float and double entries.
 * \par
 * As they are written in C the original name of the float version is
 * generally terminated by and extra 'f',
 * this is not the case for the nt2 version which dispatch to
 * the correct function according to the inputs types.
 *
**/

namespace nt2 { namespace cephes { namespace tag
  {
    /*!
     * \brief Define the tag nbdtrc_ of functor nbdtrc
     *        in namespace nt2::cephes::tag for toolbox cephes
    **/
    struct nbdtrc_ : ext::elementwise_<nbdtrc_> { typedef ext::elementwise_<nbdtrc_> parent; };
  }
  NT2_FUNCTION_IMPLEMENTATION(cephes::tag::nbdtrc_, nbdtrc, 3)
  } }

#include <nt2/toolbox/cephes/functions/scalar/nbdtrc.hpp>
// #include <nt2/toolbox/cephes/functions/simd/all/nbdtrc.hpp>

#endif

// modified by jt the 29/12/2010

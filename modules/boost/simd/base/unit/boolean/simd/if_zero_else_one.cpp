//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <boost/simd/boolean/include/functions/if_zero_else_one.hpp>
#include <boost/dispatch/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests/relation.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <boost/simd/include/constants/zero.hpp>
#include <boost/simd/include/constants/mzero.hpp>
#include <boost/simd/include/constants/one.hpp>
#include <boost/simd/include/constants/mone.hpp>
#include <boost/simd/include/constants/quarter.hpp>
#include <boost/simd/include/constants/two.hpp>
#include <boost/simd/include/constants/half.hpp>
#include <boost/simd/include/constants/inf.hpp>
#include <boost/simd/include/constants/minf.hpp>
#include <boost/simd/include/constants/nan.hpp>
#include <boost/simd/include/constants/true.hpp>
#include <boost/simd/include/constants/false.hpp>
#include <boost/simd/sdk/config.hpp>
#include <boost/simd/sdk/simd/io.hpp>

NT2_TEST_CASE_TPL ( if_zero_else_one_real__1_0,  BOOST_SIMD_SIMD_REAL_TYPES)
{
  using boost::simd::if_zero_else_one;
  using boost::simd::tag::if_zero_else_one_;
  using boost::simd::native;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef native<T,ext_t>                  vT;
  typedef typename boost::dispatch::meta::call<if_zero_else_one_(vT)>::type r_t;

  // specific values tests
  NT2_TEST_EQUAL(if_zero_else_one(boost::simd::Inf<vT>()), boost::simd::Zero<r_t>());
  NT2_TEST_EQUAL(if_zero_else_one(boost::simd::Minf<vT>()), boost::simd::Zero<r_t>());
  NT2_TEST_EQUAL(if_zero_else_one(boost::simd::Nan<vT>()), boost::simd::Zero<r_t>());
  NT2_TEST_EQUAL(if_zero_else_one(boost::simd::Mzero<vT>()), boost::simd::One<r_t>());
  NT2_TEST_EQUAL(if_zero_else_one(boost::simd::Half<vT>()), boost::simd::Zero<r_t>());
  NT2_TEST_EQUAL(if_zero_else_one(boost::simd::Mone<vT>()), boost::simd::Zero<r_t>());
  NT2_TEST_EQUAL(if_zero_else_one(boost::simd::One<vT>()), boost::simd::Zero<r_t>());
  NT2_TEST_EQUAL(if_zero_else_one(boost::simd::Quarter<vT>()), boost::simd::Zero<r_t>());
  NT2_TEST_EQUAL(if_zero_else_one(boost::simd::Two<vT>()), boost::simd::Zero<r_t>());
  NT2_TEST_EQUAL(if_zero_else_one(boost::simd::Zero<vT>()), boost::simd::One<r_t>());
} // end of test for floating_

NT2_TEST_CASE_TPL ( if_zero_else_one_,  BOOST_SIMD_SIMD_TYPES)
{
  using boost::simd::if_zero_else_one;
  using boost::simd::tag::if_zero_else_one_;
  using boost::simd::native;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef native<T,ext_t>                  vT;
  typedef typename boost::dispatch::meta::call<if_zero_else_one_(vT)>::type r_t;

  // specific values tests
  NT2_TEST_EQUAL(if_zero_else_one(boost::simd::One<vT>()), boost::simd::Zero<r_t>());
  NT2_TEST_EQUAL(if_zero_else_one(boost::simd::Two<vT>()), boost::simd::Zero<r_t>());
  NT2_TEST_EQUAL(if_zero_else_one(boost::simd::Zero<vT>()), boost::simd::One<r_t>());
} // end of test for floating_

NT2_TEST_CASE_TPL ( if_zero_else_onel,  BOOST_SIMD_SIMD_TYPES)
{
  using boost::simd::if_zero_else_one;
  using boost::simd::tag::if_zero_else_one_;
  using boost::simd::native;
  typedef BOOST_SIMD_DEFAULT_EXTENSION  ext_t;
  typedef native<T,ext_t>                  vT;
  typedef typename boost::dispatch::meta::call<if_zero_else_one_(vT)>::type r_t;
  typedef native< boost::simd::logical<T>, ext_t> vlT;

  // specific values tests
  NT2_TEST_EQUAL(if_zero_else_one(boost::simd::True<vlT>()), boost::simd::Zero<r_t>());
  NT2_TEST_EQUAL(if_zero_else_one(boost::simd::False<vlT>()), boost::simd::One<r_t>());
} // end of test for floating_

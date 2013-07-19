//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 boost.simd.arithmetic toolbox - toints/simd Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of boost.simd.arithmetic components in simd mode
//////////////////////////////////////////////////////////////////////////////

#include <boost/simd/arithmetic/include/functions/toints.hpp>
#include <boost/simd/sdk/simd/native.hpp>
#include <boost/dispatch/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/tests/type_expr.hpp>
#include <nt2/sdk/unit/tests/relation.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <boost/simd/include/functions/splat.hpp>
#include <boost/simd/include/functions/multiplies.hpp>
#include <boost/simd/include/constants/inf.hpp>
#include <boost/simd/include/constants/minf.hpp>
#include <boost/simd/include/constants/nan.hpp>
#include <boost/simd/include/constants/zero.hpp>
#include <boost/simd/include/constants/one.hpp>
#include <boost/simd/include/constants/mone.hpp>
#include <boost/simd/sdk/simd/io.hpp>
#include <boost/simd/include/functions/simd/make.hpp>



NT2_TEST_CASE_TPL ( toints_real,  BOOST_SIMD_SIMD_REAL_TYPES)
{
  using boost::simd::toints;
  using boost::simd::tag::toints_;
  using boost::simd::native;
  typedef BOOST_SIMD_DEFAULT_EXTENSION                                ext_t;
  typedef native<T,ext_t>                                                vT;
  typedef typename boost::dispatch::meta::as_integer<vT, signed>::type   wished_r_t;
  typedef typename boost::dispatch::meta::call<toints_(vT)>::type       r_t;
  typedef typename boost::dispatch::meta::call<toints_(T)>::type       sr_t;

  // return type conformity test
  NT2_TEST_TYPE_IS(r_t, wished_r_t);

  // specific values tests
  NT2_TEST_EQUAL(toints(boost::simd::splat<vT>(T(1.5)*boost::simd::Valmax<sr_t>())),  boost::simd::Valmax<r_t>());
  NT2_TEST_EQUAL(toints(boost::simd::splat<vT>(T(1.5)*boost::simd::Valmin<sr_t>())),  boost::simd::Valmin<r_t>());
  NT2_TEST_EQUAL(toints(boost::simd::splat<vT>(T(2)*boost::simd::Valmax<sr_t>())),  boost::simd::Valmax<r_t>());
  NT2_TEST_EQUAL(toints(boost::simd::splat<vT>(T(2)*boost::simd::Valmin<sr_t>())),  boost::simd::Valmin<r_t>());
  NT2_TEST_EQUAL(toints(boost::simd::Inf<vT>()),  boost::simd::Inf<r_t>());
  NT2_TEST_EQUAL(toints(boost::simd::splat<vT>(T(1)/T(0))),  boost::simd::Inf<r_t>());
  NT2_TEST_EQUAL(toints(boost::simd::Minf<vT>()), boost::simd::Minf<r_t>());
  NT2_TEST_EQUAL(toints(boost::simd::splat<vT>(T(-1)/T(0))),  boost::simd::Minf<r_t>());
  NT2_TEST_EQUAL(toints(boost::simd::Mone<vT>()), boost::simd::Mone<r_t>());
  NT2_TEST_EQUAL(toints(boost::simd::splat<vT>(T(0)/T(0))),  boost::simd::Zero<r_t>());
  NT2_TEST_EQUAL(toints(boost::simd::Nan<vT>()),  boost::simd::Zero<r_t>());
  NT2_TEST_EQUAL(toints(boost::simd::One<vT>()),  boost::simd::One<r_t>());
  NT2_TEST_EQUAL(toints(boost::simd::Zero<vT>()), boost::simd::Zero<r_t>());
} // end of test for floating_

NT2_TEST_CASE_TPL ( toints_real2,   BOOST_SIMD_SIMD_REAL_TYPES)
{
  using nt2::toints;
  using nt2::tag::toints_;
  using boost::simd::native;
  typedef BOOST_SIMD_DEFAULT_EXTENSION                                ext_t;
  typedef native<T,ext_t>                                                vT;
  typedef typename boost::dispatch::meta::call<toints_(vT)>::type      r_t;
  typedef typename boost::dispatch::meta::call<toints_(T)>::type        iT;
  typedef native<iT,ext_t>                                              ivT;

  T data[] = {nt2::One<T>(), nt2::Inf<T>(), nt2::Minf<T>(), nt2::Nan<T>(),nt2::One<T>(), nt2::Inf<T>(), nt2::Minf<T>(), nt2::Nan<T>(), };
  iT idat[] = {nt2::One<iT>(), nt2::Inf<iT>(), nt2::Minf<iT>(), nt2::Nan<iT>(), nt2::One<iT>(), nt2::Inf<iT>(), nt2::Minf<iT>(), nt2::Nan<iT>()};
  nt2::uint32_t NR =  (sizeof(data)/sizeof(T));
  for(nt2::uint32_t j = 0; j < NR;j+=nt2::meta::cardinal_of<vT>::value)
  {
    vT   a =  nt2::aligned_load<vT>(&data[0],j);
    ivT ia =  nt2::aligned_load<ivT>(&idat[0],j);
    NT2_TEST_EQUAL(toints(a), ia);
  }
}

NT2_TEST_CASE_TPL ( toints_unsigned_int,  BOOST_SIMD_UNSIGNED_TYPES)
{

  using boost::simd::toints;
  using boost::simd::tag::toints_;
  using boost::simd::native;
  typedef BOOST_SIMD_DEFAULT_EXTENSION                                ext_t;
  typedef native<T,ext_t>                                                vT;
  typedef typename boost::dispatch::meta::as_integer<vT, signed>::type   wished_r_t;
  typedef typename boost::dispatch::meta::call<toints_(vT)>::type       r_t;

  // return type conformity test
  NT2_TEST_TYPE_IS(r_t, wished_r_t);

  // specific values tests
  NT2_TEST_EQUAL(toints(boost::simd::One<vT>()),  boost::simd::One<r_t>());
  NT2_TEST_EQUAL(toints(boost::simd::Zero<vT>()), boost::simd::Zero<r_t>());
} // end of test for unsigned_int_

NT2_TEST_CASE_TPL ( toints_signed,  BOOST_SIMD_INTEGRAL_SIGNED_TYPES)
{

  using boost::simd::toints;
  using boost::simd::tag::toints_;
  using boost::simd::native;
  typedef BOOST_SIMD_DEFAULT_EXTENSION                                ext_t;
  typedef native<T,ext_t>                                                vT;
  typedef typename boost::dispatch::meta::as_integer<vT, signed>::type   wished_r_t;
  typedef typename boost::dispatch::meta::call<toints_(vT)>::type       r_t;

  // return type conformity test
  NT2_TEST_TYPE_IS(r_t, wished_r_t);

  // specific values tests
  NT2_TEST_EQUAL(toints(boost::simd::Mone<vT>()), boost::simd::Mone<r_t>());
  NT2_TEST_EQUAL(toints(boost::simd::One<vT>()),  boost::simd::One<r_t>());
  NT2_TEST_EQUAL(toints(boost::simd::Zero<vT>()), boost::simd::Zero<r_t>());
} // end of test for signed_int_

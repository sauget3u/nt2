//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <boost/simd/ieee/include/functions/modf.hpp>
#include <boost/simd/sdk/simd/native.hpp>
#include <boost/simd/sdk/simd/io.hpp>
#include <boost/simd/include/functions/splat.hpp>
#include <boost/simd/include/functions/trunc.hpp>
#include <boost/dispatch/functor/meta/call.hpp>
#include <boost/fusion/include/vector_tie.hpp>

#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/unit/tests/relation.hpp>
#include <nt2/sdk/unit/tests/type_expr.hpp>

NT2_TEST_CASE_TPL( modf, BOOST_SIMD_SIMD_TYPES)
{
  using boost::simd::modf;
  using boost::simd::splat;
  using boost::simd::tag::modf_;
  using boost::simd::native;

  typedef native<T,NT2_SIMD_DEFAULT_EXTENSION>  vT;

  NT2_TEST_TYPE_IS( (typename boost::dispatch::meta::call<modf_(vT)>::type)
                  , (std::pair<vT,vT>)
                  );

  {
    vT frac;
    vT ent;

    modf(splat<vT>(1.5), frac, ent);
    NT2_TEST_EQUAL(ent, boost::simd::trunc(splat<vT>(1.5)));
    NT2_TEST_EQUAL(frac, splat<vT>(.5));
  }

  {
    vT frac;
    vT ent;

    frac = modf(splat<vT>(1.5), ent);
    NT2_TEST_EQUAL(ent, boost::simd::trunc(splat<vT>(1.5)));
    NT2_TEST_EQUAL(frac, splat<vT>(.5));
  }

  {
    vT frac;
    vT ent;

    boost::fusion::vector_tie(frac,ent) = modf(splat<vT>(1.5));
    NT2_TEST_EQUAL(ent, boost::simd::trunc(splat<vT>(1.5)));
    NT2_TEST_EQUAL(frac, splat<vT>(.5));
  }

  {
    std::pair<vT,vT> p;

    p = modf(splat<vT>(1.5));
    NT2_TEST_EQUAL(p.first , splat<vT>(.5));
    NT2_TEST_EQUAL(p.second  , boost::simd::trunc(splat<vT>(1.5)));
  }
}

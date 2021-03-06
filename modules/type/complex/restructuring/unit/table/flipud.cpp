//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <nt2/table.hpp>
#include <nt2/include/functions/flipud.hpp>
#include <nt2/include/functions/ones.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/unit/tests/relation.hpp>

NT2_TEST_CASE_TPL( flipud_scalar, NT2_TYPES )
{
  typedef std::complex<T> cT;
  cT x = nt2::flipud(cT(42));
  NT2_TEST_EQUAL( x, cT(42) );
}

NT2_TEST_CASE_TPL( flipud, NT2_TYPES )
{
  typedef std::complex<T> cT;
  nt2::table<cT> x,y( nt2::of_size(5,3) );

  for(int j=1;j<=3;j++)
    for(int i=1;i<=5;i++)
      y(i,j) = cT(i + 10*j);

  x = nt2::flipud(y);

  for(int j=1;j<=3;j++)
  {
    for(int i=1;i<=5;i++)
    {
      NT2_TEST_EQUAL( x(i,j),y(6-i,j) );
    }
  }
}

##############################################################################
###   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
###   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
###
###          Distributed under the Boost Software License, Version 1.0
###                 See accompanying file LICENSE.txt or copy at
###                     http://www.boost.org/LICENSE_1_0.txt
##############################################################################

SET( SOURCES
  if_zero_else.cpp
  if_else_zero.cpp
  if_allbits_else.cpp
  if_else_allbits.cpp
  if_one_else_zero.cpp
  if_zero_else_one.cpp
  ifnotadd.cpp
  ifnotsub.cpp
  ifnotinc.cpp
  ifnotdec.cpp
  negif.cpp
  negifnot.cpp
  seladd.cpp
  selsub.cpp
  selinc.cpp
  seldec.cpp
  logical_andnot.cpp
  logical_ornot.cpp
  logical_notand.cpp
  logical_notor.cpp
  mask2logical.cpp
# List of simd test files for toolbox boolean
   )

nt2_module_add_tests(boost.simd.base.boolean.simd.unit ${SOURCES})

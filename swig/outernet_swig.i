/* -*- c++ -*- */

#define OUTERNET_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "outernet_swig_doc.i"

%{
#include "outernet/descrambler308.h"
#include "outernet/invert_bit.h"
%}


%include "outernet/descrambler308.h"
GR_SWIG_BLOCK_MAGIC2(outernet, descrambler308);

%include "outernet/invert_bit.h"
GR_SWIG_BLOCK_MAGIC2(outernet, invert_bit);

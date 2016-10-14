/* -*- c++ -*- */
/*
 * gr-outernet GNUradio OOT module for Outernet
 *
 * Copyright 2016 Daniel Estevez <daniel@destevez.net>.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "invert_bit_impl.h"

namespace gr {
  namespace outernet {

    invert_bit::sptr
    invert_bit::make()
    {
      return gnuradio::get_initial_sptr
        (new invert_bit_impl());
    }

    /*
     * The private constructor
     */
    invert_bit_impl::invert_bit_impl()
      : gr::sync_block("invert_bit",
	      gr::io_signature::make(1, 1, sizeof(unsigned char)),
              gr::io_signature::make(1, 1, sizeof(unsigned char)))
    {}

    /*
     * Our virtual destructor.
     */
    invert_bit_impl::~invert_bit_impl()
    {
    }

    int
    invert_bit_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      const unsigned char *in = (const unsigned char *) input_items[0];
      unsigned char *out = (unsigned char *) output_items[0];

      for (int i = 0; i < noutput_items; i++) {
	out[i] = in[i] ^ 1;
      }

      return noutput_items;
    }

  } /* namespace outernet */
} /* namespace gr */


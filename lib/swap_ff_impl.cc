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
#include "swap_ff_impl.h"

namespace gr {
  namespace outernet {

    swap_ff::sptr
    swap_ff::make()
    {
      return gnuradio::get_initial_sptr
        (new swap_ff_impl());
    }

    /*
     * The private constructor
     */
    swap_ff_impl::swap_ff_impl()
      : gr::sync_block("swap_ff",
              gr::io_signature::make(1, 1, sizeof(float)),
              gr::io_signature::make(1, 1, sizeof(float)))
    {
      set_output_multiple(2);
    }

    /*
     * Our virtual destructor.
     */
    swap_ff_impl::~swap_ff_impl()
    {
    }

    int
    swap_ff_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      const float *in = (const float *) input_items[0];
      float *out = (float *) output_items[0];

      assert(noutput_items % 2 == 0);

      for (int i = 0; i < noutput_items; i += 2) {
	out[i] = in[i+1];
	out[i+1] = in[i];
      }

      return noutput_items;
    }

  } /* namespace outernet */
} /* namespace gr */


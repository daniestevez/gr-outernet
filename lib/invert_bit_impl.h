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

#ifndef INCLUDED_OUTERNET_INVERT_BIT_IMPL_H
#define INCLUDED_OUTERNET_INVERT_BIT_IMPL_H

#include <outernet/invert_bit.h>

namespace gr {
  namespace outernet {

    class invert_bit_impl : public invert_bit
    {
     private:
      // Nothing to declare in this block.

     public:
      invert_bit_impl();
      ~invert_bit_impl();

      // Where all the action really happens
      int work(int noutput_items,
         gr_vector_const_void_star &input_items,
         gr_vector_void_star &output_items);
    };

  } // namespace outernet
} // namespace gr

#endif /* INCLUDED_OUTERNET_INVERT_BIT_IMPL_H */


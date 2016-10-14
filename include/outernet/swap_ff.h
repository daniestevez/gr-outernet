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

#ifndef INCLUDED_OUTERNET_SWAP_FF_H
#define INCLUDED_OUTERNET_SWAP_FF_H

#include <outernet/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace outernet {

    /*!
     * \brief <+description of block+>
     * \ingroup outernet
     *
     */
    class OUTERNET_API swap_ff : virtual public gr::sync_block
    {
     public:
      typedef boost::shared_ptr<swap_ff> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of outernet::swap_ff.
       *
       * To avoid accidental use of raw pointers, outernet::swap_ff's
       * constructor is in a private implementation
       * class. outernet::swap_ff::make is the public interface for
       * creating new instances.
       */
      static sptr make();
    };

  } // namespace outernet
} // namespace gr

#endif /* INCLUDED_OUTERNET_SWAP_FF_H */


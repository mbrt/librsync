/*=                                     -*- c-file-style: "bsd" -*-
 * rproxy -- dynamic caching and delta update in HTTP
 * $Id$
 * 
 * Copyright (C) 2000 by Martin Pool <mbp@humbug.org.au>
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 2.1 of
 * the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

/*
 * This table describes each of the opcodes present in the binary
 * protocol, which lets us emit and inhale them without writing code
 * for each.
 *
 * For each command we give the command byte, and the length of the
 * first and second parameters if any.  The total length is therefore
 * one (for the command byte) plus these two lengths.
 *
 * Actually, perhaps it would be better just to generate this table by
 * a script, so that we can have all the values in an array ready to
 * decode?  We need to also handle immediate-mode operations.
 *
 * When *encoding*, we need to look up based on the operation type,
 * the literal value of the first parameter, the length of the first
 * parameter and the length of the second parameter.  From this we
 * know what command byte we want and based on that we can reverse the
 * process and generate the actual stream from this table.
 */

typedef struct hs_prototab_ent {
    hs_op_kind_t        kind;
    int                 immediate;
    size_t              len_1, len_2, total_size;
} hs_prototab_ent_t;

extern const hs_prototab_ent_t _hs_prototab[];

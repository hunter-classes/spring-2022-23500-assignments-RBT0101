/* This testcase is part of GDB, the GNU debugger.

   Copyright 2021-2022 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#include <unistd.h>

static unsigned int global_counter = 1;

static volatile unsigned int global_var = 123;

static void
maybe_stop_here ()
{
}

int
main (void)
{
  global_counter = 1;

  while (global_counter > 0)
    {
      global_counter++;

      /* Less than 1s, so the counter increments at least once while
	 the .exp sleep 1s, but slow enough that the counter doesn't
	 wrap in 1s.  */
      usleep (5000);

      maybe_stop_here ();
    }

  return 0;
}

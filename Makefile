#    Copyright (C) 2012 Simon Sickle <simon@simonsickle.com>
#
#    This program is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program.  If not, see
#    <http://www.gnu.org/licenses/>.

CC      = /usr/bin/gcc
CFLAGS  = -m32 -Wall -O3
INCDIR	= -I/usr/include/ -I.
LIBDIR  = /usr/lib
LDFLAGS = -L/usr/lib -static
RM      = rm -f
CP	= cp

TRG = build_helper
OBJ = build_rom.o build_kernel.o menu.o

all: $(OBJ)
	$(CC) $(CFLAGS) $(INCDIR) -o $(TRG) $(OBJ) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) *.o
	$(RM) *.d
	$(RM) build_helper

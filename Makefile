# Makefile for mac-encheez
# Copyright 2017 Eric Smith <spacewar@gmail.com>

# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License version 3 as
# published by the Free Software Foundation.  Note that no permission
# is granted to redistribute or modify this program under the terms
# of any other version of the General Public License.
# 
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program (in the file "GPL-3.0.txt"); if not,
# see <http://www.gnu.org/licenses/>.


# It's entirely likely that you'll want to override these variables
# on the make command line
PREFIX = /usr/local
LIBDIR = $(PREFIX)/lib
BINDIR = $(PREFIX)/bin

CFLAGS = -Wall -Wextra -Werror
override CFLAGS += -fpic

all: libfakemac.so

libfakemac.o: libfakemac.c

libfakemac.so: libfakemac.o
	gcc $(CFLAGS) -shared -ldl -o libfakemac.so libfakemac.o

install:
	install -m 0755 libfakemac.so $(DESTDIR)$(LIBDIR)
	install -m 0755 encheez $(DESTDIR)$(BINDIR)

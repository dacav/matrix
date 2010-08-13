# Copyright (C) 2010 Giovanni [dacav] Simoni
#                    <simgidacav@gmail.com>
# 
# This program is free software; you can redistribute it and/or 
# modify it under the terms of the GNU General Public License 
# as published by the Free Software Foundation; either 
# version 3 of the License, or (at your option) any later 
# version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
# 

AM_CXXFLAGS = -I$(top_srcdir)/src/ -I./ -Wall -Werror
AM_LDDFLAGS = -L$(top_srcdir)/src/ -L./ -L../

check_PROGRAMS = test_base \
                 test_exceptions

TESTS = $(check_PROGRAMS)
#LDADD = -lmatrix

test_base_SOURCES = test_base.cpp
test_exceptions_SOURCES = test_exceptions.cpp

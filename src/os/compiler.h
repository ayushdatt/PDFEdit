/*
 * PDFedit - free program for PDF document manipulation.
 * Copyright (C) 2006, 2007, 2008  PDFedit team: Michal Hocko,
 *                                              Miroslav Jahoda,
 *                                              Jozef Misutka,
 *                                              Martin Petricek
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program (in doc/LICENSE.GPL); if not, write to the 
 * Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, 
 * MA  02111-1307  USA
 *
 * Project is hosted on http://sourceforge.net/projects/pdfedit
 */
// vim:tabstop=4:shiftwidth=4:noexpandtab:textwidth=80

#ifndef _COMPILER_H_
#define _COMPILER_H_

// default definitions for compiler specific attributes 
#define UNUSED_PARAM
#define WARN_UNUSED_RESULT
#define DEPRECATED

//
// GCC specific stuff
//
#ifdef __GNUC__

// Note that gcc >= 4.3 reports error when macro is redefined, so 
// we need to undefine already existing macros

#undef UNUSED_PARAM
#define UNUSED_PARAM __attribute__((unused))

#undef WARN_UNUSED_RESULT 
#define WARN_UNUSED_RESULT __attribute__((warn_unused_result))

#undef DEPRECATED
#define DEPRECATED __attribute__((deprecated))

#define USE_GCC_PRAGMAS

/* There is a bug in the version of gcc which ships with MacOS X 10.2 */
#if defined(__APPLE__) && defined(__MACH__)
#  include <AvailabilityMacros.h>
#endif
#ifdef MAC_OS_X_VERSION_MAX_ALLOWED
#  if MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_2
#    undef USE_GCC_PRAGMAS
#  endif
#endif

#ifdef USE_GCC_PRAGMAS
#pragma interface
#endif

#endif // GCC specific stuff

#if defined(_MSC_VER)
#	if _MSC_VER >= 2000
#		undef DEPRECATED
#		define DEPRECATED __declspec(deprecated) 
#	endif
#endif

#endif


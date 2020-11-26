/*<This file represents the -list function of the client.c >
Copyright (C) <2020>  <ckasou01>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Υou should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.*/

/**
 *
 * @file list.h
 *
 * @brief This file represents the -list function of the program.
 *
 * @author Christos Kasoulides
 * @version 1.0
 * @since 19/11/20
 *
 */
#ifndef EPL232_HW4_LIST_H
#define EPL232_HW4_LIST_H

#include "bmp.h"

/**
 * This function lists every element in the header of the image.
 *
 * @param i is an IMAGE representing the given image
 *
 * @return void
 */
void list(IMAGE *i);


#endif //EPL232_HW4_LIST_H

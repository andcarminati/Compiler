/*
 * Compiler
Copyright (C) 2019  Andreu Carminati
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*
 * error_report.h
 *
 *  Created on: 18/06/2009
 *      Author: andreu
 */

#ifndef ERROR_REPORT_H_
#define ERROR_REPORT_H_

void type_incompatibility(int line, int type_n1, int type_n2);
void iteration_type_incompatibility(int line, int type_n);

#endif /* ERROR_REPORT_H_ */

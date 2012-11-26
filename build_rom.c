/* 
 *    Copyright (C) 2012 Simon Sickle <simon@simonsickle.com>
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program.  If not, see 
 *    <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdint.h>
#include <string.h>
#include <sys/stat.h>

int build_rom(void) {
	system(". build/envsetup.sh");
	char device[50];
	printf("Target device: ");
	scanf("%s", device);
	printf("\nOkay, were building for %s\n", device);
	char lunch[50];
	sprintf(lunch, "lunch %s", device);
	system(lunch);
	printf("How many parallel builds: ");
	char amnt_cores[50];
	scanf("%s", amnt_cores);
	printf("\nYou have chosen -j%s\n", amnt_cores);
	char make_it[50];
	sprintf(make_it, "make -j%s bacon", amnt_cores);
	system(make_it);

	return 0;
}

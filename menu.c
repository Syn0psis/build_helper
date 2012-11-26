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

#include "menu.h"
#include "build_rom.h"

static int menu(void) {
char choice[20];
do {
	printf("Please make a choice: \n"
		"1) Build CyanogenMod \n"
		"2) Build Kernel \n"
		"3) Does Nothing \n"
		"4) Does Nothing \n"
		"5) Exit \n");
	scanf("%s", choice);
	if ((strcmp(choice, "1") == 0)) {
		build_rom();
	}
	else if ((strcmp(choice, "2") == 0)) {
		printf("Coming soon\n");
	}
	else if ((strcmp(choice, "3") == 0)) {}
	else if ((strcmp(choice, "4") == 0)) {}
	else if ((strcmp(choice, "5") == 0)) {}
	else {
		printf("Invalid Choice\n");
	};
} while ((strcmp(choice, "5") != 0));

return 0;
}

int main() {
menu();

return 0;
}

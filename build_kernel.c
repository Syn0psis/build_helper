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

int build_kernel(void) {
	char kernel_defconfig[20];
	//Okay, lets see what device to build for
	printf("What defconfig are you using: ");
	scanf("%s", kernel_defconfig);
	printf("\nOkay, were building with %s\n", kernel_defconfig);
	//now we are going to build
	printf("Starting the build\n");
	system("make mrproper");
	//make kernel defconfig
	char make_kernel_dc[20];
        sprintf(make_kernel_dc, "make %s", kernel_defconfig);
        system(make_kernel_dc);
	//make the actual kernel
	char toolchain_kernel[50];
	printf("Where is your toolchain: ");
	scanf("%s", toolchain_kernel);
	printf("\n");
	char make_kernel_comand[500];
	sprintf(make_kernel_comand, "make `cat /proc/stat | grep ^cpu[0-9] | wc -l` ARCH=arm CROSS_COMPILE=%s", toolchain_kernel);
	system(make_kernel_comand);

	return 0;
};

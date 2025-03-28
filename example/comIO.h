/*
	This file is part of AuriText-SDL2.

	AuriText-SDL2 is free software: you can redistribute it and/or modify
	it under the terms of the GNU Lesser General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	any later version.

	AuriText-SDL2 is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public License along with AuriText-SDL2.
	If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef __COMIO__
#define __COMIO__

#ifdef __cplusplus
extern "C" {
#endif

const char comIO_size[2] = { 8, 8 };

const char *comIO_fontSheet[] = {
	"760 8 2 1 ",
	"  c None",
	". c white",
	"......    ..     .. ..   .. ..    ..    ..  ..   ....      ..      ..    ..                                                 ..   ....     ..     ....    ....      ..   ......   ....   ......   ....    ....     ..      ..       ..           ..       ....    ....     ..    .....    ....   .....   ......  ......   ....   ..  ..    ..        ..  ..  ..  ..      ..   .. ..  ..   ....   .....    ....   .....    ....   ......  ..  ..  ..  ..  ..   .. ..  ..  ..  ..  ......   ....    ..      ....      .              ..            ..                  ..            ....          ..        ..        ..  ..        ..                                                              ..                                                       ..     ..     ..      .. ..  ",
	"..  ..    ..     .. ..  .......  ....   ..  ..  ..  ..     ..     ..      ..      ..      ..                                ..  ..  ..  ....    ..  ..  ..  ..    ...   ..      ..  ..      ..  ..  ..  ..  ..                    ..             ..     ..  ..  ..  ..   ....   ..  ..  ..  ..  ..  ..  ..      ..      ..  ..  ..  ..    ..        ..  .. ..   ..      ... ... ..  ..  ..  ..  ..  ..  ..  ..  ..  ..  ..  ..    ..    ..  ..  ..  ..  ..   .. ..  ..  ..  ..      ..   ..      ..        ..     ...             ..     ....   ..       ....       ..   ....    ..      .....  ..                      ..  ..    ..    .....   .....    ....   .....    ....   .. ...   ....     ..    ..  ..  ..  ..  ..   .. ..  ..  ..  ..  ......    ..      ..      ..    .. ..   ",
	"..  ..    ..     .. ..   .. ..  ......     ..   ..  ..    ..     ..        ..   ......    ..                               ..   .. ...    ..        ..      ..   ....   ..      ..          ..  ..  ..  ..  ..                   ..      ....     ..        ..  ..  ..  ..  ..  ..  ..  ..      ..  ..  ..      ..      ..      ..  ..    ..        ..  ....    ..      ... ... ... ..  ..  ..  ..  ..  ..  ..  ..  ..  ..        ..    ..  ..  ..  ..  ..   ..  ....   ..  ..     ..    ..       ..       ..    .. ..             ..   ..  ..  ..      ..  ..      ..  ..  ..   ..     ..  ..  .....     ..        ..  .. ..     ..    .. . .  ..  ..  ..  ..  ..  ..  ..  ..  ....    ..  ..  ......  ..  ..  ..  ..  ..   .. ..  ..  ..  ..      ..    ..      ..      ..            ",
	"..  ..    ..             .. ..  ....       ..    ....            ..        ..    ....   ......                             ..   .. ...    ..        ..      ..  .. ..    ....   ..         ..    ....   ..  ..                  ..                 ..      ..   .. ...  ..  ..  .....   ..      ..  ..  ..      ......  ..      ......    ..        ..  ...     ..      ....... ......  ..  ..  ..  ..  ..  ..  ..  ..   ....     ..    ..  ..  ..  ..  .. . ..   ..     ....     ..     ..       ..       ..                               ..  .....   ..       .....  ..  ..  ......  ..  ..  ..  ..    ..        ..  ....      ..    .. . .  ..  ..  ..  ..  ..  ..  ..  ..  ..      ..        ..    ..  ..  ..  ..  .. . ..  ....   ..  ..     ..    ..                ..           ",
	"..  ..    ..             .. ..    ....    ..    ..               ..        ..    ....   ......          ......            ..    ... ..    ..     ....     ...   .. ..       ..  .....      ..   ..  ..   .....                  ..                 ..     ..    .. ...  ..  ..  ..  ..  ..      ..  ..  ....    ..      .. ...  ..  ..    ..        ..  ...     ..      ....... ......  ..  ..  .....   ..  ..  .....       ..    ..    ..  ..  ..  ..  .. . ..   ..      ..     ..      ..        ..      ..                            .....  ..  ..  ..      ..  ..  ......   ..      .....  ..  ..    ..        ..  ...       ..    .. . .  ..  ..  ..  ..  ..  ..  ..  ..  ..       ....     ..    ..  ..  ..  ..  .. . ..   ..     ....     ..     ..                ..           ",
	"..  ..    ..             .. ..  ......    ..    ..  ..           ..        ..   ......    ..                              ..    ... ..    ..    ..          ..  ......      ..  ..  ..    ..    ..  ..      ..                   ..      ....     ..      ..    ..      ......  ..  ..  ..      ..  ..  ..      ..      ..  ..  ..  ..    ..        ..  ....    ..      .. . .. .. ...  ..  ..  ..      .. ...  ..  ..      ..    ..    ..  ..  ..  ..  .. . ..  ....     ..    ..       ..        ..      ..                           ..  ..  ..  ..  ..      ..  ..  ..       ..         ..  ..  ..    ..        ..  ....      ..    .. . .  ..  ..  ..  ..  .....   ..  ..  ..          ..    ..    ..  ..  ..  ..  .. . ..  ....     ..     ..       ..      ..      ..            ",
	"..  ..                  .......  ....    ..  .. .. ..             ..      ..      ..      ..      ..                     ..     ..  ..    ..    ..      ..  ..     ..   ..  ..  ..  ..    ..    ..  ..  ..  ..            ..      ..             ..             ..      ..  ..  ..  ..  ..  ..  ..  ..  ..      ..      ..  ..  ..  ..    ..    ..  ..  .. ..   ..      .. . .. ..  ..  ..  ..  ..      ..  ..  ..  ..  ..  ..    ..    ..  ..   ....   ....... ..  ..    ..    ..       ..         ..     ..                           ..  ..  ..  ..  ..  ..  ..  ..  ..       ..     ..  ..  ..  ..    ..    ..  ..  .. ..     ..    .. . .  ..  ..  ..  ..  ..       .....  ..      ..  ..    ..    ..  ..   ....   ....... ..  ..    ..    ..        ..      ..      ..            ",
	"......    ..             .. ..    ..     ..  ..  .. ..             ..    ..                      ..               ..     ..      ....   ......  ......   ....      ..    ....    ....     ..     ....    ....     ..     ..        ..           ..        ..     ....   ..  ..  .....    ....   .....   ......  ..       ....   ..  ..    ..     ....   ..  ..  ......  ..   .. ..  ..   ....   ..       ...... ..  ..   ....     ..     ....     ..     .. ..  ..  ..    ..    ......   ....       ..   ....           ......           .....  .....    ....    .....   .....   ..      ....   ..  ..    ..     ....   ..  ..     ..   .. . .  ..  ..   ....   ..          ..  ..       ....      ...   .....    ..     .. ..  ..  ..  ...     ......     ..     ..     ..             "
};

#ifdef __cplusplus
}
#endif

#endif
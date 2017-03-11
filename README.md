# mac-encheez - run a program with a modified view of network MAC addresses

Copyright 2008, 2017 Eric Smith <spacewar@gmail.com>

mac-encheez development is hosted at the
[mac-encheez Github repository](https://github.com/brouhaha/mac-encheez/).


## Introduction

mac-encheez provides a way to run a program such that it has a
modified view of the MAC addresses of the network interfaces of the
computer.


## Example Usage

* 'encheez 12:34:56:78:9a:bc someprogram arg1 arg2 arg3'

  Runs "someprogram arg1 arg2 arg3" with all network interfaces appearing
  to have the alternate MAC address "12:34:56:78:9a:bc".


## License

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License version 3 as
published by the Free Software Foundation.  Note that no permission is
granted to redistribute or modify this program under the terms of any
other version of the General Public License.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program (in the file "GPL-3.0.txt"); if not, see
<http://www.gnu.org/licenses/>.

// libfakemac, part of MAC-encheez
// Copyright 2008, 2017 Eric Smith <spacewar@gmail.com>

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 3 as
// published by the Free Software Foundation.  Note that no permission
// is granted to redistribute or modify this program under the terms
// of any other version of the General Public License.
// 
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program (in the file "GPL-3.0.txt"); if not,
// see <http://www.gnu.org/licenses/>.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <net/if.h>
#include <netinet/ether.h>

// We need to get the definition of SIOCGIFHWADDR, but NOT the prototype
// of the ioctl() system call, so we can't include sys/ioctl.h.
#include <linux/sockios.h>

#define __USE_GNU
#include <dlfcn.h>

typedef int (ioctl_fn_t)(int d, int request, char *argp);

static ioctl_fn_t *orig_ioctl_fn;

static struct ether_addr mac_addr;

static void __attribute__ ((constructor)) init (void)
{
  char *mac_addr_str;
  struct ether_addr *mac_addr_ptr;

  orig_ioctl_fn  = (ioctl_fn_t *)  dlsym (RTLD_NEXT, "ioctl");

  mac_addr_str = getenv ("MACADDR");
  if (! mac_addr_str)
    {
      fprintf (stderr, "no MACADDR environment variable\n");
      exit (2);
    }

  mac_addr_ptr = ether_aton (mac_addr_str);
  if (! mac_addr_ptr)
    {
      fprintf (stderr, "invalid MACADDR environment variable\n");
      exit (2);
    }

  memcpy (& mac_addr, mac_addr_ptr, sizeof (mac_addr));
}


int ioctl (int d, int request, void *argp)
{
  int r;
  struct ifreq *ifreq;

  r = orig_ioctl_fn (d, request, argp);
  if (r < 0)
    return r;

  if (request == SIOCGIFHWADDR)
    {
      ifreq = argp;
      //printf ("SIOCGIFHWADDR for interface '%s'\n", ifreq->ifr_name);
      memcpy (ifreq->ifr_hwaddr.sa_data, & mac_addr, sizeof (mac_addr));
    }

  return r;
}

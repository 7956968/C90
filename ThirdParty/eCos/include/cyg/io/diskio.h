#ifndef CYGONCE_DISKIO_H
#define CYGONCE_DISKIO_H
// ====================================================================
//
//      diskio.h
//
//      Device I/O
//
// ====================================================================
//####ECOSGPLCOPYRIGHTBEGIN####
// -------------------------------------------
// This file is part of eCos, the Embedded Configurable Operating System.
// Copyright (C) 2003 Savin Zlobec
// Copyright (C) 2004, 2006 eCosCentric Limited
//
// eCos is free software; you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published by the Free
// Software Foundation; either version 2 or (at your option) any later version.
//
// eCos is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
// for more details.
//
// You should have received a copy of the GNU General Public License along
// with eCos; if not, write to the Free Software Foundation, Inc.,
// 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.
//
// As a special exception, if other files instantiate templates or use macros
// or inline functions from this file, or you compile this file and link it
// with other works to produce a work based on this file, this file does not
// by itself cause the resulting work to be covered by the GNU General Public
// License. However the source code for this file must still be made available
// in accordance with section (3) of the GNU General Public License.
//
// This exception does not invalidate any other reasons why a work based on
// this file might be covered by the GNU General Public License.
//
// -------------------------------------------
//####ECOSGPLCOPYRIGHTEND####
// ====================================================================
//#####DESCRIPTIONBEGIN####
//
// Author(s):     savin
// Date:          2003-06-09
// Purpose:       Special support for disk I/O devices
// Description:
//
//####DESCRIPTIONEND####
//
// ====================================================================

// This file contains the user-level visible I/O interfaces

#include <pkgconf/hal.h>
#include <cyg/infra/cyg_type.h>
#include <cyg/io/config_keys.h>

#include <cyg/io/devtab.h>

#ifdef __cplusplus
extern "C" {
#endif

struct cyg_disk_identify_t
{
    char        serial[20+1];      // serial number
    char        firmware_rev[8+1]; // firmware revision
    char        model_num[40+1];   // model number
    cyg_uint32  cylinders_num;     // number of cylinders         (CHS)
    cyg_uint32  heads_num;         // number of heads             (CHS)
    cyg_uint32  sectors_num;       // number of sectors per track (CHS)
    cyg_uint32  lba_sectors_num;   // total number of sectors in LBA mode
    cyg_uint32  phys_block_size;   // physical block size in sectors
    cyg_uint32  max_transfer;      // Maximum transfer size in bytes
};

struct  cyg_disk_partition_t
{
    cyg_uint8  type;    // partition type
    cyg_uint8  state;   // state 0x00 - inactive, 0x80 - active
    cyg_uint32 start;   // first sector number
    cyg_uint32 end;     // last sector number
    cyg_uint32 size;    // size in sectors
};

struct  cyg_disk_info_t
{
    cyg_disk_identify_t         ident;              // identify data
    cyg_disk_partition_t        partitions[12];     // partitions
    cyg_disk_partition_t        extended_partition; // extended partition
    cyg_uint32                  partition_num;      // number of partition
    cyg_addrword_t              devs[13];           // device instances
    cyg_uint32                  block_size;         // logical block size
    cyg_uint32                  blocks_num;         // number of blocks on disk
    cyg_uint32                  phys_block_size;    // physical block size
    cyg_bool                    connected;          // true if device connected
    cyg_ucount16                mounts;             // total number of mounts for all partitions
    struct cyg_devtab_entry     devtab[12];         // Device table entries for partitions
    disk_channel                diskchan[12];       // Disk channels for partitions
    cyg_uint8                   percentage;         //
};

#ifdef __cplusplus
}
#endif

#endif  /* CYGONCE_DISKIO_H */
/* EOF diskio.h */
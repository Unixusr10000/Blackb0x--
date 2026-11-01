//
//  mach-o/nlist.h (Linux compat shim)
//  Blackb0x
//
//  Minimal, portable definitions of the classic 32-bit Mach-O structures
//  CBPatch.c needs to statically analyze a downloaded ARMv7 kernelcache
//  buffer. This is pure binary-format parsing of a stable, publicly
//  documented file format -- not a proprietary macOS runtime API -- so
//  these struct layouts are safe to redefine outside of Apple's
//  <mach-o/*.h>, which does not exist on Linux.
//
//  First-party shim, used only on Linux (see the CBPatcher block in
//  CMakeLists.txt): CBPatch.c's angle-bracket includes resolve here
//  instead of to a patched submodule. Contents recovered from this
//  project's own deleted portable_macho.h, which stood in for the same
//  headers in the pre-submodule in-tree copy of CBPatcher.
//

#ifndef BLACKB0X_COMPAT_MACH_O_NLIST_H
#define BLACKB0X_COMPAT_MACH_O_NLIST_H

#include <stdint.h>
#include <stddef.h> /* offsetof() -- CBPatch.c relies on this being pulled in
                     * transitively by the Apple headers this file replaces */

#define LC_SEGMENT 0x1
#define LC_SYMTAB  0x2

struct mach_header {
    uint32_t magic;
    int32_t cputype;
    int32_t cpusubtype;
    uint32_t filetype;
    uint32_t ncmds;
    uint32_t sizeofcmds;
    uint32_t flags;
};

struct load_command {
    uint32_t cmd;
    uint32_t cmdsize;
};

struct segment_command {
    uint32_t cmd;
    uint32_t cmdsize;
    char segname[16];
    uint32_t vmaddr;
    uint32_t vmsize;
    uint32_t fileoff;
    uint32_t filesize;
    int32_t maxprot;
    int32_t initprot;
    uint32_t nsects;
    uint32_t flags;
};

struct section {
    char sectname[16];
    char segname[16];
    uint32_t addr;
    uint32_t size;
    uint32_t offset;
    uint32_t align;
    uint32_t reloff;
    uint32_t nreloc;
    uint32_t flags;
    uint32_t reserved1;
    uint32_t reserved2;
};

struct symtab_command {
    uint32_t cmd;
    uint32_t cmdsize;
    uint32_t symoff;
    uint32_t nsyms;
    uint32_t stroff;
    uint32_t strsize;
};

struct nlist {
    union {
        uint32_t n_strx;
    } n_un;
    uint8_t n_type;
    uint8_t n_sect;
    int16_t n_desc;
    uint32_t n_value;
};

#endif /* BLACKB0X_COMPAT_MACH_O_NLIST_H */

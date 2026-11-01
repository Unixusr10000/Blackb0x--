//
//  mach-o/fat.h (Linux compat shim)
//  Blackb0x
//
//  CBPatch.c includes this header but uses nothing from it (verified by
//  grep: no fat_header/fat_arch/FAT_* symbols in the CBPatcher sources --
//  it only ever parses thin 32-bit kernelcaches). It exists so the
//  angle-bracket include resolves on Linux, where Apple's header does
//  not. See src/compat/mach-o/nlist.h for the shim that carries the
//  definitions CBPatch.c actually needs.
//

#ifndef BLACKB0X_COMPAT_MACH_O_FAT_H
#define BLACKB0X_COMPAT_MACH_O_FAT_H

#endif /* BLACKB0X_COMPAT_MACH_O_FAT_H */

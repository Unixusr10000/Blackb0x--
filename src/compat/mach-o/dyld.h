//
//  mach-o/dyld.h (Linux compat shim)
//  Blackb0x
//
//  CBPatch.c includes this header but uses nothing from it (verified by
//  grep: no _dyld_*/dyld symbols in the CBPatcher sources). It exists so
//  the angle-bracket include resolves on Linux, where Apple's header
//  does not. See src/compat/mach-o/nlist.h for the shim that carries the
//  definitions CBPatch.c actually needs.
//

#ifndef BLACKB0X_COMPAT_MACH_O_DYLD_H
#define BLACKB0X_COMPAT_MACH_O_DYLD_H

#endif /* BLACKB0X_COMPAT_MACH_O_DYLD_H */

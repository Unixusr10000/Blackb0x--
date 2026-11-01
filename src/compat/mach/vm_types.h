//
//  mach/vm_types.h (Linux compat shim)
//  Blackb0x
//
//  The one definition CBPatch.c takes from this header is vm_address_t.
//  See src/compat/mach-o/nlist.h for the rest of the Linux Mach-O compat
//  shims and why they exist.
//

#ifndef BLACKB0X_COMPAT_MACH_VM_TYPES_H
#define BLACKB0X_COMPAT_MACH_VM_TYPES_H

#include <stdint.h>

typedef uint32_t vm_address_t;

#endif /* BLACKB0X_COMPAT_MACH_VM_TYPES_H */

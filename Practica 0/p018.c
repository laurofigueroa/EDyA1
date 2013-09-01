#include <stdio.h>
#include <stdlib.h>

int main (void) {

	char *p=malloc(100);
	free(p);
	free(p);
	return 0;

}

*** glibc detected *** ./a.out: double free or corruption (top): 0x098b7008 ***
======= Backtrace: =========
/lib/i386-linux-gnu/libc.so.6(+0x75ee2)[0xde4ee2]
./a.out[0x8048445]
/lib/i386-linux-gnu/libc.so.6(__libc_start_main+0xf3)[0xd884d3]
./a.out[0x8048381]
======= Memory map: ========
0041a000-0043a000 r-xp 00000000 08:06 2098038    /lib/i386-linux-gnu/ld-2.15.so
0043a000-0043b000 r--p 0001f000 08:06 2098038    /lib/i386-linux-gnu/ld-2.15.so
0043b000-0043c000 rw-p 00020000 08:06 2098038    /lib/i386-linux-gnu/ld-2.15.so
0098c000-009a8000 r-xp 00000000 08:06 2098050    /lib/i386-linux-gnu/libgcc_s.so.1
009a8000-009a9000 r--p 0001b000 08:06 2098050    /lib/i386-linux-gnu/libgcc_s.so.1
009a9000-009aa000 rw-p 0001c000 08:06 2098050    /lib/i386-linux-gnu/libgcc_s.so.1
00b3f000-00b40000 r-xp 00000000 00:00 0          [vdso]
00d6f000-00f12000 r-xp 00000000 08:06 2098009    /lib/i386-linux-gnu/libc-2.15.so
00f12000-00f13000 ---p 001a3000 08:06 2098009    /lib/i386-linux-gnu/libc-2.15.so
00f13000-00f15000 r--p 001a3000 08:06 2098009    /lib/i386-linux-gnu/libc-2.15.so
00f15000-00f16000 rw-p 001a5000 08:06 2098009    /lib/i386-linux-gnu/libc-2.15.so
00f16000-00f19000 rw-p 00000000 00:00 0 
08048000-08049000 r-xp 00000000 08:06 2888647    /home/pepe02/a.out
08049000-0804a000 r--p 00000000 08:06 2888647    /home/pepe02/a.out
0804a000-0804b000 rw-p 00001000 08:06 2888647    /home/pepe02/a.out
098b7000-098d8000 rw-p 00000000 00:00 0          [heap]
b77bd000-b77be000 rw-p 00000000 00:00 0 
b77ce000-b77d1000 rw-p 00000000 00:00 0 
bfd6c000-bfd8d000 rw-p 00000000 00:00 0          [stack]
Abortado (`core' generado)

/* 
   Configuration for compiling Racket

   If you want to set all the flags externally (on the command line
   with -D or some other compiler-dependent way), then define
   FLAGS_ALREADY_SET, and this file will be ignored.

   The best flag settings are already provided for some auto-detected
   architecture/system/compilers. Otherwise, the default settings 
   are generic Unix.  Send other architecture/system/compiler-specific 
   info to "racket@racket-lang.org".
*/

#ifndef FLAGS_ALREADY_SET

/******** (BEGIN KNOWN ARCHITECTURE/SYSTEM CONFIGURATIONS) ********/

/* First, use configure-generated information */
/*   (on Windows, this is done by a manual file which is in src/worksp) */
#include "mzconfig.h"

  /*************** OSKit with Linux/gcc *****************/

#if defined(OSKIT)

# define SYSTEM_TYPE_NAME "oskit"

# define DO_STACK_CHECK
# ifndef OSKIT_TEST
#  define OSKIT_FIXED_STACK_BOUNDS
# else
#  define ASSUME_FIXED_STACK_SIZE
#  define FIXED_STACK_SIZE 65500
# endif
# define STACK_SAFETY_MARGIN 10000

# define UNIX_FILE_SYSTEM
# define NO_UNIX_USERS

# define TIME_SYNTAX
# define DIR_FUNCTION
# define DIRENT_NO_NAMLEN
# define GETENV_FUNCTION

# ifndef OSKIT_TEST
#  define HAS_FREEBSD_IOB
# else
#  define HAS_LINUX_IOB
# endif
# define USE_OSKIT_CONSOLE
# define FILES_HAVE_FDS
# define USE_FD_PORTS
# define FIXED_FD_LIMIT 256
# define USE_UNIX_SOCKETS_TCP
# define USE_FCNTL_O_NONBLOCK

# ifndef OSKIT_TEST
#  define INCLUDE_OSKIT_SOCKET
#  define MZ_PF_INET OSKIT_PF_INET
#  define PROTOENT_IS_INT IPPROTO_TCP
# endif

# define NO_USLEEP
# define NO_SLEEP
# define USER_TIME_IS_CLOCK

# define SIGSET_IS_SIGNAL

# define UNISTD_INCLUDE

# define USE_TM_GMTOFF_FIELD
# define USE_TM_ZONE_FIELD

# define FLAGS_ALREADY_SET

#else  /* >>>>>>> close after all platforms <<<<<<<<<< */

  /************** SunOS/Solaris with gcc ****************/

#if defined(sun)

# include "uconfig.h"

# define USE_EXPLICT_FP_FORM_CHECK
# define POW_HANDLES_INF_CORRECTLY

# include <errno.h>
# ifdef ECHRNG
/* Solaris */
#  if  defined(i386)
#   define SCHEME_PLATFORM_LIBRARY_SUBPATH "i386-solaris"
#  elif defined(__x86_64)
#   define SCHEME_PLATFORM_LIBRARY_SUBPATH "x86_64-solaris"
#  else
#   define SCHEME_PLATFORM_LIBRARY_SUBPATH "sparc-solaris"
#  endif
#  define DIRENT_NO_NAMLEN
#  define NO_USLEEP
#  define USE_ULIMIT
#  define USE_FCNTL_O_NONBLOCK
#  define SOME_FDS_ARE_NOT_SELECTABLE
#  define NEED_RESET_STDOUT_BLOCKING
#  undef USE_FLOCK_FOR_FILE_LOCKS
#  define USE_FCNTL_AND_FORK_FOR_FILE_LOCKS
#  define USE_TIMEZONE_AND_ALTZONE_VAR
#  define USE_TZNAME_VAR
#  define USE_NULL_TO_DISCONNECT_UDP
# else
/* SunOS4 */
# define SCHEME_PLATFORM_LIBRARY_SUBPATH "sparc-sunos4"
# define SIGSET_IS_SIGNAL
# define USE_TM_GMTOFF_FIELD
# define USE_TM_ZONE_FIELD
# define NO_STRERROR_AVAILABLE
# define USE_ON_EXIT_FOR_ATEXIT
# endif

# define FMOD_CAN_RETURN_POS_ZERO

# ifdef i386
#  define MZ_USE_JIT_I386
#  define MZ_JIT_USE_MPROTECT
# elif defined(__x86_64)
#  define MZ_USE_JIT_X86_64
#  define MZ_JIT_USE_MPROTECT
# else
#  define FLUSH_SPARC_REGISTER_WINDOWS
# endif

# define FLAGS_ALREADY_SET

#endif

  /************** RS6000/AIX with gcc or xlc ****************/

# if defined(_IBMR2)

# define SCHEME_PLATFORM_LIBRARY_SUBPATH "rs6k-aix"

# include "uconfig.h"
# undef USE_FCHDIR

# define UNIX_LIMIT_STACK 33554944

# define SELECT_INCLUDE

# define POW_HANDLES_INF_CORRECTLY

# define USE_FCNTL_O_NONBLOCK

# define USE_TIMEZONE_VAR_W_DLS
# define USE_TZNAME_VAR

# define FLAGS_ALREADY_SET

#endif

  /************** Linux with gcc ****************/

#if defined(linux)

# if defined(i386)
#  define SCHEME_PLATFORM_LIBRARY_SUBPATH "i386-linux"
#  define REGISTER_POOR_MACHINE
#  ifndef MZ_USE_JIT_SSE
#   define ASM_DBLPREC_CONTROL_87
#  endif
# endif
# if defined(powerpc)
#  define SCHEME_PLATFORM_LIBRARY_SUBPATH "ppc-linux"
# endif
# if defined(__mc68000__)
#  define SCHEME_PLATFORM_LIBRARY_SUBPATH "m68k-linux"
# endif
# if defined(mips)
#  define SCHEME_PLATFORM_LIBRARY_SUBPATH "mips-linux"
# endif
# if defined(__alpha__)
#  define SCHEME_PLATFORM_LIBRARY_SUBPATH "alpha-linux"
# endif
# if defined(__hppa__)
#  define SCHEME_PLATFORM_LIBRARY_SUBPATH "hppa-linux"
# endif
# if defined(__sparc__)
#  define SCHEME_PLATFORM_LIBRARY_SUBPATH "sparc-linux"
#  define FLUSH_SPARC_REGISTER_WINDOWS
# endif
# if defined(__x86_64__)
#  define SCHEME_PLATFORM_LIBRARY_SUBPATH "x86_64-linux"
#  define REGISTER_POOR_MACHINE
#  ifdef MZ_NO_JIT_SSE
#   define ASM_DBLPREC_CONTROL_87
#  endif
# endif
# ifndef SCHEME_PLATFORM_LIBRARY_SUBPATH
#  define SCHEME_PLATFORM_LIBRARY_SUBPATH "unknown-linux"
# endif

# include "uconfig.h"
# undef HAS_STANDARD_IOB
# ifndef __ELF__
#  undef UNIX_DYNAMIC_LOAD
# endif

# define DIRENT_NO_NAMLEN

# define HAS_LINUX_IOB

# define USE_IEEE_FP_PREDS
# define USE_EXPLICT_FP_FORM_CHECK

# define SIGSET_IS_SIGNAL
# define SIGSET_NEEDS_REINSTALL

# define LINUX_FIND_STACK_BASE
# define USE_DYNAMIC_FDSET_SIZE

# define USE_TIMEZONE_VAR_W_DLS
# define USE_TZNAME_VAR

# define MZ_TCP_LISTEN_IPV6_ONLY_SOCKOPT

# define FLAGS_ALREADY_SET

#if defined(i386)
# define MZ_USE_JIT_I386
# define MZ_JIT_USE_MPROTECT
#endif
#if defined(__x86_64__)
# define MZ_USE_JIT_X86_64
# define MZ_JIT_USE_MPROTECT
# define MZ_USE_DWARF_LIBUNWIND
#endif
#if defined(powerpc)
# define MZ_USE_JIT_PPC
#endif

#endif

  /********************* NetBSD ***********************/

#if defined(__NetBSD__)

#if defined(i386)
# define SCHEME_PLATFORM_LIBRARY_SUBPATH "i386-netbsd"
#elif defined(powerpc)
# define SCHEME_PLATFORM_LIBRARY_SUBPATH "ppc-netbsd"
#elif defined(__x86_64__)
# define SCHEME_PLATFORM_LIBRARY_SUBPATH "x86_64-netbsd"
#else
# define SCHEME_PLATFORM_LIBRARY_SUBPATH "netbsd"
#endif

# include "uconfig.h"

# undef HAS_STANDARD_IOB
# define HAS_BSD_IOB

#ifndef __ELF__
# define UNDERSCORE_DYNLOAD_SYMBOL_PREFIX
#endif

# define USE_IEEE_FP_PREDS
# define POW_HANDLES_INF_CORRECTLY

# define USE_DYNAMIC_FDSET_SIZE

# define SIGSET_IS_SIGNAL

# define USE_TM_GMTOFF_FIELD
# define USE_TM_ZONE_FIELD

#if defined(__alpha__)
# define USE_DIVIDE_MAKE_INFINITY
#endif

#if defined(i386)
# define MZ_USE_JIT_I386
# define MZ_JIT_USE_MPROTECT
#endif
#if defined(powerpc)
# define MZ_USE_JIT_PPC
#endif
#if defined(__x86_64__)
# define MZ_USE_JIT_X86_64
# define MZ_JIT_USE_MPROTECT
#endif

# define FLAGS_ALREADY_SET

#endif

  /************** x86/OpenBSD with gcc ****************/
              /* Thanks to Bengt Kleberg */

#if defined(__OpenBSD__) && (defined(__i386__) || defined(i386) || defined(__x86_64__))

# if defined(__x86_64__)
#  define SCHEME_PLATFORM_LIBRARY_SUBPATH "x86_64-openbsd"
# else
#  define SCHEME_PLATFORM_LIBRARY_SUBPATH "i386-openbsd"
# endif

# include "uconfig.h"
# undef HAS_STANDARD_IOB

# define HAS_BSD_IOB

#ifndef __ELF__
# define UNDERSCORE_DYNLOAD_SYMBOL_PREFIX
#endif

# define USE_IEEE_FP_PREDS
# define POW_HANDLES_INF_CORRECTLY

# define USE_DYNAMIC_FDSET_SIZE

# define SIGSET_IS_SIGNAL

# define REGISTER_POOR_MACHINE

# define USE_TM_GMTOFF_FIELD
# define USE_TM_ZONE_FIELD

#if defined(__x86_64__)
# define MZ_USE_JIT_X86_64
# define MZ_JIT_USE_MPROTECT
#else
# define MZ_USE_JIT_I386
# define MZ_JIT_USE_MPROTECT
#endif

# define FLAGS_ALREADY_SET

#endif

  /************** x86/FreeBSD with gcc ****************/

#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
 
# if defined(__i386__)
#  define SCHEME_PLATFORM_LIBRARY_SUBPATH "i386-freebsd"
#  define REGISTER_POOR_MACHINE
#  define MZ_USE_JIT_I386
#  ifndef MZ_JIT_X86_SSE
#    if defined(__FreeBSD_kernel__)
#     define ASM_DBLPREC_CONTROL_87
#    else
#     define FREEBSD_CONTROL_387
#    endif
#  endif
# elif defined(__amd64__)
#  define SCHEME_PLATFORM_LIBRARY_SUBPATH "amd64-freebsd"
#  define REGISTER_POOR_MACHINE
#  define MZ_USE_JIT_X86_64
#  ifdef MZ_NO_JIT_SSE
#    if defined(__FreeBSD_kernel__)
#     define ASM_DBLPREC_CONTROL_87
#    endif
#  endif
# elif defined(__sparc64__)
#  define SCHEME_PLATFORM_LIBRARY_SUBPATH "sparc64-freebsd"
#  define FLUSH_SPARC_REGISTER_WINDOWS
# else
#  error Unported platform.
# endif

/* pthreads always enabled via configure', and
   initial pthread's stack size doesn't use rlimit: */
# define ASSUME_FIXED_STACK_SIZE
# define FIXED_STACK_SIZE 1048576

# include "uconfig.h"
# undef HAS_STANDARD_IOB

# define HAS_BSD_IOB

# ifdef FREEBSD_VERSION_2x
#  define UNDERSCORE_DYNLOAD_SYMBOL_PREFIX
# endif

# define USE_UNDERSCORE_SETJMP

# define USE_IEEE_FP_PREDS
# ifndef ASM_DBLPREC_CONTROL_87
#  define POW_HANDLES_INF_CORRECTLY
# endif

# define USE_DYNAMIC_FDSET_SIZE

# define SIGSET_IS_SIGNAL

# define USE_TM_GMTOFF_FIELD
# define USE_TM_ZONE_FIELD

# define MZ_JIT_USE_MPROTECT

# define FLAGS_ALREADY_SET

#endif

  /************** SGI/IRIX with SGI cc ****************/

#if  (defined(mips) || defined(__mips)) \
     && !(defined(ultrix) || defined(__ultrix) || defined(linux))

# define SCHEME_PLATFORM_LIBRARY_SUBPATH "mips-irix"

# include "uconfig.h"

# define DIRENT_NO_NAMLEN

# define BSTRING_INCLUDE

# define DEFEAT_FP_COMP_OPTIMIZATION
# define FMOD_CAN_RETURN_NEG_ZERO

# define NO_USLEEP
# define USE_FCNTL_O_NONBLOCK

# define USE_TIMEZONE_AND_ALTZONE_VAR
# define USE_TZNAME_VAR

# define FLAGS_ALREADY_SET

#endif

  /************** Ultrix with gcc ****************/

#if defined(ultrix) || defined(__ultrix)

# define SCHEME_PLATFORM_LIBRARY_SUBPATH "mips-ultrix"

# include "uconfig.h"
# undef UNIX_DYNAMIC_LOAD
# undef USE_FCHDIR

# define DIRENT_NO_NAMLEN

# define NO_USLEEP
# define USE_FCNTL_O_NONBLOCK

# define FLAGS_ALREADY_SET

#endif

  /************** ALPHA/OSF1 with gcc ****************/

# if (defined(__alpha) || defined(__alpha__)) && !defined(linux) && !defined(__NetBSD__)

# define SCHEME_PLATFORM_LIBRARY_SUBPATH "alpha-osf1"

# include "uconfig.h"

# define ALPHA_CONTROL_FP
# define USE_OSF_FP_PREDS
# define USE_DIVIDE_MAKE_INFINITY
# define ATAN2_DOESNT_WORK_WITH_INFINITIES

# define FLAGS_ALREADY_SET

#endif

  /************** HP/UX with cc or gcc ****************/

#if defined(__hpux)

# define SCHEME_PLATFORM_LIBRARY_SUBPATH "parisc-hpux"

# include "uconfig.h"

# define SOME_FDS_ARE_NOT_SELECTABLE
# define USE_FCNTL_O_NONBLOCK

# define USE_SYSCALL_GETRUSAGE

# define USE_DIVIDE_MAKE_INFINITY
# define USE_IEEE_FP_PREDS
# define USE_EXPLICT_FP_FORM_CHECK
# define ZERO_MINUS_ZERO_IS_POS_ZERO
# define LOG_ZERO_ISNT_NEG_INF

# define USE_ULIMIT

# define USE_TIMEZONE_VAR_W_DLS
# define USE_TZNAME_VAR

# define FLAGS_ALREADY_SET

#endif

  /************** x86/SCO Unix with gcc ****************/
  /* Contributed by Atanas Ivanov <nasko@noac.bg>      */

#if defined(_M_XENIX) && defined(_M_SYSV)

# define SCHEME_PLATFORM_LIBRARY_SUBPATH "sco-i386"

# include "uconfig.h"
# undef HAS_STANDARD_IOB
#ifndef __ELF__
# undef UNIX_DYNAMIC_LOAD
#endif

# define DIRENT_NO_NAMLEN

# define HAS_SCO_IOB

# define USE_SCO_IEEE_FP_PREDS
# define USE_EXPLICT_FP_FORM_CHECK
# define USE_FCNTL_O_NONBLOCK

# define REGISTER_POOR_MACHINE

# define FLAGS_ALREADY_SET

#endif

  /****************** Windows with MS Visual C ***************/
  /* See the "worksp" directory for more MSVC details.       */

#if (defined(__BORLANDC__) \
     || (defined(_MSC_VER) \
         && (defined(__WIN32__) || defined(WIN32) || defined(_WIN32))))

# ifdef _WIN64
#  define SCHEME_PLATFORM_LIBRARY_SUBPATH "win32\\x86_64"
# else
#  define SCHEME_PLATFORM_LIBRARY_SUBPATH "win32\\i386"
# endif

# define SYSTEM_TYPE_NAME "windows"
# define DOS_FILE_SYSTEM
# if defined(_MSC_VER)
#  define NO_READDIR
#  define USE_FINDFIRST
#  define NO_READLINK
#  define MKDIR_NO_MODE_FLAG
# endif
# if defined(__BORLANDC__)
#  define DIRENT_NO_NAMLEN
#  define NO_READLINK
#  define MKDIR_NO_MODE_FLAG
# endif

# define TIME_SYNTAX
# define USE_FTIME
# define USE_TIMEZONE_VAR_W_DLS
# define USE_TZNAME_VAR
# define WINDOWS_GET_PROCESS_TIMES
# define GETENV_FUNCTION
# define DIR_FUNCTION

# define USE_WINDOWS_EVENT_LOG
# define INIT_SYSLOG_LEVEL SCHEME_LOG_ERROR

# define DO_STACK_CHECK
# define WINDOWS_FIND_STACK_BOUNDS
/* Default stack size is 1MB, but we try to read
   the actual size from the executable on startup: */
# define WINDOWS_DEFAULT_STACK_SIZE 1048576
# ifdef _WIN64
#  define STACK_SAFETY_MARGIN 100000
# endif

# ifndef _WIN64
#  define USE_MZ_SETJMP
# endif

# define WINDOWS_DYNAMIC_LOAD

#ifdef _MSC_VER
# define USE_MSVC_FP_PREDS
# if _MSC_VER < 1300
#  define NAN_EQUALS_ANYTHING
# endif
# define INT64_AS_LONG_LONG
# define ATAN2_DOESNT_WORK_WITH_INFINITIES
         /* With VC 7, ATAN2_DOESNT... wasn't needed, and
            POW_HANDLES_INF_CORRECTLY worked, too. */
# define SIN_COS_NEED_DEOPTIMIZE
#endif
#ifdef __BORLANDC__
# define NAN_EQUALS_ANYTHING
# define ATAN2_DOESNT_WORK_WITH_INFINITIES
# define ATAN2_DOESNT_WORK_WITH_NAN
# define SQRT_NAN_IS_WRONG
# define LOG_ZERO_ISNT_NEG_INF
# define TRIG_ZERO_NEEDS_SIGN_CHECK
# define NEED_TO_DEFINE_MATHERR
#endif

# define IO_INCLUDE
# define DONT_IGNORE_PIPE_SIGNAL

# define PROCESS_FUNCTION
# define NO_SLEEP
# define WINDOWS_PROCESSES
# define WINDOWS_FILE_HANDLES
# ifndef MZ_USE_DETERMINSTIC_FUEL
#  define USE_WIN32_THREAD_TIMER
# endif

# define SIGSET_IS_SIGNAL
# define SIGSET_NEEDS_REINSTALL

#define USE_WINSOCK_TCP

#define PRINTF_INTPTR_SIZE_PREFIX "I"

/* MS Visual C++ likes underscore prefixes */
#if defined(_MSC_VER)
# define MSC_IZE(x) _ ## x
# define DIRECT_INCLUDE
#endif

#ifdef __BORLANDC__
# define MSCBOR_IZE(x) _ ## x
# define DIR_INCLUDE
# define IGNORE_BY_BORLAND_CONTROL_87
#endif

#if defined(_MSC_VER)
# define IGNORE_BY_MS_CONTROL_87
#endif

# define REGISTER_POOR_MACHINE

# define WINDOWS_UNICODE_SUPPORT
# define USE_ICONV_DLL
# define NO_MBTOWC_FUNCTIONS

# ifdef _WIN64
#  define MZ_USE_JIT_X86_64
# else
#  define MZ_USE_JIT_I386
# endif
# define MZ_JIT_USE_WINDOWS_VIRTUAL_ALLOC

# define FLAGS_ALREADY_SET

#endif

  /******************** Windows with Cygwin ******************/
  /* See the "worksp" directory for more MSVC details.       */

#if defined(__CYGWIN32__)

# define SCHEME_PLATFORM_LIBRARY_SUBPATH "i386-cygwin"

# include "uconfig.h"

# undef USE_ITIMER

# undef HAS_STANDARD_IOB
# define HAS_CYGWIN_IOB
# define MZ_BINARY O_BINARY

# define DIRENT_NO_NAMLEN
# define UNISTD_INCLUDE

# define SIGCHILD_DOESNT_INTERRUPT_SELECT
# define SIGSET_IS_SIGNAL
# define SIGSET_NEEDS_REINSTALL

# define CANT_SET_SOCKET_BUFSIZE
# define NO_NEED_FOR_BEGINTHREAD
# define USE_CREATE_PIPE

# define USE_MZ_CYGWIN_SETJMP
# define USE_MZ_SETJMP

# define USE_CYGWIN_SO_SUFFIX

# define USE_PLAIN_TIME
# define USE_TOD_FOR_TIMEZONE

# define USE_DIVIDE_MAKE_INFINITY

# define DO_STACK_CHECK
# define WINDOWS_FIND_STACK_BOUNDS

# define REGISTER_POOR_MACHINE

# ifndef AS_MSVC_EXTENSION
#  define LINK_EXTENSIONS_BY_TABLE
# endif

# define MZ_USE_JIT_I386

# define FLAGS_ALREADY_SET

#endif

  /************** Mac OS X  ****************/

# if defined(OS_X) || defined(XONX)

#ifdef XONX 
# ifdef __POWERPC__
#  define SCHEME_PLATFORM_LIBRARY_SUBPATH "ppc-darwin"
# else
#  ifdef __x86_64__
#   define SCHEME_PLATFORM_LIBRARY_SUBPATH "x86_64-darwin"
#  else
#   define SCHEME_PLATFORM_LIBRARY_SUBPATH "i386-darwin"
#  endif
# endif
#else
# ifdef __POWERPC__
#  define SCHEME_PLATFORM_LIBRARY_SUBPATH "ppc-macosx"
# else
#  ifdef __x86_64__
#   define SCHEME_PLATFORM_LIBRARY_SUBPATH "x86_64-macosx"
#  else
#   define SCHEME_PLATFORM_LIBRARY_SUBPATH "i386-macosx"
#  endif
# endif
#endif

# include "uconfig.h"

# define INIT_SYSLOG_LEVEL SCHEME_LOG_ERROR

# undef HAS_STANDARD_IOB
# define HAS_BSD_IOB

#ifndef XONX
# undef SYSTEM_TYPE_NAME
# define SYSTEM_TYPE_NAME "macosx"
#endif

# ifndef MZ_USE_DETERMINSTIC_FUEL
#  undef USE_ITIMER
#  define USE_PTHREAD_THREAD_TIMER
# endif

# define USE_MAP_ANON

# define USE_CARBON_FP_PREDS
# define TRIG_ZERO_NEEDS_SIGN_CHECK

# define USE_DYNAMIC_FDSET_SIZE

# define SIGSET_IS_SIGNAL

# define USE_TM_GMTOFF_FIELD
# define USE_TM_ZONE_FIELD

# define USE_UNDERSCORE_SETJMP

# define UDP_DISCONNECT_EADRNOTAVAIL_OK

#ifndef XONX
# define MACOS_UNICODE_SUPPORT
#endif

#ifndef OS_X
#  define OS_X 1
#endif

#if defined(__POWERPC__)
# define MZ_USE_JIT_PPC
#elif defined(__x86_64__)
# define MZ_USE_JIT_X86_64
#else
# define MZ_USE_JIT_I386
# ifndef MZ_NO_JIT_SSE
#  define MZ_USE_JIT_SSE
# endif
#endif

#ifdef MZ_NO_JIT_SSE
# define ASM_DBLPREC_CONTROL_87
#endif

# define MZ_JIT_USE_MPROTECT

# define FLAGS_ALREADY_SET

#endif

  /************** Darwin x86  ****************/

# if defined(__APPLE__) && defined(__MACH__) && defined(__i386__) && !defined(OS_X)

# define SCHEME_PLATFORM_LIBRARY_SUBPATH "i386-darwin"

# include "uconfig.h"

# define USE_MAP_ANON

# define USE_DYNAMIC_FDSET_SIZE

# define SIGSET_IS_SIGNAL

# define USE_TM_GMTOFF_FIELD
# define USE_TM_ZONE_FIELD

# define USE_UNDERSCORE_SETJMP

# define UDP_DISCONNECT_EADRNOTAVAIL_OK

# define MZ_USE_JIT_I386

# define FLAGS_ALREADY_SET

# endif

  /************ Macintosh with CodeWarrior (not OS X) *************/

#if ((defined(__MWERKS__) && !defined(__BEOS__) && !defined(__palmos__) && !defined(OS_X))  \
     || defined(MPW_C) || defined(MPW_CPLUS))

# if defined(__POWERPC__)
#  define SCHEME_PLATFORM_LIBRARY_SUBPATH "ppc-mac"
# else
#  define SCHEME_PLATFORM_LIBRARY_SUBPATH "68k-mac"
# endif

# define SYSTEM_TYPE_NAME "macos"
# define MAC_FILE_SYSTEM

# define NO_READDIR
# define NO_READLINK
# define USE_MAC_FILE_TOOLBOX

# define MACINTOSH_EVENTS
# define MAC_MZ_GUI_ENABLED
# define MAC_CLASSIC_PROCESS_CONTROL
//# define NEVER_EVER_SLEEP
# define MACINTOSH_GIVE_TIME
# define MACINTOSH_SIOUX

# if !defined(__POWERPC__)
#  define MACINTOSH_SET_STACK
#  define COMPUTE_NEG_INEXACT_TO_EXACT_AS_POS
#  define NAN_LT_COMPARISON_WRONG
#  define SQRT_NAN_IS_WRONG
#  define ATAN2_DOESNT_WORK_WITH_INFINITIES
# else
#  define CODEFRAGMENT_DYNAMIC_LOAD
# endif

# ifndef MZSCHEME_IS_CODEFRAGMENT
#  define LINK_EXTENSIONS_BY_TABLE
# endif

# define DO_STACK_CHECK
# define MACOS_FIND_STACK_BOUNDS
# define STACK_SAFETY_MARGIN 10000

# define TIME_SYNTAX
# define USE_MACTIME
# define DIR_FUNCTION
# define TIME_TYPE_IS_UNSIGNED

# define NO_SYS_INCLUDE_SUBDIR
# define NO_SLEEP
# define NO_USLEEP
# define NO_STAT_PROC
# define DONT_IGNORE_PIPE_SIGNAL

# define POW_HANDLES_INF_CORRECTLY
# define TRIG_ZERO_NEEDS_SIGN_CHECK

# define MACOS_UNICODE_SUPPORT

# define USE_MAC_TCP

# define SIGSET_IS_SIGNAL

# ifdef MPW_C
#  define NO_INLINE_KEYWORD
# endif

# define FLAGS_ALREADY_SET

#endif

  /************** DOS with Borland C++ ****************/
  /*          (Never successfully supported)          */

#if defined(__BORLANDC__) && defined(__MSDOS__)

# define SCHEME_PLATFORM_LIBRARY_SUBPATH "dos\\i386"

# define USE_SENORA_GC
# define DOS_FAR_POINTERS
# define SMALL_HASH_TABLES

# define SYSTEM_TYPE_NAME "dos"
# define DOS_FILE_SYSTEM
# define USE_GETDISK
# define DIRENT_NO_NAMLEN
# define NO_READLINK
# define MKDIR_NO_MODE_FLAG

# define TIME_SYNTAX
# define USE_FTIME
# define GETENV_FUNCTION
# define DIR_FUNCTION

# define DO_STACK_CHECK
# define USE_STACKAVAIL
# define STACK_SAFETY_MARGIN 15000

# define IGNORE_BY_CONTROL_87

# define DIR_INCLUDE
# define IO_INCLUDE
# define NO_SLEEP
# define DONT_IGNORE_PIPE_SIGNAL

# define REGISTER_POOR_MACHINE

# define FLAGS_ALREADY_SET

#endif

  /************ PalmOS *************/

#if defined(__palmos__)

# define SCHEME_PLATFORM_LIBRARY_SUBPATH "68k-palm"

# define SYSTEM_TYPE_NAME "palm"

# define NO_FILE_SYSTEM_UTILS
# define NO_TCP_SUPPORT
# define MZSCHEME_SOMETHING_OMITTED

# define PALMOS_STUFF
# define NO_STAT_PROC
# define NO_USER_BREAK_HANDLER
# define NO_USLEEP

# define DO_STACK_CHECK
# define PALM_FIND_STACK_BOUNDS
# define STACK_SAFETY_MARGIN 1000

# define TIME_SYNTAX
# define USE_PALMTIME
# define USER_TIME_IS_CLOCK
# define TIME_TYPE_IS_UNSIGNED

# define DONT_IGNORE_PIPE_SIGNAL
# define DONT_IGNORE_FPE_SIGNAL

# define POW_HANDLES_INF_CORRECTLY
# define USE_PALM_INF_TESTS

# define FLAGS_ALREADY_SET

#endif

  /************ QNX *************/

#if defined(__QNX__)

#if defined(i386)
# define SCHEME_PLATFORM_LIBRARY_SUBPATH "i386-qnx"
#endif
# define ASSUME_FIXED_STACK_SIZE

# include "uconfig.h"
# define SIGSET_IS_SIGNAL
# define SIGSET_NEEDS_REINSTALL

# define USE_FCNTL_O_NONBLOCK

# define FIXED_STACK_SIZE 524288

# define FLAGS_ALREADY_SET

#if defined(i386)
# define MZ_USE_JIT_I386
# define MZ_JIT_USE_MPROTECT
#endif
#if defined(__x86_64__)
# define MZ_USE_JIT_X86_64
# define MZ_JIT_USE_MPROTECT
# define MZ_USE_DWARF_LIBUNWIND
#endif

#endif

  /***************************************************/

#endif /* end not OSKit */

/************** (END KNOWN ARCHITECTURE/SYSTEMS) ****************/


/***** (BEGIN CONFIGURATION FLAG DESCRPTIONS AND DEFAULTS) ******/

#ifndef FLAGS_ALREADY_SET

/* assume generic Unix: */
#include "uconfig.h"
# define SIGSET_IS_SIGNAL
# define SIGSET_NEEDS_REINSTALL

  /*********************/
 /* Operating System  */
/*********************/

  /* SYSTEM_TYPE_NAME must be a string; this will be converted into
     a symbol for the result of (system-type) */

  /* SCHEME_PLATFORM_LIBRARY_SUBPATH must be a string; if it is 
     undefined, it is automatically generated into a file named
     "schsys.h" into the same directory as .o files and #included
     by string.c. This string is returned by (system-library-subpath) */

  /*********************/
 /* Language Features */
/*********************/

 /* TIME_SYNTAX adds the (time ...) syntax; this may need to be
     turned off for compilation on some systems.
    CLOCKS_PER_SEC relates the values returned by clock() to
     real seconds. (The difference between two clock() calls is
     divided by this number.) Usually, this is defined in <time.h>;
     it defaults to 1000000 */

 /* USE_FTIME uses ftime instead of gettimeofday; only for TIME_SYNTAX */
 
 /* USE_PLAIN_TIME uses time; only for TIME_SYNTAX */
 
 /* USE_MACTIME uses the Mac toolbox to implement time functions. */

 /* CLOCK_IS_USER_TIME uses the system time for user milliseconds. */

 /* USER_TIME_IS_CLOCK uses the user time for system milliseconds. */

 /* TIME_TYPE_IS_UNSIGNED converts time_t values as unsigned. */

 /* MIN_VALID_DATE_SECONDS sets a minimum vald time in seconds. */

 /* PROCESS_FUNCTION adds (process ...) and (system ...) functions */

 /* DIR_FUNCTION adds (current-directory ...) function */

 /* GETENV_FUNCTION adds (getenv ...) function */

 /* USE_TIMEZONE_VAR gets timezone offset from a timezone global.
    USE_TOD_FOR_TIMEZONE gets timezone offset via gettimeofday.
    USE_TIMEZONE_VAR_W_DLS is similar, but adds 1 hour when daylight 
     savings is in effect.
    USE_TIMEZONE_AND_ALTZONE_VAR is similar, but uses altzone when
     daylight savings is in effect.
    USE_TM_GMTOFF_FIELD gets timezone offset from the tm_gmtoff field
     of the tm struct. */

 /* USE_TZNAME_VAR gets the timezone name from a tzname global.
    USE_TM_ZONE_FIELD gets the timezone name from a tm_zone field
     of the tm struct. */
 

  /*******************/
 /*   Filesystem    */
/*******************/

 /* UNIX_FILE_SYSTEM indicates that filenames are as in Unix, with
    forward slash separators, ".." as the parent directory, "/" 
    as the root directory, and case-sensitivity */

 /* DOS_FILE_SYSTEM indicates that filenames are as in DOS, with 
    slash or backward slash separators, ".." as the parent directory, 
    "X:\", "X:/", "\", or "/" as a root directory (for some letter X),
    and case insensitivity */

 /* MAC_FILE_SYSTEM indicates that filenames are as on the Macintosh,
    with colon separators, "" as the parent directory, a volume name 
    (followed by a colon) as a root directory, and case insensitivity. */

 /* EXPAND_FILENAME_TILDE expands ~ in a filename with a user's home
     directory. */

 /* NO_STAT_PROC means that there is no stat() function. */

 /* NO_MKDIR means that there is no mkdir() function. */

 /* NO_READLINK means that there is no readlink() function. */

 /* USE_GETDISK uses getdisk() and setdisk() to implement the
     filesystem-root-list primitive under DOS. */

 /* NO_READDIR means that there is no opendir() and readdir() for
     implementing directory-list. */

 /* DIRENT_NO_NAMLEN specifies that dirent entries do not have a
     d_namlen field; this is used only when NO_READDIR is not
     specified. */
     
 /* MKDIR_NO_MODE_FLAG specifies that mkdir() takes only one argument,
     instead of a directory name and mode flags. */

 /* USE_C_SYSLOG uses the C syslog library for logging. */

 /* USE_WINDOWS_EVENT_LOG uses the Windows event log API for logging. */

 /* INIT_SYSLOG_LEVEL sets the initial level for filtering messages
    sent to syslog. It default to 0 (i.e., no events). */

  /***********************/
 /*       Ports         */
/***********************/

/* These are flags about the implementation of char-ready? for FILE*s
   None of these flags are required, but char-ready? may return
   spurious #ts if they are set up incorrectly. */

 /* HAS_STANDARD_IOB, HAS_GNU_IOB, HAS_CYGWIN_IOB, HAS_LINUX_IOB,
    HAS_BSD_IOB, and HAS_SCO_IOB are mutually exclusive; they describe
    how to read the FILE* structure to determine if there are
    available cached characters. */

 /* USE_FD_PORTS uses Unix-style open(), etc., for file ports. */

 /* FILES_HAVE_FDS means that a FILE* is always associated with a
    file desciptor, which can be select-ed to see if there are
    pending bytes. Don't use this unless one of the HAS_<X>_IOB
    flags is used. */

 /* USE_FLOCK_FOR_FILE_LOCKS means that flock() is available and works
    for file locking. */

 /* USE_FCNTL_AND_FORK_FOR_FILE_LOCKS means that fnctl() and fork()
    should be used to implement file locking. */

 /* CLOSE_ALL_FDS_AFTER_FORK means that all fds except 0, 1, and 2
    should be closed after performing a fork() for `process'
    and `system' calls. */

 /* USE_UNIX_SOCKETS_TCP means that the tcp- procedures can be implemented
    with the standard Unix socket functions. */

 /* USE_WINSOCK_TCP means that the tcp- procedures can be implemented
    with the Winsock toolbox. */

 /* USE_MAC_TCP means that the tcp- procedures can be implemented
    with the Mac TCP toolbox. */

 /* WINDOWS_FILE_HANDLES implements file access through the Windows
    API (CreateFile(), ReadFile(), etc.) */

 /* USE_FCNTL_O_NONBLOCK uses O_NONBLOCK instead of FNDELAY for
    fcntl on Unix TCP sockets. (Posix systems need this flag). */

 /* SOME_FDS_ARE_NOT_SELECTABLE indicates that select() doesn't work
    for reading on all kinds of file descriptors. Such FDs must never
    be able to go from no-char-ready to char-ready while Racket is
    sleeping. */

 /* NEED_RESET_STDOUT_BLOCKING enures that file descriptors 1 and 2
    are reset to blocking mode before exiting. */

 /* USE_TRANSITIONAL_64_FILE_OPS uses fseeko64, lseek64, stat64,
    etc. for file operations involving sizes (that can require
    64-bit arithmetic). */

 /* USE_ULIMIT uses ulimit instead of getdtablesize (Unix). */

 /* USE_DYNAMIC_FDSET_SIZE allocates fd_set records based on the
    current fd limit instead of relying on the compile-time size
    of fd_set. */

 /* UNIX_LIMIT_FDSET_SIZE insures that the fd limit at start-up is
    no greater than FD_SETSIZE */

 /* CANT_SET_SOCKET_BUFSIZE turns off setting the buffer size for
    Unix TCP sockets. */

 /* USE_NULL_TO_DISCONNECT_UDP calls connect() with NULL instead of
    an AF_UNSPEC address to disconnect a UDP socket. */

 /* UDP_DISCONNECT_EADRNOTAVAIL_OK means that a disconnecting call
    to connect() might return EADDRNOTAVAIL instead of 
    EAFNOSUPPORT. */

 /* MZ_BINARY is combinaed with other flags in all calls to open();
    it can be defined to O_BINARY in Cygwin, for example. */

 /* MZ_TCP_LISTEN_IPV6_ONLY_SOCKOPT uses IPV6_V6ONLY for IPv6
    listeners when the same listener has an IPv4 address, which means
    that the IpV6 listener accepts only IPv6 connections. This is used
    with Linux, for example, because a port cannot have both an IPv4
    and IPv6 listener if the IPv6 one doesn't use IPV6_V6ONLY. (The
    two listeners might be for different interfaces, in which case
    IPV6_V6ONLY is not necessary, but we must err on the side of being
    too restrictive. If IPV6_V6ONLY is not #defined or if setting the
    option doesn't work, then the IPv6 addresses are silently ignored
    when creating the listener (but only where there is at least once
    IPv4 address). */


  /***********************/
 /* Threads & Signals  */
/***********************/

/* These are flags about the implementation of system, process, etc. */

 /* UNIX_PROCESSES implements the process functions for Unix; uses
    sigset() to install the signal handler. */

 /* WINDOWS_PROCESSES implements the process functions for Windows. */

 /* USE_ITIMER uses setitimer() to implement thread pre-emption (for
    Racket-implemented threads). Define MZ_THREAD_QUANTUM_USEC to
    set the base time in usec allocated to each thread. */

 /* USE_WIN32_THREAD_TIMER uses a background Windows thread to implement
    tread pre-emption. */

 /* USE_PTHREAD_THREAD_TIMER uses a background pthread to implement
    tread pre-emption. */

 /* SIGSET_IS_SIGNAL uses signal() in place of sigset() for Unix. This 
    flag is often paired with SIGSET_NEEDS_REINSTALL for traditional
    Unix systems. */

 /* SIGSET_NEEDS_REINSTALL reinstalls a signal handler when it
    is called to handle a signal. The expected semantics of sigset()
    (when this flags is not defined) is that a signal handler is NOT
    reset to SIG_DFL after a handler is called to handle a signal. */

 /* DONT_IGNORE_FPE_SIGNAL stops Racket from ignoring floating-point 
    exception signals. */

 /* DONT_IGNORE_PIPE_SIGNAL stops Racket from ignoring SIGPIPE
    signals. */

 /* USE_CREATE_PIPE uses CreatePipe() instead of _pipe() for Windows. */

 /* SIGCHILD_DOESNT_INTERRUPT_SELECT indicates that the SIGCHILD
    signal, sent when a child OS process dies, does not interrupt
    select(). This flag is needed for Cygwin B20. */

 /* USE_UNDERSCORE_SETJMP uses _setjmp() instead of setjmp() to avoid
    sigmal-mask work. */

 /* FLUSH_SPARC_REGISTER_WINDOWS uses an assembly instruction for
    flushing the Sparc register windows before copying the stack. */

  /**********************/
 /* Inexact Arithmetic */
/**********************/

 /* USE_SINGLE_FLOATS turns on support for single-precision
    floating point numbers. Otherwise, floating point numbers
    are always represented in double-precision. */

 /* USE_SINGLE_FLOATS_AS_DEFAULT, when used with
    USE_SINGLE_FLOATS, causes exact->inexact coercions to
    use single-precision numbers as the result rather
    than double-precision numbers. */

 /* USE_INFINITY_FUNC uses infinity() to get the infinity
     floating-point constant instead of using HUGE_VAL. */

 /* USE_DIVIDE_MAKE_INFINITY creates +inf.0 by dvividing by zero
    instead of using HUGE_VAL. */

 /* USE_IEEE_FP_PREDS uses isinf() and isnan() to implement tests for
    infinity and not-a-number. */

 /* USE_OSF_FP_PREDS uses fp-class() and isnan() to implement tests for
    infinity and not-a-number. */

 /* USE_SCO_IEEE_FP_PREDS uses fpclass() and isnan() to implement tests for
    infinity and not-a-number. */

 /* USE_CARBON_FP_PREDS uses __isnand() and __isfinited() to implement tests
    for infinity and not-a-number. */

 /* USE_MSVC_FP_PREDS uses _fpclass() and _isnan() to implement tests
    for infinity and not-a-number. */

 /* DEFEAT_FP_COMP_OPTIMIZATION avoids a compiler optimization that
    converts (a == a) to TRUE, even if `a' is floating-point. Used
    only when USE_[SCO_]IEEE_FP_PREDS is not defined. */

 /* ASM_DBLPREC_CONTROL_87 uses inline assembly to set Intel '387
    floating-point operations to double-precision instead of
    extended-precision arithmetic. */

 /* IGNORE_BY_BORLAND_CONTROL_87 turns off floating-point error for
    Intel '387 with Borlad-style _control87. DONT_IGNORE_PIPE_SIGNAL
    can be on or off. */

 /* IGNORE_BY_MS_CONTROL_87 turns off floating-point error for Intel
    '387 with Microsoft-style _control87. DONT_IGNORE_PIPE_SIGNAL can
    be on or off. */

 /* LINUX_CONTROL_387 controls the floating-point processor under i386
    Linux using __setfpucw(). libc 6.1 doesn't export __setfpucw() and
    it doesn't matter; for Linux 2.0 and up, the default FP behavior
    is the one we want. This flag might be needed for older versions
    of Linux. */

 /* FREEBSD_CONTROL_387 controls the floating-point processor under i386
    FreeBSD. As for Linux, this does not appear necessary anymore. */

 /* APLHA_CONTROL_FP controls the floating-point processor for Alpha
    OSF1 */

 /* NAN_EQUALS_ANYTHING indicates that the compiler is broken and
    equality comparisons with +nan.0 always return #t. Currently
    used for MSVC++ */
    
 /* ZERO_MINUS_ZERO_IS_POS_ZERO indicates that something (compiler?
    machine? fp flags?) is broken so that 0.0 - 0.0 = 0.0 instead of
    -0.0. This flag doesn't fix Racket completely, since (- 0.0) is
    still 0.0, but at least it lets Racket read and print 0.0 and
    -0.0 accurately. Currently used for HP/UX. */

 /* NAN_LT_COMPARISON_WRONG indicates that +nan.0 is not handled correctly
    by < or <=. Probably the compiler implements < as !>. */

 /* USE_EXPLICT_FP_FORM_CHECK circumvents bugs in strtod() under Linux,
    SunOS/Solaris, and HP/UX by explicit pre-checking the form of the 
    number and looking for values that are obviously +inf.0 or -inf.0 */

 /* POW_HANDLES_INF_CORRECTLY indicates that thw pow() library procedure
    handles +/-inf.0 correctly. Otherwise, code in inserted to specifically
    check for infinite arguments. */
    
 /* ATAN2_DOESNT_WORK_WITH_INFINITIES indicates that atan2(+/-inf, +/-inf)
    is not the same as atan2(1, 1). */ 
    
 /* ATAN2_DOESNT_WORK_WITH_NAN indicates that atan2(+nan.0, _) and
    atan2(_, +nan.0) don't produce +nan.0. */ 
    
 /* SQRT_NAN_IS_WRONG indicates that (sqrt +nan.0) must be forced to +nan.0
    (i.e., the C library function is bad). */
    
 /* COMPUTE_NEG_INEXACT_TO_EXACT_AS_POS computes inexact->exact of some
    negative inexact number x by computing the result for -x and negating
    it. Use this if (inexact->exact -0.1) is wrong. */

 /* TRIG_ZERO_NEEDS_SIGN_CHECK defines versions of tan, sin, atan, and
    asin that preserve the sign of a zero argument. */

 /* FMOD_CAN_RETURN_NEG_ZERO is fmod() on positive numbers can produce
    a negative zero. */

 /* FMOD_CAN_RETURN_POS_ZERO is fmod() on -0.0 can produce 0.0. */

 /* LOG_ZERO_ISNT_NEG_INF defines a version of log that checks for an
    inexact zero argument and return negative infinity. */

 /* NEED_TO_DEFINE_MATHERR defines _matherr to quiet warnings from the
    math library. */

 /* SIN_COS_NEED_DEOPTIMIZE disables optimization for calls to sin()
    and cos() (for MSVC) */

/******************************/
 /* Byte Order and long long */
/****************************/

 /* INT64_AS_LONG_LONG indicates that long long is not supported, but
    _int64 is */

 /* NO_LONG_LONG_TYPE indicates that long long is not supported */

  /***********************/
 /* Stack Maniuplations */
/***********************/

 /* DO_STACK_CHECK checks for stack overflow during execution.
     Requires either UNIX_FIND_STACK_BOUNDS, USE_STACKAVAIL,
     MACOS_FIND_STACK_BOUNDS, or ASSUME_FIXED_STACK_SIZE. */

 /* UNIX_FIND_STACK_BOUNDS figures out the maximum stack position
     on Unix systems, using getrlimit() and the GC_find_stack_base()
     defined in the conservative garbage collector. But no more
     than UNIX_STACK_MAXIMUM bytes, if defined, will be used.
    USE_STACKAVIL uses stackavail() function for checking stack
     overflow; works with Borland C++, maybe other compilers.
    WINDOWS_FIND_STACK_BOUNDS figures out the maximum stack position
     under Windows (uses GC_find_stack_base())
    MACOS_FIND_STACK_BOUNDS figures out the stack limit on the Mac.
    LINUX_FIND_STACK_BASE figures out the stack base under Linux
     by reading from /proc/self/maps and looking for "[stack]"
     line.
    ASSUME_FIXED_STACK_SIZE assumes that the main stack size is
     always FIXED_STACK_SIZE.
    Use only one of these if DO_STACK_CHECK is used, or none otherwise. */

 /* FIXED_STACK_SIZE <X> sets the stack size to <X> when the
     ASSUME_FIXED_STACK_SIZE stack-checking mode is on. */

 /* STACK_SAFETY_MARGIN <X> sets the number of bytes that should be
     available on the stack for "safety" to <X>. Used only if
     DO_STACK_CHECK is used. STACK_SAFETY_MARGIN defaults to 50000. */

 /* UNIX_LIMIT_STACK <X> limits stack usage to <X> bytes. This may
     be necessary to avoid GC-setup traversal over too much memory
     (with GC flag HEURISTIC2?). */

 /* OSKIT_FIXED_STACK_BOUNDS uses base_stack_start to get the hottest
     stack location */

  /***********************/
 /*   Dynamic Loading   */
/***********************/

 /* UNIX_DYNAMIC_LOAD implements dynamic extensions under Unix
     using dlopen(); you may have to add the -ldl flag in the LIBS 
     Makefile variable. The library doesn't exist under Linux without 
     ELF, so it won't work. If you get linker errors about dlopen(), etc., 
     this flag and the -ldl linker flag are the things to adjust.
    SHL_DYNAMIC_LOAD implement HP/UX dynamic loading.
    WINDOWS_DYNAMIC_LOAD implements dynamic extensions under Windows
     (Thanks to Patrick Barta).
    CODEFRAGMENT_DYNAMIC_LOAD implements dynamic extensions with
     MacOS's Code Fragment Custodian (thanks to William Ng).
    Use only one or none of these. */

 /* UNDERSCORE_DYNLOAD_SYMBOL_PREFIX with UNIX_DYNAMIC_LOAD means that
    an extra underscore ("_") must be placed in front of the name passed 
    to dlopen(). */

 /* LINK_EXTENSIONS_BY_TABLE specifies that the Racket functions
    used by an extension must be manually linked via a table of
    function pointers. Windows dynamic linking uses this method. */

 /* MZSCHEME_IS_CODEFRAGMENT exploits improved CFM linking when
    Racket is itself a shared library instead of embedded in
    an application */

  /***********************/
 /*         JIT         */
/***********************/

 /* MZ_USE_JIT_I386 enables the JIT for x86 */

 /* MZ_USE_JIT_X86_64 enables the JIT for x86_64 */

 /* MZ_USE_JIT_PPC enables the JIT for PowerPC */

 /* MZ_JIT_USE_MPROTECT uses mprotect on x86 platforms to make code
    pages executable */

 /* MZ_JIT_USE_WINDOWS_VIRTUAL_ALLOC uses VirtualAlloc to make
    code pages executable. */

  /***********************/
 /*     Heap Images     */
/***********************/

 /* UNIX_IMAGE_DUMPS turns on image save and restore for Unix systems. 
     This will only work if the final application is statically linked. 
     (As an exception, the dynamic-linking library itself can be 
     dynamically linked. This works because loading an extension in 
     Racket automatically turns off image saving.) */

  /*****************************/
 /*   Macintosh Standalone    */
/*****************************/

 /* MACINTOSH_EVENTS enables specific support for Mac Classic */
 
 /* MAC_MZ_GUI_ENABLED activates the windowed I/O code (use under classic) 
     (should maybe use MACINTOSH_SIOUX instead?) */

 /* MAC_CLASSIC_PROCESS_CONTROL swaps the UNIX process commands for the 
    mac family (use under classic) */

 /* OS_X enables specific support for Mac OS X, e.g. the location of the
    prefs directory */
 
 /* MACINTOSH_GIVE_TIME lets background processes run when checking for
     a user break */

 /* MACINTOSH_SIOUX interfaces with Metrowerks's SIOUX library */

 /* MACINTOSH_SET_STACK sets the stack to be 1/4 of the heap; this should
     be used for 68k machines, where the stack is not user-configurable */

  /***********************/
 /*    Miscellaneous    */
/***********************/

 /* USE_MAP_ANON indicates that mmap should use BSD's MAP_ANON flag
    rather than trying to open /dev/zero */

 /* REGISTER_POOR_MACHINE guides a hand optimization that seems to
    be work best one way for Sparc machines, and better the other
    way for x86 machines. */

 /* USE_LONG_LONG_FOR_BIGDIG indicates that `long long' is available
    and 64 bits wide. (Don't use when `long' is 64 bits wide). */

 /* MACOS_UNICODE_SUPPORT and WINDOWS_UNICODE_SUPPORT indicate that
    platform-native functions should be used for string comparisons
    in the default locale. */

 /* USE_ICONV_DLL loads iconv.dll lazily for string conversion; no
    headers necessary. */

 /* NO_MBTOWC_FUNCTIONS indicates that locale-to-wchar conversion
    functions are not available. */

 /* NO_INLINE_KEYWORD indicates that the C compiler doesn't recognize
    C's `inline' keyword. */

 /* NO_USER_BREAK_HANDLER turns off handling of INT signal in main.c */

 /* DIR_INCLUDE if there's a <dir.h> file (mainly for Windows). */

 /* DIRECT_INCLUDE if there's a <direct.h> file (mainly for Windows). */

 /* IO_INCLUDE if there's a <io.h> file (mainly for Windows). */

 /* UNISTD_INCLUDE if there's a <unistd.h> file (mainly for Unix). */

 /* SELECT_INCLUDE if there's a <sys/select.h> file (mainly for Unix) 
     to be used with FILES_HAVE_FDS. */

 /* BSTRING_INCLUDE if there's a <bstring.h> file (mainly for Unix) 
     to be used with FILES_HAVE_FDS. */

 /* NO_SYS_INCLUDE_SUBDIR if include files should all be <XXX.h>; no
     includes of the form <sys/XXX.h>. Mainly used for <sys/stat.h>
     for MacOS. */

 /* USE_FCHDIR uses fchdir() to improve thread context switches when
    a small number of threads are active. */

 /* USE_GETRUSAGE uses getrusage() to for timing info; otherwise clock()
    is used. */

 /* USE_SYSCALL_GETRUSAGE uses syscall() to implement getrusage() for
    timing info. Used with USE_GETRUSAGE. */

 /* NO_SLEEP means that there is no sleep() function. Used only in
    standalone Racket. */

 /* NO_USLEEP means that there is no usleep() function. Used only in 
    standalone Racket. Used only if NO_SLEEP is undefined. */

 /* NO_STRERROR_AVAILABLE means that strerror() is not available. */

 /* USE_ON_EXIT_FOR_ATEXIT means that a SunOS4-style on_exit()
    is available instead of atexit(). */

 /* NO_NEED_FOR_BEGINTHREAD indicates that the C library used for
    Windows is always thread-ready and there's no need use the
    _beginthreadex() function instead of CreateThread(). */

 /* WIN32S_HACK uses a special hack to implement threads under Win32s
    with some compilers. Obsolete. */

#endif  /* FLAGS_ALREADY_SET */

/****** (END CONFIGURATION FLAG DESCRPTIONS AND DEFAULTS) *******/

#endif  /* FLAGS_ALREADY_SET */

void _Perror(const char * File, int Line);
#define Perror() _Perror(__FILE__, __LINE__)

#ifdef DEBUG_ENABLED

#define rdtscll(val)     __asm__ __volatile__("rdtsc" : "=A" (val))

static inline unsigned get_cycles (void)
{
	unsigned long long ret;

	rdtscll(ret);
	return ret;
}

#define DEBUG(format,args...) \
	fprintf (stderr, PACKAGE ":%5d:%08x %s:%s:%d: " format "\n", getpid(), get_cycles(), __FILE__, __FUNCTION__, __LINE__ , ## args)
#define DEBUGP(format,args...) \
	fprintf (stderr, PACKAGE ":%5d:%08x %s:%s:%d: " format "\n", getpid(), get_cycles(), __FILE__, __PRETTY_FUNCTION__, __LINE__ , ## args)
#else
    #define DEBUG(format,args...)
    #define DEBUGP(format,args...)
#endif

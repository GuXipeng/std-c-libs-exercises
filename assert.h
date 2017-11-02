/* assert-h standard header */
#undef assert /* remove exiting assert macro definition */

#ifdef NDEBUG
# define assert(e) ((void)0)
#else
 void _Assert(char *);
# define _STR(x) _VAL(x)
# define _VAL(x) #x
# define assert(e) ((e) ? (void)0 : _Assert(__FILE__":"_STR(__LINE__)" "#e))
#endif

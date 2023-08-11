/*
 * Definitions etc. for regexp(3) routines.
 *
 * Caveat:  this is V8 regexp(3) [actually, a reimplementation thereof],
 * not the System V one.
 */
#ifndef REGEXP_H
#define REGEXP_H

#define CHARBITS 0377
#define NSUBEXP  10
typedef struct regexp {
	char *startp[NSUBEXP];
	char *endp[NSUBEXP];
	char regstart;		/* Internal use only. */
	char reganch;		/* Internal use only. */
	char *regmust;		/* Internal use only. */
	int regmlen;		/* Internal use only. */
	char program[1];	/* Unwarranted chumminess with compiler. */
} regexp;

extern regexp *regcomp (char *_exp);
extern int regexec (regexp *_prog, char *_string, int _bolflag);
extern void regsub (regexp *_prog, char *_source, char *_dest);
extern void regerror (char const *_message);
extern void regdump (regexp *r);

#endif

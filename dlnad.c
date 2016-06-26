/*
 * Copyright (c) 2016 Claes Persson <c@cp.se>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "dlnad.h"

void			par_shutdown(struct dlnad *);
__dead void		usage(void);

struct dlnad	*dlnad_env;

int
main(int argc, char *argv[])
{
	int c;
	uint32_t opts = 0;
	struct dlnad *env;
	const char *conffile = DLNAD_CONF_FILE;

	while ((c = getopt(argc, argv, "Df:v")) != -1) {
		switch(c) {
		case 'D':
			opts |= DLNAD_OPT_DONTDAEMONIZE;
			break;
		case 'f':
			conffile = optarg;
			break;
		case 'v':
			opts |= DLNAD_OPT_VERBOSE;
			break;
		default:
			usage();
		}
	}

	argc -= optind;
	if (argc > 0)
		usage();

	if ((env = calloc(1, sizeof(*env))) == NULL)
		exit(1);

	dlnad_env = env;

	env->conffile = conffile;
	env->flags = opts;

	if (parse_config(env->conffile, env) == -1)
		exit(1);

	par_shutdown(env);

	return (0);
}

void
par_shutdown(struct dlnad *env)
{
	free(env);
	exit(0);
}

__dead void
usage(void)
{
	extern char *__progname;

	fprintf(stderr, "usage: %s\n", __progname);
	exit(1);
}

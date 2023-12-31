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

#ifndef _DLNAD_H
#define _DLNAD_H

#include <sys/types.h>

#define DLNAD_CONF_FILE				"/usr/local/etc/dlnad.conf"

#define DLNAD_OPT_DONTDAEMONIZE		0x01
#define DLNAD_OPT_VERBOSE			0x04

struct dlnad {
	uint32_t		flags;
	const char		*conffile;
};

int		parse_config(const char *, struct dlnad *);

#endif /* _DLNAD_H */

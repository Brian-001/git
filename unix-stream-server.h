#ifndef UNIX_STREAM_SERVER_H
#define UNIX_STREAM_SERVER_H

#include "unix-socket.h"

struct unix_stream_server_socket {
	char *path_socket;
	struct stat st_socket;
	int fd_socket;
};

/*
 * Create a Unix Domain Socket at the given path under the protection
 * of a '.lock' lockfile.
 */
struct unix_stream_server_socket *unix_stream_server__listen_with_lock(
	const char *path,
	const struct unix_stream_listen_opts *opts);

/*
 * Close and delete the socket.
 */
void unix_stream_server__free(
	struct unix_stream_server_socket *server_socket);

/*
 * Return 1 if the inode of the pathname to our socket changes.
 */
int unix_stream_server__was_stolen(
	struct unix_stream_server_socket *server_socket);

#endif /* UNIX_STREAM_SERVER_H */

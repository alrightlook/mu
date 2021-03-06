#ifndef SERVER_PROTOCOL_H
#define SERVER_PROTOCOL_H

#include <stdbool.h>
#include "uv.h"
#include "const.h"

void server_on_connect(uv_stream_t *server, int status);
void server_on_read(uv_stream_t *stream, ssize_t length, const uv_buf_t *buf);
void server_on_tick(uv_timer_t *timer);
void server_on_client_close(uv_handle_t *handle);
bool server_listen(int port);

void server_close_connection(uv_tcp_t *connection);
void server_disconnect_player(size_t index);

bool find_entity_by_connection(uv_tcp_t *connection, size_t *index);

#endif

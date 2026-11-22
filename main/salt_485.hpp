#ifndef SALT_485_HPP
#define SALT_485_HPP

#ifdef __cplusplus
extern "C" {
#endif

// callback type
typedef void (*salt_485_recv_t)(const char * m, int len);

/**
 * main initializer
 * @param cb callback for bytes received
 */
void salt_485_main(salt_485_recv_t cb);

/**
 * send out a message
 */
#ifdef __cplusplus
void salt_485_send(const char *msg, int len = -1);
#else
void salt_485_send(const char *msg, int len);
#endif


#ifdef __cplusplus
}
#endif

#endif

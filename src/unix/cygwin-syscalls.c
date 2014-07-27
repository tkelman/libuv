/* Copyright Joyent, Inc. and other Node contributors. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */

#include "linux-syscalls.h"
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>


int uv__accept4(int fd, struct sockaddr* addr, socklen_t* addrlen, int flags) {
  return accept4(fd, addr, addrlen, flags);
}


int uv__eventfd(unsigned int count) {
#if defined(__NR_eventfd)
  return syscall(__NR_eventfd, count);
#else
  return errno = ENOSYS, -1;
#endif
}


int uv__eventfd2(unsigned int count, int flags) {
#if defined(__NR_eventfd2)
  return syscall(__NR_eventfd2, count, flags);
#else
  return errno = ENOSYS, -1;
#endif
}


int uv__epoll_create(int size) {
#if defined(__NR_epoll_create)
  return syscall(__NR_epoll_create, size);
#else
  return errno = ENOSYS, -1;
#endif
}


int uv__epoll_create1(int flags) {
#if defined(__NR_epoll_create1)
  return syscall(__NR_epoll_create1, flags);
#else
  return errno = ENOSYS, -1;
#endif
}


int uv__epoll_ctl(int epfd, int op, int fd, struct uv__epoll_event* events) {
#if defined(__NR_epoll_ctl)
  return syscall(__NR_epoll_ctl, epfd, op, fd, events);
#else
  return errno = ENOSYS, -1;
#endif
}


int uv__epoll_wait(int epfd,
                   struct uv__epoll_event* events,
                   int nevents,
                   int timeout) {
#if defined(__NR_epoll_wait)
  return syscall(__NR_epoll_wait, epfd, events, nevents, timeout);
#else
  return errno = ENOSYS, -1;
#endif
}


int uv__epoll_pwait(int epfd,
                    struct uv__epoll_event* events,
                    int nevents,
                    int timeout,
                    const sigset_t* sigmask) {
#if defined(__NR_epoll_pwait)
  return syscall(__NR_epoll_pwait,
                 epfd,
                 events,
                 nevents,
                 timeout,
                 sigmask,
                 sizeof(*sigmask));
#else
  return errno = ENOSYS, -1;
#endif
}


int uv__inotify_init(void) {
#if defined(__NR_inotify_init)
  return syscall(__NR_inotify_init);
#else
  return errno = ENOSYS, -1;
#endif
}


int uv__inotify_init1(int flags) {
#if defined(__NR_inotify_init1)
  return syscall(__NR_inotify_init1, flags);
#else
  return errno = ENOSYS, -1;
#endif
}


int uv__inotify_add_watch(int fd, const char* path, uint32_t mask) {
#if defined(__NR_inotify_add_watch)
  return syscall(__NR_inotify_add_watch, fd, path, mask);
#else
  return errno = ENOSYS, -1;
#endif
}


int uv__inotify_rm_watch(int fd, int32_t wd) {
#if defined(__NR_inotify_rm_watch)
  return syscall(__NR_inotify_rm_watch, fd, wd);
#else
  return errno = ENOSYS, -1;
#endif
}


int uv__pipe2(int pipefd[2], int flags) {
  return pipe2(pipefd, flags);
}


int uv__sendmmsg(int fd,
                 struct uv__mmsghdr* mmsg,
                 unsigned int vlen,
                 unsigned int flags) {
#if defined(__NR_sendmmsg)
  return syscall(__NR_sendmmsg, fd, mmsg, vlen, flags);
#else
  return errno = ENOSYS, -1;
#endif
}


int uv__recvmmsg(int fd,
                 struct uv__mmsghdr* mmsg,
                 unsigned int vlen,
                 unsigned int flags,
                 struct timespec* timeout) {
#if defined(__NR_recvmmsg)
  return syscall(__NR_recvmmsg, fd, mmsg, vlen, flags, timeout);
#else
  return errno = ENOSYS, -1;
#endif
}


int uv__utimesat(int dirfd,
                 const char* path,
                 const struct timespec times[2],
                 int flags)
{
  return utimensat(dirfd, path, times, flags);
}


ssize_t uv__preadv(int fd, const struct iovec *iov, int iovcnt, off_t offset) {
#if defined(__NR_preadv)
  return syscall(__NR_preadv, fd, iov, iovcnt, offset);
#else
  return errno = ENOSYS, -1;
#endif
}


ssize_t uv__pwritev(int fd, const struct iovec *iov, int iovcnt, off_t offset) {
#if defined(__NR_pwritev)
  return syscall(__NR_pwritev, fd, iov, iovcnt, offset);
#else
  return errno = ENOSYS, -1;
#endif
}


int uv__dup3(int oldfd, int newfd, int flags) {
  return dup3(oldfd, newfd, flags);
}

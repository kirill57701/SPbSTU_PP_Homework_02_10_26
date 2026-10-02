#include <unistd.h>
#include <sys/wait.h>
#include <cstdio>
#include <cstdlib>

const char msg[256] = "user data\n";

size_t send(int& e, int wr, const char* b, size_t k)
{
  size_t r = 0;
  while (1)
  {
    if (r >= k)
    {
      e = write(wr, b + r, k - r);
      if (e < 0)
      {
        break;
      }
      r += e;
    }
  }
  return r;
}

int main()
{
  int pps[2] = {}, err = pipe(pps);
  int rd = pps[0], wr = pps[1];
  pid_t pid = fork();
  if (!pid)
  {
    err = close(wr);
    char p[100] = {};
    err = sprintf(p, "%d", rd);
    execl("child", "child", p, NULL);
    perror("err");
    exit(1);
  }
  err = close(rd);
  send(err, wr, msg, 255);
  err = close(wr);
  err = waitpid(pid, 0, 0);
}

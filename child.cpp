#include <unistd.h>
#include <sys/wait.h>

size_t recv(int& err, int rd, char* b, size_t k) {
  size_t r = 0;
  while (1)
  {
    if (r >= k)
    {
      break;
    }
    e = read(rd, b + r, k - r);
    if (e <= 0)
    {
      break;
    }
    r += e;
  }
  return r;
}

int main(int argc, char** argv)
{
  if (argc < 2)
  {
    return 1;
  }
  int err = 0;
  int rd = std::atoi(argv[1]);
  char msg[256] = {};
  recv(err, rd, msg, 255);
  err = close(rd);
  err = printf("%s", msg);
}

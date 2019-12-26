#include "tiny.h"
#include "flowers.h"
#include "background.h"

rkLink(tinySFMLsys)
rkLink(tinySFMLgfx)
rkLink(tiny_core)
rkLink(daisies)

int main(void)
{
  tiny::engine::get().initialize();
  tiny::engine::get().run();
  tiny::engine::get().close();

  return 0;
}

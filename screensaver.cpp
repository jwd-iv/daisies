#include "tiny.h"
#include "SFML\Graphics.hpp"
#include "SFML\OpenGL.hpp"
#include "screensaver.h"

int Width = 0;
int Height = 0;

void Win32ScreensaverWindow::initialize()
{
}

void Win32ScreensaverWindow::update(float dt)
{
}

void Win32ScreensaverWindow::close()
{
}

bool Win32ScreensaverWindow::is_active() const
{
  return true;
}

bool Win32ScreensaverWindow::show()
{
  return false;
}

bool Win32ScreensaverWindow::hide()
{
  return false;
}

unsigned Win32ScreensaverWindow::width() const
{
  return Width;
}

unsigned Win32ScreensaverWindow::height() const
{
  return Height;
}

bool Win32ScreensaverWindow::is_fullscreen() const
{
  return true;
}

void Win32ScreensaverWindow::render()
{
}

bool Win32ScreensaverWindow::set_size(unsigned w, unsigned h, bool fullscreen)
{
  return false;
}
